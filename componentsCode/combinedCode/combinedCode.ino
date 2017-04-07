//sets pin numbers
const int joyStickXPin = A1;
const int joyStickYPin = A0;
const int joyStickButtonPin = 2;
const int resetBtn = 7;
const int trigPin = 9;
const int echoPin = 10;
const int redLight = 11;
const int greenLight = 12;

//global variables
//distance checker
long duration;
int distance;
int distanceCheck;

//lights
bool greenOn;

//reset button
int btnReading;//the btn vars are for the reset button to deal with delay
int btnState = HIGH;
int btnPrevious = LOW;
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

//JoyStick
int joyStickXPosition = 0;
int joyStickYPosition = 0;
int joyStickButtonState = 0;

//0 = center, 1 = left/up, 2 = right/down
int joyStickXLast = 0;
int joyStickYLast = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Signal Goes Out
  pinMode(echoPin, INPUT); // Signal Goes In
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(resetBtn, INPUT);
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);
  //activate pull-up resistor on the push-button pin
  pinMode(joyStickButtonPin, INPUT_PULLUP); 
  
  Serial.begin(9600); // Start Talking to the serial moniter

}

void loop() {
  // put your main code here, to run repeatedly:
  reset();
  echo();
  readJoystick();
  delay(100);
}

///////////////////////////////////////
/////////FUNCTIONS/////////////////////
///////////////////////////////////////

void reset(){
  ///////////////////FOR THE RESET BUTTON///////////////////////////
  btnReading = digitalRead(resetBtn);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (btnReading == HIGH && btnPrevious == LOW && millis() - time > debounce) {
    if (btnState == HIGH){
      btnState = LOW;
      restartValues();
    }else{
      btnState = HIGH;
      restartValues();
    }
    time = millis();    
  }

  btnPrevious = btnReading; 
}//end of reset

void restartValues(){//put all starting values here for reset
    Serial.println("The reset button has been hit");
    greenOn = false;
}

void echo(){
  /////////////////FOR THE ECHO PIN/////////////////////////////////
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  
  if(greenOn!=true){
      if(distance>45 && distance < 60){
      distanceCheck = distance;
      Serial.print("You got the right distance: ");
      Serial.println(distance);
      digitalWrite(redLight, LOW);
      Serial.println("at the end");
      greenOn = true;
    } else {
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println("cm");
      digitalWrite(greenLight, LOW);
      digitalWrite(redLight, HIGH);
    }
    if(greenOn == true){
      digitalWrite(greenLight, HIGH);
    }
  } 
}//end of echo pin/distance sensor

void readJoystick(){//get directions from JoyStick
  joyStickXPosition = analogRead(joyStickXPin);
  joyStickYPosition = analogRead(joyStickYPin);
  joyStickButtonState = digitalRead(joyStickButtonPin);
  if(joyStickXPosition >= 700){
    if(joyStickXLast != 1){
      joyStickXLast = 1;
      Serial.println("up "); 
    } 
  } else if (joyStickXPosition <= 100){
    if(joyStickXLast != 2){
      joyStickXLast = 2;
      Serial.println("down ");
    }
  }else{
    joyStickXLast = 0;
  }
  if(joyStickYPosition >= 700){
    if(joyStickYLast != 1){
      joyStickYLast = 1;
      Serial.println("left"); 
    } 
  } else if (joyStickYPosition <= 100){
    if(joyStickYLast != 2){
      joyStickYLast = 2;
      Serial.println("right");
    }
  }else{
    joyStickYLast = 0;
  }
}//end of readJoystick

//get numerical values from JoyStick
void joyStickValues(){
  Serial.print("X: ");
  Serial.print(joyStickXPosition);
  Serial.print(" | Y: ");
  Serial.print(joyStickYPosition);
  Serial.print(" | Button: ");
  Serial.println(joyStickButtonState);
}





