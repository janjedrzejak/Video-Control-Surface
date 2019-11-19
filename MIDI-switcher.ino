/*
 4 channels MIDI video switcher for using with Arduino Nano
 and vMIX software. 
 Copyright by JJ 2019
*/

const int buttonPin1 = 2;     //PROGRAM 1
const int buttonPin2 = 3;     //PROGRAM 2
const int buttonPin3 = 4;     //PROGRAM 3
const int buttonPin4 = 5;     //PROGRAM 4

const int buttonPin5 = 6;     //PREVIEW 1
const int buttonPin6 = 7;     //PREVIEW 2
const int buttonPin7 = 8;     //PREVIEW 3
const int buttonPin8 = 9;     //PREVIEW 4

//initialize
int buttonState1 = 0;         
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;         
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int volume1 = 0;

void setup() {
  Serial.begin(115200); //Set MIDI baud rate to communication
  //setup pins mode on Arduino board
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
}
//send note to serial port
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
//Main:
void loop() {
  //reading buttons states
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
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (buttonState2 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x11, 0x45); //send midi as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (buttonState3 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x12, 0x45); //send midi as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (buttonState4 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x13, 0x45); //send midi as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW); 
  }
  //------------------------------------------
  if (buttonState5 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x20, 0x45); //send midi  as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (buttonState6 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x21, 0x45); //send midi as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (buttonState7 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x22, 0x45); //send midi as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (buttonState8 == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);

    noteOn(0x90, 0x23, 0x45); //send midi as note on
    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  //-----------------------------------------

  volume1 = analogRead(A0) / 8; //min 0 max 1023;
  //Serial.println(volume1, HEX);
  
  noteOn(0xB0, 0x23, volume1); //send midi as continues values 
  delay(200); //wait 200ms
  
}
