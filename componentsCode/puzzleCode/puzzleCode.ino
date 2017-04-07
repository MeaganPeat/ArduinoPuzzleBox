//SET THE PINS
const int joyStickXPin = A1;
const int joyStickYPin = A0;
const int joyStickButtonPin = 2;
//const int touchPin = 6;
const int resetBtn = 7;
const int tiltPin = 8;
const int trigPin = 9;
const int echoPin = 10;
const int lights[12] = {0, 1, 3, 4, 5, 11, 12, 13, 16, 17, 18, 19 };

//GLOBAL VARIABLES

bool gameOn = true;

//light on off checking and animation
int lightsOnOff[12] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0};
int timer = 30;

//distance
long duration;
int distance;

//JoyStick
int joyStickXPosition = 0;
int joyStickYPosition = 0;
int joyStickButtonState = 0;
//0 = center, 1 = left/up, 2 = right/down
int joyStickXLast = 0;
int joyStickYLast = 0;
int joyStickPushes[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int joyStickIndex = 0;
bool joyStickCodeCheck = false;

//tiltSensor
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
int switchCheck = 0;
long time = 0;         // the last time the output pin was toggled
long debounce = 100; // the debounce time, increase if the output flickers

//reset button
int btnReading;//the btn vars are for the reset button to deal with delay
int btnState = HIGH;
int btnPrevious = LOW;
long btnTime = 0;         // the last time the output pin was toggled
long btnDebounce = 200;   // the debounce time, increase if the output flickers


void setup() {
  //Sensor Stuff
  pinMode(trigPin, OUTPUT); // Signal Goes Out
  pinMode(echoPin, INPUT); // Signal Goes In
  pinMode(resetBtn, INPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);
  //activate pull-up resistor on the push-button pin
  pinMode(joyStickButtonPin, INPUT_PULLUP); 

  //Lights
  for(int i = 0; i<12; i++){
    pinMode(lights[i], OUTPUT);
  }

  //Serial.begin(9600);
}

void loop() {
  if(gameOn==true){
    lightManager();
    readJoystick();
    tiltCheck();
    checkWin();
//    reset();
    delay(100);
  } else {
    knightRider();
    joystickButtonReset();
  }
}


///////////////////////////////////////
/////////FUNCTIONS/////////////////////
///////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//////////WINNING////////////////
//_____________________________//
void checkWin(){
  int check = 0;
  for(int i = 0; i<12; i++){
    if(lightsOnOff[i] == 1){
      check ++;
    } else {
      check = 0;
    }

    if(check == 12){
      for(int i = 0; i<12; i++){
        delay(timer);
        lightsOnOff[i] = 0;
        lightManager();
      }
      delay(timer);
      gameOn = false;
      
    }
  } 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//////////RESET BUTTON///////////
//_____________________________//
void reset(){
  btnReading = digitalRead(resetBtn);

  if (btnReading == HIGH && btnPrevious == LOW && millis() - btnTime > btnDebounce) {
    if (btnState == HIGH){
      btnState = LOW;
      restartValues();
    }else{
      btnState = HIGH;
      restartValues();
    }
    btnTime = millis();    
  }
  btnPrevious = btnReading; 
}//end of reset

void restartValues(){//put all starting values here for reset
    //Serial.println("The reset button has been hit");
    for(int i=0; i<12; i++){
      lightsOnOff[i] = 0;
    }
    long rand = random(3, 12);
    lightsOnOff[rand]=1;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
////////DISTANCE SENSOR//////////
//_____________________________//
void echo(){
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
      if(distance>150){
        farLight();
      //Serial.print("far");
    } else {
      closeLight();
      //Serial.print("Close: ");
    }
}//end of echo pin/distance sensor


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
////////////JOYSTICK/////////////
//_____________________________//


    void joystickButtonReset(){
      joyStickButtonState = digitalRead(joyStickButtonPin);
      if(joyStickButtonState == 0){
         restartValues();
         joyStickIndex = 0;
         joyStickCodeCheck = false;
         gameOn = true;
      }
    }
    
    void readJoystick(){//get directions from JoyStick
      //read the pins
      joyStickXPosition = analogRead(joyStickXPin);
      joyStickYPosition = analogRead(joyStickYPin);
      joyStickButtonState = digitalRead(joyStickButtonPin);
      //check if it is away from center
      if(joyStickXPosition >= 700){
        if(joyStickXLast != 1){
          joyStickXLast = 1;
          moveUp();
          //Serial.println("up ");
          if(joyStickIndex<8){
           joyStickPushes[joyStickIndex] = 1;
           joyStickIndex ++;  
          }
        } 
      } else if (joyStickXPosition <= 100){
        if(joyStickXLast != 2){
          joyStickXLast = 2;
          moveDown();
          //Serial.println("down ");
          if(joyStickIndex<8){
           joyStickPushes[joyStickIndex] = 2;
           joyStickIndex ++;  
          }
        }
      }else{
        joyStickXLast = 0;
      }
      if(joyStickYPosition >= 700){
        if(joyStickYLast != 1){
          joyStickYLast = 1;
          moveLeft();
          //Serial.println("left");
          if(joyStickIndex<8){
           joyStickPushes[joyStickIndex] = 3;
           joyStickIndex ++;  
          } 
        } 
      } else if (joyStickYPosition <= 100){
        if(joyStickYLast != 2){
          joyStickYLast = 2;
          moveRight();
          //Serial.println("right");
          if(joyStickIndex<8){
           joyStickPushes[joyStickIndex] = 4;
           joyStickIndex ++;  
          }
        }
      }else{
        joyStickYLast = 0;
      }
    
      //reset counting if button is pressed
      if(joyStickButtonState == 0){
         echo();
         joyStickIndex = 0;
         joyStickCodeCheck = false;
      }
    
      //check for konami code (for reasons)
      if(joyStickCodeCheck == false &&
         joyStickPushes[0]==1 && 
         joyStickPushes[1]==1 &&
         joyStickPushes[2]==2 &&
         joyStickPushes[3]==2 &&
         joyStickPushes[4]==3 &&
         joyStickPushes[5]==4 &&
         joyStickPushes[6]==3 &&
         joyStickPushes[7]==4){
          konamiCode();
          joyStickPushes[7]=8;
          joyStickCodeCheck = true;
         }
      
    }//end of read Joystick
    
    void konamiCode(){
      //Serial.print("Konami CODE!!! w00t!!");
      gameOn=false;
    }  
    
    //get numerical values from JoyStick
    void joyStickValues(){
      joyStickXPosition = analogRead(joyStickXPin);
      joyStickYPosition = analogRead(joyStickYPin);
      joyStickButtonState = digitalRead(joyStickButtonPin);
//      Serial.print("X: ");
//      Serial.print(joyStickXPosition);
//      Serial.print(" | Y: ");
//      Serial.print(joyStickYPosition);
//      Serial.print(" | Button: ");
//      Serial.println(joyStickButtonState);
    }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
/////////////TILT////////////////
//_____________________________//
    void tiltCheck(){
      int switchstate;
      reading = digitalRead(tiltPin);
      // If the switch changed, due to bounce or pressing...
      if (reading != previous) {
        // reset the debouncing timer
        time = millis();
      }
      if ((millis() - time) > debounce) {
         switchstate = reading;
        if (switchstate == HIGH){
          if(switchCheck!=1){
            invertLights();
//            Serial.println("tilted!");
            switchCheck = 1;  
          } 
        } else if(switchCheck == 1){
          invertLights();
//          Serial.println("Level!");
          switchCheck = 0;
        }  
      }
      previous = reading;
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//////////LIGHTS/////////////////
//_____________________________//
    //Light Manager//
    void lightManager(){
      for(int i=0; i<12; i++){
        if(lightsOnOff[i] == 0){
          digitalWrite(lights[i], LOW);
        } else{
          digitalWrite(lights[i], HIGH);
        }
      }
    }
    
    //Light On Off Functions//
    void invertLights(){
      for(int i=0; i<12; i++){
        if(lightsOnOff[i] == 0){
          digitalWrite(lights[i], HIGH);
          lightsOnOff[i] = 1;
        } else {
        digitalWrite(lights[i], LOW);
        lightsOnOff[i] = 0;
        }
      }
      lightManager();
    }
    
    void moveRight(){
      int temp[4] = {lightsOnOff[1], lightsOnOff[4], lightsOnOff[7], lightsOnOff[10]};
      lightsOnOff[1] = temp[3];
      lightsOnOff[4] = temp[0];
      lightsOnOff[7] = temp[1];
      lightsOnOff[10] = temp[2];
      lightManager();
    }
    
    void moveLeft(){
      int temp[4] = {lightsOnOff[1], lightsOnOff[4], lightsOnOff[7], lightsOnOff[10]};
      lightsOnOff[1] = temp[1];
      lightsOnOff[4] = temp[2];
      lightsOnOff[7] = temp[3];
      lightsOnOff[10] = temp[0];
      lightManager();
    }
    
    void moveUp(){
      int temp[3] = {lightsOnOff[6], lightsOnOff[7], lightsOnOff[8]};
      lightsOnOff[6]=temp[1];
      lightsOnOff[7]=temp[2];
      lightsOnOff[8]=temp[0];
      lightManager(); 
    }
    
    void moveDown(){
      int temp[3] = {lightsOnOff[6], lightsOnOff[7], lightsOnOff[8]};
      lightsOnOff[6]=temp[2];
      lightsOnOff[7]=temp[0];
      lightsOnOff[8]=temp[1]; 
      lightManager();
    }
    
    void closeLight(){
      lightsOnOff[3]=1;
      lightsOnOff[8]=1;
      lightsOnOff[11]=1;
      lightManager();
    }
    
    void farLight(){
      lightsOnOff[5]=1;
      lightsOnOff[6]=1;
      lightsOnOff[9]=1;
      lightManager();
    }

    
    //LIGHT SHOWS//
    void knightRider(){
      for(int i=0; i<11; i++){
       digitalWrite(lights[i], HIGH);
       delay(timer);
       digitalWrite(lights[i + 1], HIGH);
       delay(timer);
       digitalWrite(lights[i], LOW);
       delay(timer*2);
      }
      for (int i = 11; i>0; i--){
        digitalWrite(lights[i], HIGH);
       delay(timer);
       digitalWrite(lights[i - 1], HIGH);
       delay(timer);
       digitalWrite(lights[i], LOW);
       delay(timer*2);
      }
    }
