/**********************************************************
 4 channels MIDI video switcher for using with Arduino Uno
 and vMIX software. 
 Copyright by JJ 2019
**********************************************************/


//Program buttons pins declared
const int buttonPin1 = 2;  const int buttonPin2 = 3;    
const int buttonPin3 = 4;  const int buttonPin4 = 5;    
//Preview buttons pins declared
const int buttonPin5 = 6;  const int buttonPin6 = 7;     
const int buttonPin7 = 9;  const int buttonPin8 = 10;     
//74HC595
const int lPin = 8;       
const int cPin = 12;
const int dPin = 11;

//initialize variables
int buttonState1 = 0;   int buttonState2 = 0;
int buttonState3 = 0;   int buttonState4 = 0;
int buttonState5 = 0;   int buttonState6 = 0;
int buttonState7 = 0;   int buttonState8 = 0;

int rezFader, rezFaderNextPosition = 0;
bool initState=true;

void setup() {
  Serial.begin(115200); 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin10, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(lPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);


}
//Function - send note to serial port
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void shiftLed(int p) {
  int pin;
  pin = 1<< p;
  digitalWrite(lPin, LOW);
  shiftOut(dPin, cPin, MSBFIRST, pin);
  digitalWrite(lPin, HIGH);
}

void loop() {
  //reading digital states
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);

        //discovering button states
        if (buttonState1 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x10, 0x45); //send midi as note on
            shiftLed(1);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        if (buttonState2 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x11, 0x45); //send midi as note on  
            shiftLed(2);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        if (buttonState3 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x12, 0x45); //send midi as note on\   
            shiftLed(3);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        if (buttonState4 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x13, 0x45); //send midi as note on
            shiftLed(4);   
        } else {
            digitalWrite(LED_BUILTIN, LOW); 
        }
        //------------------------------------------
        if (buttonState5 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x20, 0x45); //send midi  as note on  
            shiftLed(5);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        if (buttonState6 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x21, 0x45); //send midi as note on 
            shiftLed(6);   
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        if (buttonState7 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x22, 0x45); //send midi as note on    
            shiftLed(7);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        if (buttonState8 == HIGH) {
            digitalWrite(LED_BUILTIN, HIGH);
            noteOn(0x90, 0x23, 0x45); //send midi as note on   
            shiftLed(8);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
        //-----------------------------------------
  //read analog state
  rezFader = analogRead(A0) / 8; 
  delay(20); //wait 20ms
  rezFaderNextPosition = analogRead(A0) / 8; //read next value (for checking changes)
  if(initState==true) { //if first connection send potentiometer value
    noteOn(0xB0, 0x23, volume1a);
    initState=false;
  }
  if (rezFader!=volume1a) { //if change is discover send to serial command, if not, don't send midi
    noteOn(0xB0, 0x23, volume1a); //send midi as continues values
  }
}
