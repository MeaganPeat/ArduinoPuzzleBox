//sets pin numbers
const int joyStickXPin = A1;
const int joyStickYPin = A0;
const int joyStickButtonPin = 2;
//const int touchPin = 6;
const int resetBtn = 7;
const int tiltPin = 8;
const int trigPin = 9;
const int echoPin = 10;
const int lights[12] = {0, 1, 3, 4, 5, 11, 12, 13, 16, 17, 18, 19 };

//LIGHT VARIABLES
//int lightsOnOff[12] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0};
int lightsOnOff[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int timer = 30;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<12; i++){
    pinMode(lights[i], OUTPUT);
  }
}

void loop() {
  lightManager();
  delay(1000);
  closeLight();
  delay(1000);
  farLight();
  delay(1000);
}


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
