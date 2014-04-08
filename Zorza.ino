int LED[] ={9, 10, 11, 3, 5, 6};  // RGB, RGB
const int LIGHTPIN = 0;
const int VOLTAGE = 7; // Providing +5V to the pin
const int PINCOUNT = 6;
float lightness[] = {1, 1, 1, 1, 1, 1};
float steps[] = {0.7, 0.8, 0.9, 0.75, 0.85, 0.75};
int lightValue;

const int STEP = 10; // milliseconds to change the values
const int PI180 = PI/180;
const int BRIGHT = 10; // switch on if darker 

void setup() {
   Serial.begin(9600);
   for (int i = 0; i < PINCOUNT; i++) {
     pinMode(LED[i], OUTPUT);
     lightness[i] = random(255);
   }
   pinMode(VOLTAGE, OUTPUT);
}

void loop()
{
   lightValue = analogRead(LIGHTPIN);
   if (lightValue < BRIGHT) {
     digitalWrite(VOLTAGE, HIGH);
     for (int i = 0; i < PINCOUNT; i++) {
       if (lightness[i] >= 255 or lightness[i] <= 0) {
         steps[i] = -1 * steps[i];
       }
       lightness[i] = lightness[i] + steps[i];
       analogWrite(LED[i], (int)lightness[i]);
     }
   } else {
     digitalWrite(VOLTAGE, LOW);
   }
   delay(STEP);
}
