const int ARed = 9;
const int AGreen = 10;
const int ABlue = 11;
// BRed is taken from ABlue
const int BGreen = 5;
const int BBlue = 6;

float aCountRed = random(255);
float aCountGreen = random(255);
float aCountBlue = random(255);
float bCountGreen = random(255);
float bCountBlue = random(255);

float aSignRed = 0.7;
float aSignGreen = 0.8;
float aSignBlue = 0.9;
float bSignGreen = 0.85;
float bSignBlue = 0.75;

const int STEP = 10; // milliseconds 
const int PI180 = PI/180;

void setup() {
   pinMode(ARed, OUTPUT);
   pinMode(AGreen, OUTPUT);
   pinMode(ABlue, OUTPUT);
   pinMode(BGreen, OUTPUT);
   pinMode(BBlue, OUTPUT);
}



void loop()
{
   if (aCountRed >= 255 or aCountRed <= 0) {
     aSignRed = -1 * aSignRed;
   }
   if (aCountGreen >= 255 or aCountGreen <= 0) {
     aSignGreen = -1 * aSignGreen;
   }
   if (aCountBlue >= 255 or aCountBlue <= 0) {
     aSignBlue = -1 * aSignBlue;
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
   bCountGreen = bCountGreen + bSignGreen;
   bCountBlue = bCountBlue + bSignBlue;   
   
   analogWrite(ARed, (int)aCountRed);
   analogWrite(AGreen, (int)aCountGreen);
   analogWrite(ABlue, (int)aCountBlue);
   analogWrite(BGreen, (int)bCountGreen);
   analogWrite(BBlue, (int)bCountBlue);
   delay(STEP);
}
