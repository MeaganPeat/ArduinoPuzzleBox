const int redLight = 16;

void setup() {
  // put your setup code here, to run once:
    pinMode(redLight, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLight, HIGH);
}
