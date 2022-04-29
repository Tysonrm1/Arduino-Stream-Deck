#include <RotaryEncoder.h>
#define PIN_IN1 2
#define PIN_IN2 3
uint8_t buf[8] = {
  0
};  // Keyboard Report Buffer: 8 bytes

#define PIN_F13 A0
#define PIN_F14 A1
#define PIN_F15 A2
#define PIN_F16 A3
#define PIN_F18 A4
#define PIN_F19 A5
#define PIN_F21 4
#define PIN_F22 5
#define PIN_F23 6
#define PIN_F24 7
#define PIN_scrollLock 9

//#define SERIAL_DEBUG  // for serial debug: remove //
                        // for actual HID: put //

bool currState_F13 = HIGH;
bool currState_F14 = HIGH;
bool currState_F15 = HIGH;
bool currState_F16 = HIGH;
bool currState_F18 = HIGH;
bool currState_F19 = HIGH;
bool currState_F21 = HIGH;
bool currState_F22 = HIGH;
bool currState_F23 = HIGH;
bool currState_F24 = HIGH;
bool currState_scrollLock = HIGH; 
          
bool prevState_F13 = HIGH; 
bool prevState_F14 = HIGH; 
bool prevState_F15 = HIGH; 
bool prevState_F16 = HIGH;
bool prevState_F18 = HIGH;
bool prevState_F19 = HIGH;
bool prevState_F21 = HIGH;
bool prevState_F22 = HIGH;
bool prevState_F23 = HIGH;
bool prevState_F24 = HIGH;
bool prevState_scrollLock = HIGH; 

unsigned long prevTime_F13 = 0;
unsigned long prevTime_F14 = 0;
unsigned long prevTime_F15 = 0;
unsigned long prevTime_F16 = 0;
unsigned long prevTime_F18 = 0;
unsigned long prevTime_F19 = 0;
unsigned long prevTime_F21 = 0;
unsigned long prevTime_F22 = 0;
unsigned long prevTime_F23 = 0;
unsigned long prevTime_F24 = 0;
unsigned long prevTime_scrollLock = 0;

unsigned long waitTime_F13 = 50;
unsigned long waitTime_F14 = 50;
unsigned long waitTime_F15 = 50;
unsigned long waitTime_F16 = 50;
unsigned long waitTime_F18 = 50;
unsigned long waitTime_F19 = 50;
unsigned long waitTime_F21 = 50;
unsigned long waitTime_F22 = 50;
unsigned long waitTime_F23 = 50;
unsigned long waitTime_F24 = 50;
unsigned long waitTime_scrollLock = 50;
RotaryEncoder encoder(PIN_IN1, PIN_IN2);
void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_F13, INPUT_PULLUP);
  pinMode(PIN_F14, INPUT_PULLUP);
  pinMode(PIN_F15, INPUT_PULLUP);
  pinMode(PIN_F16, INPUT_PULLUP);
  pinMode(PIN_F18, INPUT_PULLUP);
  pinMode(PIN_F19, INPUT_PULLUP);
  pinMode(PIN_F21, INPUT_PULLUP);
  pinMode(PIN_F22, INPUT_PULLUP);
  pinMode(PIN_F23, INPUT_PULLUP);
  pinMode(PIN_F24, INPUT_PULLUP);
  pinMode(PIN_scrollLock, INPUT);
  
  delay(200);
}

void loop() 
{
  checkButton();
  
}


void checkButton() {
 static int pos = 0;
  encoder.tick();
   int newPos = encoder.getPosition();
  
  if (pos != newPos) {
   // Serial.print(((int)encoder.getDirection()));
    if (newPos > pos){
      buf[2] = 108;
      Serial.write(buf, 8);
    } else if (newPos < pos){
      buf[2] = 111;
      Serial.write(buf, 8);
    }
  releaseKey();
  }
   // Serial.print("pos:");
   // Serial.print(newPos);
   // Serial.print(" dir:");
   // Serial.println((int)(encoder.getDirection()));
    
  bool currRead_F13 = digitalRead(PIN_F13);
  bool currRead_F14 = digitalRead(PIN_F14);
  bool currRead_F15 = digitalRead(PIN_F15);
  bool currRead_F16 = digitalRead(PIN_F16);
  bool currRead_F18 = digitalRead(PIN_F18);
  bool currRead_F19 = digitalRead(PIN_F19);
  bool currRead_F21 = digitalRead(PIN_F21);
  bool currRead_F22 = digitalRead(PIN_F22);
  bool currRead_F23 = digitalRead(PIN_F23);
  bool currRead_F24 = digitalRead(PIN_F24);
  bool currRead_scrollLock = digitalRead(PIN_scrollLock);

  if (currRead_F13 != prevState_F13) {
    prevTime_F13 = millis();
  }
  if (currRead_F14 != prevState_F14) {
    prevTime_F14 = millis();
  }
  if (currRead_F15 != prevState_F15) {
    prevTime_F15 = millis();
  }
  if (currRead_F16 != prevState_F16) {
    prevTime_F16 = millis();
  }
  if (currRead_F18 != prevState_F18) {
    prevTime_F18 = millis();
  }
  if (currRead_F19 != prevState_F19) {
    prevTime_F19 = millis();
  }
  if (currRead_F21 != prevState_F21) {
    prevTime_F21 = millis();
  }
  if (currRead_F22 != prevState_F22) {
    prevTime_F22 = millis();
  }
  if (currRead_F23 != prevState_F23) {
    prevTime_F23 = millis();
  }
  if (currRead_F24 != prevState_F24) {
    prevTime_F24 = millis();
  }
  if (currRead_scrollLock != prevState_scrollLock) {
    prevTime_scrollLock = millis();
  }

  if ((millis() - prevTime_F13) > waitTime_F13) {
    if (currRead_F13 != currState_F13) {
      currState_F13 = currRead_F13;
      if (currState_F13 == LOW) {
        // Send the code
        buf[2] = 104;    // HID: W key
#ifdef SERIAL_DEBUG
        buf[2] = 'F13';     // Serial: W key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_F14) > waitTime_F14) {
    if (currRead_F14 != currState_F14) {
      currState_F14 = currRead_F14;
      if (currState_F14 == LOW) {
        // Send the code
        buf[2] = 105;   // HID: A key
#ifdef SERIAL_DEBUG
        buf[2] = 'f14';   // Serial: A key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_F15) > waitTime_F15) {
    if (currRead_F15 != currState_F15) {
      currState_F15 = currRead_F15;
      if (currState_F15 == LOW) {
        // Send the code
        buf[2] = 106;    // HID: S key
#ifdef SERIAL_DEBUG
        buf[2] = 'f15';     // Serial: S key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_F16) > waitTime_F16) {
    if (currRead_F16 != currState_F16) {
      currState_F16 = currRead_F16;
      if (currState_F16 == LOW) {
        // Send the code
        buf[2] = 107;   // HID: D key
#ifdef SERIAL_DEBUG        
        buf[2] = 'f16';   // Serial: D key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
if ((millis() - prevTime_F18) > waitTime_F18) {
    if (currRead_F18 != currState_F18) {
      currState_F18 = currRead_F18;
      if (currState_F18 == LOW) {
        // Send the code
        buf[2] = 109;    // HID: W key
#ifdef SERIAL_DEBUG
        buf[2] = 'f18';     // Serial: W key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_F19) > waitTime_F19) {
    if (currRead_F19 != currState_F19) {
      currState_F19 = currRead_F19;
      if (currState_F19 == LOW) {
        // Send the code
        buf[2] = 110;    // HID: F19 key
#ifdef SERIAL_DEBUG
        buf[2] = 'f19';     // Serial: F19 key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_F21) > waitTime_F21) {
    if (currRead_F21 != currState_F21) {
      currState_F21 = currRead_F21;
      if (currState_F21 == LOW) {
        buf[2] = 112;
#ifdef SERIAL_DEBUG
        buf[2] = 'f21';
#endif
        Serial.write(buf, 8);
      } else {
        releaseKey(); 
      }
    }
  }
  if ((millis() - prevTime_F22) > waitTime_F22) {
    if (currRead_F22 != currState_F22) {
      currState_F22 = currRead_F22;
      if (currState_F22 == LOW) {
        buf[2] = 113;
#ifdef SERIAL_DEBUG
        buf[2] = 'f22';
#endif
        Serial.write(buf, 8);
      } else {
        releaseKey(); 
      }
    }
  }
  if ((millis() - prevTime_F23) > waitTime_F23) {
    if (currRead_F23 != currState_F23) {
      currState_F23 = currRead_F23;
      if (currState_F23 == LOW) {
        buf[2] = 114;
#ifdef SERIAL_DEBUG
        buf[2] = 'f23';
#endif
        Serial.write(buf, 8);
      } else {
        releaseKey(); 
      }
    }
  }
  if ((millis() - prevTime_F24) > waitTime_F24) {
    if (currRead_F24 != currState_F24) {
      currState_F24 = currRead_F24;
      if (currState_F24 == LOW) {
        buf[2] = 115;
#ifdef SERIAL_DEBUG
        buf[2] = 'f24';
#endif
        Serial.write(buf, 8);
      } else {
        releaseKey(); 
      }
    }
  }
  if ((millis() - prevTime_scrollLock) > waitTime_scrollLock) {
    if (currRead_scrollLock != currState_scrollLock) {
      if (currState_scrollLock == HIGH) {
        buf[2] = 71;
#ifdef SERIAL_DEBUG
        buf[2] = 'scrollLock';
#endif
        Serial.write(buf, 8);
        delay(100);
        releaseKey();
      } else {
        releaseKey();
      }
    }
  }
  prevState_F13 = currRead_F13;
  prevState_F14 = currRead_F14;
  prevState_F15 = currRead_F15;
  prevState_F16 = currRead_F16;
  prevState_F18 = currRead_F18;
  prevState_F19 = currRead_F19;
  prevState_F21 = currRead_F21;
  prevState_F22 = currRead_F22;
  prevState_F23 = currRead_F23;
  prevState_F24 = currRead_F24;
  prevState_scrollLock = currRead_scrollLock;
  pos = newPos;
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;

  Serial.write(buf, 8); // Release key  
}
