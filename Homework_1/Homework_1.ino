const int maxAnalogValue = 1023;
const int maxVoltageValue = 255;
const int minAnalogValue = 0;
const int minVoltageValue = 0;

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

const int redPotPin = A0;
const int greenPotPin = A1;
const int bluePotPin = A2;

int redBrightness = 0;
int greenBrightness = 0;
int blueBrightness = 0;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(redPotPin, INPUT);
  pinMode(greenPotPin, INPUT);
  pinMode(bluePotPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  redBrightness = analogRead(redPotPin);
  greenBrightness = analogRead(greenPotPin);
  blueBrightness = analogRead(bluePotPin);


  analogWrite(redPin, map(redBrightness, minAnalogValue, maxAnalogValue, minVoltageValue, maxVoltageValue));
  analogWrite(greenPin, map(greenBrightness, minAnalogValue, maxAnalogValue, minVoltageValue, maxVoltageValue));
  analogWrite(bluePin, map(blueBrightness, minAnalogValue, maxAnalogValue, minVoltageValue, maxVoltageValue));


}
