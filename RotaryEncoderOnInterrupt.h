#pragma once

static void _f_s_EmptyFunc_(){}

#define CREATE_ENCODER(NAME, PIN_A, PIN_B) \
static rotary_encoder NAME{PIN_A, PIN_B}; \
static void RisingFunc_##NAME() { \
  if (digitalRead(NAME._a)) { \
    NAME.pulses++; \
  } else { \
    NAME.pulses--; \
  } \
}

#define GET_ENCODER_RISING_ROUTINE(NAME) \
RisingFunc_##NAME

#define INIT_INTERRUPTS(NAME) \
attachInterrupt(digitalPinToInterrupt(NAME._b), NAME.fnc, RISING)

#define INIT_ENCODER(NAME) \
pinMode(NAME._a, INPUT_PULLUP); \
pinMode(NAME._b, INPUT_PULLUP); \
NAME.fnc = GET_ENCODER_RISING_ROUTINE(NAME); \
INIT_INTERRUPTS(NAME)


#define GET_PULSES(NAME) \
NAME.pulses

using rising_f = void(*)();
class rotary_encoder {
  public:
    int _a, _b;
    explicit rotary_encoder(int a, int b) : _a{a}, _b{b} {};
    volatile long pulses{0};
    rising_f fnc{_f_s_EmptyFunc_};
};
