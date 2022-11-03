
const int buzzerPin = 3;
const int ledPietonVerde = 9;
const int ledPietonRosu = 8;
const int ledMasinaVerde = 7;
const int ledMasinaGalben = 6;
const int ledMasinaRosu = 5;

const int buttonPin = 13;

unsigned long time_now = 0;
unsigned int secondStateInitialize = 8000;
unsigned int secondStateDuration = 3000;
unsigned int thirdStateDuration = 8000;
unsigned int fourthStateDuration = 4000;

int buzzerTone = 1000;

byte start = 1;
byte buttonState = LOW;
byte ledState = HIGH;
int buttonPushCounter = 0;
byte lastReading = LOW;
byte reading = LOW;

unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 50;
unsigned long lastState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(ledPietonVerde, OUTPUT);
  pinMode(ledPietonRosu, OUTPUT);

  pinMode(ledMasinaVerde, OUTPUT);
  pinMode(ledMasinaGalben, OUTPUT);
  pinMode(ledMasinaRosu, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // TODO

  if(start == 1){
    reading = digitalRead(buttonPin);
    start = 0;
  }


  if(reading == HIGH){
//First state:
    digitalWrite(ledPietonRosu, HIGH);
    digitalWrite(ledMasinaVerde, HIGH);
  }
  else{

    
       lastState = millis();
     

    while(millis() < lastState + secondStateInitialize){

   }
   
//Second state:

    lastState = millis();
    digitalWrite(ledMasinaVerde, LOW);
    digitalWrite(ledMasinaGalben, HIGH);

    while(millis() < lastState + secondStateDuration){

    }
//Third state:
  lastState = millis();

  digitalWrite(ledMasinaGalben, LOW);
  digitalWrite(ledPietonRosu, LOW);
  digitalWrite(ledMasinaRosu, HIGH);
  digitalWrite(ledPietonVerde, HIGH);

  while(millis() < lastState + thirdStateDuration){
    if(((millis() / 960) % 2) == 0){
     tone(buzzerPin, buzzerTone, 200);
    }
  }
//Fourth state + return:

  lastState = millis();

  while(millis() < lastState + fourthStateDuration){
   digitalWrite(ledPietonVerde, (millis() / 380) % 2);
   if(((millis() / 380) % 2) == 0){
     tone(buzzerPin, buzzerTone, 50);
   }
  }
    digitalWrite(ledMasinaRosu, LOW);
    digitalWrite(ledPietonVerde, LOW);
}
start = 1;
}



