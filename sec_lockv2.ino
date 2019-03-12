#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <SPI.h>

#define SAD 10
#define RST 9
MFRC522 nfc(SAD, RST);

uint8_t id;
uint8_t getFingerprintEnroll();
int getFingerprintIDez();

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
   SPI.begin();
   Serial.begin(9600);
    Serial.println("Looking for MFRC522.");
   SPI.begin();

  Serial.begin(9600);

  Serial.println("Fingerprint and RFID Test");


  finger.begin(57600);
  if (finger.verifyPassword()) {
   Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }    
}

char abc;
void loop() {
    abc = Serial.read();
    switch (abc) {
      case '1': {
             //Enroll method
      }
      break ;
      case '2': {
        //verify method
      }break;
      case '3': {
       //rfid method
      }
   }
}
