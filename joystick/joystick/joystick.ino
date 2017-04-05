const int joyStickXPin = A1;
const int joyStickYPin = A0;
const int joyStickButtonPin = 2;

int joyStickXPosition = 0;
int joyStickYPosition = 0;
int joyStickButtonState = 0;

//0 = center, 1 = left/up, 2 = right/down
int joyStickXLast = 0;
int joyStickYLast = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(joyStickButtonPin, INPUT_PULLUP); 
}

void loop() {
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

 



  
//  Serial.print("X: ");
//  Serial.print(joyStickXPosition);
//  Serial.print(" | Y: ");
//  Serial.print(joyStickYPosition);
//  Serial.print(" | Button: ");
//  Serial.println(joyStickButtonState);

  delay(100);
}
