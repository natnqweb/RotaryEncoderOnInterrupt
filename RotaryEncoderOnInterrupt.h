#pragma once

static void REOI_f_s_EmptyFunc_(){}

#define REOI_CREATE_ENCODER(NAME, PIN_A, PIN_B) \
static REOI_t_rotary_encoder NAME{PIN_A, PIN_B}; \
static void REOI_RisingFunc_##NAME() { \
  if (digitalRead(NAME._a)) { \
    NAME.pulses++; \
  } else { \
    NAME.pulses--; \
  } \
}

#define REOI_GET_ENCODER_RISING_ROUTINE(NAME) \
REOI_RisingFunc_##NAME

#define REOI_INIT_INTERRUPTS(NAME) \
attachInterrupt(digitalPinToInterrupt(NAME._b), NAME.fnc, RISING)

#define REOI_INIT_ENCODER(NAME) \
pinMode(NAME._a, INPUT_PULLUP); \
pinMode(NAME._b, INPUT_PULLUP); \
NAME.fnc = REOI_GET_ENCODER_RISING_ROUTINE(NAME); \
REOI_INIT_INTERRUPTS(NAME)


#define REOI_GET_PULSES(NAME) \
NAME.pulses

using REOI_f_rising = void(*)();
class REOI_t_rotary_encoder {
  public:
    int _a, _b;
    explicit REOI_t_rotary_encoder(int a, int b) : _a{a}, _b{b} {};
    volatile long pulses{0};
    REOI_f_rising fnc{REOI_f_s_EmptyFunc_};
};
