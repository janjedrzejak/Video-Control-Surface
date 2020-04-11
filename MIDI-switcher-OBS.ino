/* ____________________ */
/* copyright by JJ 2020 */
/* Arduino MIDI console */
/* ____________________ */

#define prg1 2 //program 1
#define prg2 3 //program 2
#define prg3 4 //program 3
#define prg4 5 //program 4

#define prv1 6 //preview 1
#define prv2 7 //preview 2
#define prv3 8 //preview 3
#define prv4 9 //preview 4

bool niegotowe=false;

void setup()
{
	pinMode(prg1, INPUT);
    pinMode(prg2, INPUT);
    pinMode(prg3, INPUT);
    pinMode(prg4, INPUT);
    
    pinMode(prv1, INPUT);
    pinMode(prv2, INPUT);
    pinMode(prv3, INPUT);
    pinMode(prv4, INPUT);

    wlacz_serial();
}

void wlacz_serial() {
    Serial.begin(9600);

        while(!Serial) {
            niegotowe=true;
            if(msg) {
                Serial.println('Urzadzenie niegotowe, sprawdź połączenie USB');
            }
            delay(200);
        }

            niegotowe=false;

        if(!niegotowe) {
            for(int i=0; i<40; i++) {
                Serial.print('*');
                delay(500);
            }
            Serial.println('Urządzenie podłączone i gotowe');
        }
}

bool sprawdz_przycisk(button) {
    if(button == HIGH) {
        return true;
    }
}

void loop()
{  
	if(sprawdz_przycisk(prg1)) {
        
    }
}
