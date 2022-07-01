/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/maxwell/CTD-IoT/d5/uartcomm-reciever/src/uartcomm-reciever.ino"
// whoops, spelled receiver wrong

// setup() runs once, when the device is first turned on.
void setup();
void loop();
#line 4 "/home/maxwell/CTD-IoT/d5/uartcomm-reciever/src/uartcomm-reciever.ino"
SYSTEM_MODE(AUTOMATIC);
// #define FIRSTARGON
#define SECONDARGON
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(D7, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  #ifdef FIRSTARGON
  if (Serial1.available() > 0) {
    char value = Serial1.read();
    Serial.write(value);
    if (value == 'O') {
      digitalWrite(D7, HIGH);
      
    } else if (value == 'F') {
      digitalWrite(D7, LOW);
    }
  }
  #endif
  #ifdef SECONDARGON
  if (Serial.available() > 0) {
    char value = Serial.read();
    if (value == '1') {
      Serial1.write('O');
    } else if (value == '0') {
      Serial1.write('F');
    } else if (value == '?') {
      Serial1.write('G');
      delay(100ms);
      Serial.println();
      Serial.write(Serial1.read());
      Serial.println();
    }
  }
  // Serial1.write('O');
  // delay(500ms);
  // Serial1.write('F');
  // delay(500ms);
  #endif

}