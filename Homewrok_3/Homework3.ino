const int pinSW = 2; // digital pin connected to switch output
const int pinX = A0; // A0 - analog pin connected to X output
const int pinY = A1; // A1 - analog pin connected to Y output

// declare all the segments pins
const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 9;
const int pinG = 10;
const int pinDP = 11;

const int segSize = 8;
int index = 0;

// modify if you have common anode
bool commonAnode = false; 

#define firstState 1
#define secondState 2

byte state = firstState;
byte buttonState = HIGH;

byte swState = LOW;
byte sw2State = LOW;

byte lastSwState = LOW;
int xValue = 0;
int yValue = 0;

bool joyMoved = false;
int minThreshold = 350;
int maxThreshold = 650;
unsigned long int previousTime;
int inputDelay = 500;

unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 50;
unsigned int resetTimer = 3000;

int segments[segSize] = { 
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

int defaultSegment = pinDP;
int currentSegment = pinDP;

byte digitMatrix[segSize][segSize] = {
// a  b  c  d  e  f  g dp
  {1, 0, 0, 0, 0, 0, 0, 0}, // a
  {0, 1, 0, 0, 0, 0, 0, 0}, // b
  {0, 0, 1, 0, 0, 0, 0, 0}, // c
  {0, 0, 0, 1, 0, 0, 0, 0}, // d
  {0, 0, 0, 0, 1, 0, 0, 0}, // e
  {0, 0, 0, 0, 0, 1, 0, 0}, // f
  {0, 0, 0, 0, 0, 0, 1, 0}, // g
  {0, 0, 0, 0, 0, 0, 0, 1}, // dp
};

byte digitBlank[segSize][segSize] = {
// a  b  c  d  e  f  g dp
  {0, 0, 0, 0, 0, 0, 0, 0}, // a
  {0, 0, 0, 0, 0, 0, 0, 0}, // b
  {0, 0, 0, 0, 0, 0, 0, 0}, // c
  {0, 0, 0, 0, 0, 0, 0, 0}, // d
  {0, 0, 0, 0, 0, 0, 0, 0}, // e
  {0, 0, 0, 0, 0, 0, 0, 0}, // f
  {0, 0, 0, 0, 0, 0, 0, 0}, // g
  {0, 0, 0, 0, 0, 0, 0, 0}, // dp
};

int nextState[segSize][4] = {
//UP,DOWN,LEFT,RIGHT
  {-1, 6, 5, 1},  //a
  {0, 6, 5, -1},  //b
  {6, 3, 4, 7},  //c
  {6, -1, 4, 2},   //d
  {6, 3, -1, 2},  //e
  {0, 6, -1, 1},  //f
  {0, 3, -1, -1}, //g
  {-1, -1, 2, -1} //dp
};

void setup() {
  // initialize all the pins
  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(pinSW, INPUT_PULLUP);
  if (commonAnode == true) {
    buttonState = !buttonState;
  }
}

void loop() {
  // TODO: use joystick movement to cycle through the numbers from 0 to 9, with a state changer (aka if you move the joystick, only one increment should happen. The next change should be after the joystick went back to 
 
 if(state == firstState){
 
    xValue = analogRead(pinX);
    yValue = analogRead(pinY);

    swState = digitalRead(pinSW);

    if (swState == LOW){
      state = secondState;
    }

    if((minThreshold <= xValue && xValue <= maxThreshold) || (minThreshold <= yValue && yValue <= maxThreshold)){
      joyMoved = false;
    }

    if(xValue > maxThreshold && joyMoved == false){
      if (nextState[currentSegment][0] != -1){
        currentSegment = nextState[currentSegment][0]; 
      };
      joyMoved = true;
    }

    if(xValue < minThreshold && joyMoved == false){
      if(nextState[currentSegment][1] != -1){
        currentSegment = nextState[currentSegment][1]; 
      }
      joyMoved = true;
    }

    if(yValue < minThreshold && joyMoved == false){
      if(nextState[currentSegment][2] != -1){
        currentSegment = nextState[currentSegment][2];
      }
      joyMoved = true;
    }

    if(yValue > maxThreshold && joyMoved == false){
      if(nextState[currentSegment][3] != -1){
        currentSegment = nextState[currentSegment][3];
      }
      joyMoved = true;
    }  

    displaySegment(currentSegment);

 }else if(state == secondState){
    xValue = analogRead(pinX);

    sw2State = digitalRead(pinSW);
  

    if(minThreshold <= xValue && xValue <= maxThreshold){
      joyMoved = false;
    }

    if(xValue < minThreshold && joyMoved == false){;
      displayToggle(currentSegment);
      currentSegment = defaultSegment;
      joyMoved = true;
    }

    if(xValue > maxThreshold && joyMoved == false){
      digitBlank[currentSegment][currentSegment] = 1;
      displayToggle(currentSegment);
      currentSegment = defaultSegment;
      joyMoved = true;
            state = firstState;
    }

  }  




} 
void displaySegment(int currentSegment) {
  
    for (int i=0; i<segSize; i++) {
      digitalWrite(segments[i],digitMatrix[currentSegment][i]);
    }
    delay(200);

      for (int i=0; i<segSize; i++) {
      digitalWrite(segments[i],digitBlank[currentSegment][i]);
    }
    delay(200);

}

void displayToggle(int currentSegment){
      for (int i=0; i<segSize; i++) {
        digitMatrix[i][currentSegment] = 1;
        digitBlank[i][currentSegment] = 1;
        digitalWrite(segments[i],digitBlank[currentSegment][i]);
      }
}

void restart(){
  for(int i = 0; i <segSize; i++){
    for(int j = 0; j <segSize; i++){
      digitBlank[i][j] = 0;
    }
  }
}

