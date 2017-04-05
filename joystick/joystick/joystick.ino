const int joyStickXPin = A1;
const int joyStickYPin = A0;
const int joyStickButtonPin = 2;

int joyStickXPosition = 0;
int joyStickYPosition = 0;
int joyStickButtonState = 0;

//0 = center, 1 = left/up, 2 = right/down
int joyStickXLast = 0;
int joyStickYLast = 0;
int joyStickPushes[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int joyStickIndex = 0;
bool joyStickCodeCheck = false;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(joyStickButtonPin, INPUT_PULLUP); 
}

void loop() {
  readJoystick();
//  joyStickValues();
  delay(100);
}

///////////////////////////////////////
/////////FUNCTIONS/////////////////////
///////////////////////////////////////


void readJoystick(){//get directions from JoyStick
  //read the pins
  joyStickXPosition = analogRead(joyStickXPin);
  joyStickYPosition = analogRead(joyStickYPin);
  joyStickButtonState = digitalRead(joyStickButtonPin);
  //check if it is away from center
  if(joyStickXPosition >= 700){
    if(joyStickXLast != 1){
      joyStickXLast = 1;
      Serial.println("up ");
      if(joyStickIndex<8){
       joyStickPushes[joyStickIndex] = 1;
       joyStickIndex ++;  
      }
    } 
  } else if (joyStickXPosition <= 100){
    if(joyStickXLast != 2){
      joyStickXLast = 2;
      Serial.println("down ");
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
      Serial.println("left");
      if(joyStickIndex<8){
       joyStickPushes[joyStickIndex] = 3;
       joyStickIndex ++;  
      } 
    } 
  } else if (joyStickYPosition <= 100){
    if(joyStickYLast != 2){
      joyStickYLast = 2;
      Serial.println("right");
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
//    for(int i=0; i<8; i++){
//        Serial.print(joyStickPushes[i]);
//        Serial.print(" ");
//      }
//      Serial.println(" ");
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
      Serial.print("Konami CODE!!! w00t!!");
      joyStickCodeCheck = true;
     }
  
}//end of read Joystick

//get numerical values from JoyStick
void joyStickValues(){
  joyStickXPosition = analogRead(joyStickXPin);
  joyStickYPosition = analogRead(joyStickYPin);
  joyStickButtonState = digitalRead(joyStickButtonPin);
  Serial.print("X: ");
  Serial.print(joyStickXPosition);
  Serial.print(" | Y: ");
  Serial.print(joyStickYPosition);
  Serial.print(" | Button: ");
  Serial.println(joyStickButtonState);
}

