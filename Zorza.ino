const int ARed = 9;
const int AGreen = 10;
const int ABlue = 11;
const int BRed = 3;
const int BGreen = 5;
const int BBlue = 6;

const int VOLTAGE = 7;

const int LIGHT = 0;

float aCountRed = random(255);
float aCountGreen = random(255);
float aCountBlue = random(255);
float bCountRed = random(255);
float bCountGreen = random(255);
float bCountBlue = random(255);

int lightValue;

float aSignRed = 0.7;
float aSignGreen = 0.8;
float aSignBlue = 0.9;
float bSignRed = 0.75;
float bSignGreen = 0.85;
float bSignBlue = 0.75;

const int STEP = 10; // milliseconds 
const int PI180 = PI/180;
const int BRIGHT = 18;

void setup() {
   Serial.begin(9600);
   pinMode(ARed, OUTPUT);
   pinMode(AGreen, OUTPUT);
   pinMode(ABlue, OUTPUT);
   pinMode(BGreen, OUTPUT);
   pinMode(BBlue, OUTPUT);
   pinMode(VOLTAGE, OUTPUT);
}

boolean lightOn = true;

void loop()
{
   lightValue = analogRead(LIGHT);
   Serial.println(lightValue);
   if (lightValue < BRIGHT) {
     digitalWrite(VOLTAGE, HIGH);
     if (aCountRed >= 255 or aCountRed <= 0) {
       aSignRed = -1 * aSignRed;
     }
     if (aCountGreen >= 255 or aCountGreen <= 0) {
       aSignGreen = -1 * aSignGreen;
     }
     if (aCountBlue >= 255 or aCountBlue <= 0) {
       aSignBlue = -1 * aSignBlue;
     }
     if (bCountRed >= 255 or bCountRed <= 0) {
       bSignRed = -1 * bSignRed;
     }
     if (bCountGreen >= 255 or bCountGreen <= 0) {
       bSignGreen = -1 * bSignGreen;
     }
     if (bCountBlue >= 255 or bCountBlue <= 0) {
       bSignBlue = -1 * bSignBlue;
     }
  
     aCountRed = aCountRed + aSignRed;
     aCountGreen = aCountGreen + aSignGreen;
     aCountBlue = aCountBlue + aSignBlue;
     bCountRed = bCountRed + bSignRed;
     bCountGreen = bCountGreen + bSignGreen;
     bCountBlue = bCountBlue + bSignBlue;   
     
     analogWrite(ARed, (int)aCountRed);
     analogWrite(AGreen, (int)aCountGreen);
     analogWrite(ABlue, (int)aCountBlue);
     analogWrite(BRed, (int)bCountRed);
     analogWrite(BGreen, (int)bCountGreen);
     analogWrite(BBlue, (int)bCountBlue);     
   } else {
     
     digitalWrite(VOLTAGE, LOW);
     analogWrite(ARed, LOW);
     analogWrite(AGreen, LOW);
     analogWrite(ABlue, LOW);
     analogWrite(BRed, LOW);
     analogWrite(BGreen, LOW);
     analogWrite(BBlue, LOW);     
   }
   delay(STEP);
}
