const int tiltPin = 2;         // the number of the input pin

int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
int switchCheck = 0;
long time = 0;         // the last time the output pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers
     
void setup() {
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);   // turn on the built in pull-up resistor
  Serial.begin(9600);
}
     
void loop(){
 tiltCheck();
}

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
            //LEDstate = LOW;
            Serial.println("tilted!");
            switchCheck = 1;  
          } 
        } else if(switchCheck == 1){
          Serial.println("Level!");
          switchCheck = 0;
        }  
      }
      previous = reading;
}
