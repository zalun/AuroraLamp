int LED[] ={9, 10, 11, 3, 5, 6};  // RGB, RGB
const int AMBIENTPIN = 0; // measuring ambient light on pin A0
const int VOLTAGE = 7; // Providing +5V to the pin

const int PINCOUNT = 6;
float degree[] = {1, 1, 1, 1, 1, 1};
float steps[] = {0.17, 0.19, 0.23, 0.21, 0.18, 0.16}; // changes of the degrees for each pin

int ambientLight;
int lightToPin;

const int STEP = 5; // milliseconds to change the values
const float PI180 = 0.01745329251;
const int BRIGHT = 10; // switch on if darker 

void setup() {
   Serial.begin(9600);
   for (int i = 0; i < PINCOUNT; i++) {
     pinMode(LED[i], OUTPUT);
     degree[i] = random(360); // randomize starting colors
   }
   pinMode(VOLTAGE, OUTPUT);
}

void loop()
{
   ambientLight = analogRead(AMBIENTPIN);
   if (ambientLight < BRIGHT) {
     digitalWrite(VOLTAGE, HIGH);
     for (int i = 0; i < PINCOUNT; i++) {
       if (degree[i] >= 360) {
         degree[i] = 0;
       }
       degree[i] = degree[i] + steps[i];
       lightToPin = (1 + sin(degree[i] * PI180)) * 127;
       analogWrite(LED[i], (int)lightToPin);
     }
   } else {
     digitalWrite(VOLTAGE, LOW);
   }
   delay(STEP);
}
