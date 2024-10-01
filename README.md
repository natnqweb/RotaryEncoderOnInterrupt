# RotaryEncoderOnInterrupt (ARDUINO)
probably easiest and shortest implementation of rotary encoder reader out there using hardware interrupts
HEADER ONLY LIBRARY



# EXAMPLE Arduino UNO
.ino file

``` c++
#include <Arduino.h>
#include "RotaryEncoderOnInterrupt.h"
#define ENCODER_PIN_A 7
#define ENCODER_PIN_B 3
#define ENCODER2_PIN_A 8
#define ENCODER2_PIN_B 2
// ENCODER__PIN_B IS INTERRPUT PIN
CREATE_ENCODER(s_enc, ENCODER_PIN_A, ENCODER_PIN_B)
CREATE_ENCODER(s_enc2, ENCODER2_PIN_A, ENCODER2_PIN_B)

void setup() {
  INIT_ENCODER(s_enc);
  INIT_ENCODER(s_enc2);
  Serial.begin(115200);
}

void loop() {
  delay(1000);
  Serial.println(GET_PULSES(s_enc));
  Serial.println(GET_PULSES(s_enc2));
}

```

# EXAMPLE Arduino MEGA
.ino file

``` c++
#include <Arduino.h>
#include "RotaryEncoderOnInterrupt.h"
#define ENCODER1_PIN_A 41
#define ENCODER1_PIN_B 3
#define ENCODER2_PIN_A 40
#define ENCODER2_PIN_B 18
#define ENCODER3_PIN_A 44
#define ENCODER3_PIN_B 2

// CREATE_ENCODER(<NAME>,<PIN_CLK_FROM_ENCODER>, <(DT)PIN_WITH_INTERRUPT>)
CREATE_ENCODER(enc_s, ENCODER1_PIN_A, ENCODER1_PIN_B)
CREATE_ENCODER(enc2_s, ENCODER2_PIN_A, ENCODER2_PIN_B)
CREATE_ENCODER(enc3_s, ENCODER3_PIN_A, ENCODER3_PIN_B)

void setup() {
  INIT_ENCODER(enc_s);
  INIT_ENCODER(enc2_s);
  INIT_ENCODER(enc3_s);
  Serial.begin(115200);
}

void loop() {
  delay(1000);
  Serial.println(GET_PULSES(enc_s));
  Serial.println(GET_PULSES(enc2_s));
  Serial.println(GET_PULSES(enc3_s));
}


```
