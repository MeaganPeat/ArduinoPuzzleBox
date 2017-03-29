//sets pin numbers
const int trigPin = 9;
const int echoPin = 10;
const int redLight = 11;
const int greenLight = 12;
const int resetBtn = 7;

// defines variables
long duration;
int distance;
int distanceCheck;
bool greenOn;

//RESET BUTTON VARIABLES
int btnReading;//the btn vars are for the reset button to deal with delay
int btnState = HIGH;
int btnPrevious = LOW;
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


void setup() {
  pinMode(trigPin, OUTPUT); // Signal Goes Out
  pinMode(echoPin, INPUT); // Signal Goes In
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(resetBtn, INPUT);
  Serial.begin(9600); // Start Talking to the serial moniter
}

void loop() {
  
///////////////////FOR THE RESET BUTTON///////////////////////////
  btnReading = digitalRead(resetBtn);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (btnReading == HIGH && btnPrevious == LOW && millis() - time > debounce) {
    if (btnState == HIGH){
      btnState = LOW;
      Serial.println("A the reset button has been hit");
      greenOn = false;
      
    }else{
      btnState = HIGH;
      Serial.println("B the reset button has been hit");
      greenOn = false;
    }
    time = millis();    
  }
  
  btnPrevious = btnReading;

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
    if(distance>2 && distance < 10){
    distanceCheck = distance;
    Serial.print("You got the right distance: ");
    Serial.println(distance);
    digitalWrite(redLight, LOW);
//  digitalWrite(greenLight, HIGH);
//    delay(3000);//this does NOT work to see if the distance is constant. (Requires further research)
    if(distanceCheck>2 && distanceCheck < 10){
      Serial.println("at the end");
      greenOn = true;
    }
  } else {
    Serial.println("try adjusting your stuff");
    Serial.println(distance);
    digitalWrite(greenLight, LOW);
    digitalWrite(redLight, HIGH);
  }
  
  if(greenOn == true){
    digitalWrite(greenLight, HIGH);
  }
  
}

delay(500);
//delay(distance);
//Serial.print("Distance: ");
//Serial.println(distance);
//Serial.println("cm");
}
