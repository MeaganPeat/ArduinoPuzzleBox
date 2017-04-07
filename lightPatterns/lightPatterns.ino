//const int verticalSnake[12] = {0, 1, 3, 11, 5, 4, 12, 13, 16, 19, 18, 17};
//const int horizontalSnake[12] = {0, 4, 12, 17, 18, 13, 5, 1, 3, 11, 16, 19};
//const int coiledSnake[12] = {0, 4, 12, 17, 18, 19, 16, 11, 3, 1, 5, 13};
//const int horizontalAcross[12] = {0, 4, 12, 17, 1, 5, 13, 18, 3, 11, 16, 19};
//const int zigzag[12] = {0, 1, 4, 12, 5, 3, 11, 13, 17, 18, 16, 19};

const int lights[12] = {0, 1, 3, 4, 5, 11, 12, 13, 16, 17, 18, 19 };

const int lpm[6][12]{//Lights Path Matrix
  {0, 1, 3, 4, 5, 11, 12, 13, 16, 17, 18, 19}, //Vertical Stripes
  {0, 1, 3, 11, 5, 4, 12, 13, 16, 19, 18, 17}, //Vertical Snake
  {0, 4, 12, 17, 18, 13, 5, 1, 3, 11, 16, 19}, //Horizontal Snake
  {0, 4, 12, 17, 18, 19, 16, 11, 3, 1, 5, 13}, //Coiled Snake
  {0, 4, 12, 17, 1, 5, 13, 18, 3, 11, 16, 19}, //Horizontal Stripes
  {0, 1, 4, 12, 5, 3, 11, 13, 17, 18, 16, 19}  //ZigZag
};

int timer = 30;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void lightShow(){
  int show = random(1, 5);
  switch(show){
    case 1:march(random(0,6));
           break;
    case 2:negMarch(random(0,6));
            break;
    case 3:knightrider(random(0,6);
            break;
    case 4:alternate(random(0,6);
           break;
  }
}

//LIGHT PATTERNS//
void clearall(){
  for(int i = 0; i<12; i++){
    digitalWrite(lights[i], LOW);
  }
}

void lightall(){
  for(int i = 0; i<12; i++){
    digitalWrite(lights[i], HIGH);
  }
}

void march(int dir){
  for(int i = 0; i<12; i++){
    clearall();
    digitalWrite(lpm[dir][i], HIGH);
    delay(timer);
  }
  for(int i = 11; i>=0; i++){
    clearall();
    digitalWrite(lpm[dir][i], HIGH);
    delay(timer);
  }
}

void negMarch(int dir){
  for(int i = 0; i<12; i++){
    lightall();
    digitalWrite(lpm[dir][i], HIGH);
    delay(timer);
  }
  for(int i = 11; i>=0; i++){
    lightall();
    digitalWrite(lpm[dir][i], HIGH);
    delay(timer);
  }
}

void alternate(int dir){
  for(int i = 0; i<6; i++){
    clearall();
    for(int j = 1; j<12; j+=2){
      digitalWrite(lights[i], HIGH);
    }
    delay(timer);
    clearall();
    for(int j = 0; j<12; j+=2){
      digitalWrite(lights[i], HIGH);
    }
    delay(timer);
  }
}



void test(int dir){
  for(int i = 0; i<12; i++){
    
  }
  for(int i = 11; i>=0; i++){
    
  }
}


