#ifndef NECIRDecode_h
#define NECIRDecode_h

#include <Arduino.h>
#include <HardwareTimer.h>

/* The following two can be changed */
/* This is the period between timer interrupts in usec */
#define	PERIOD					50
/* Threshold for error correction */
#define THRESHOLD               0.2
/* Buffer length for keeping received IR codes */
#define IRCODE_BUF_LEN          5
/* Do not change anything below */
#define START_PULSE_HIGH        (9000 / PERIOD)
#define START_PULSE_LOW_DATA    (4500 / PERIOD)
#define START_PULSE_LOW_REPEAT  (2250 / PERIOD)
#define DATA_PULSE_HIGH         (562 / PERIOD)
#define DATA_PULSE_LOW_ZERO     (562 / PERIOD)
#define DATA_PULSE_LOW_ONE      (1687 / PERIOD)
#define REPEAT_PULSE_HIGH       (562 / PERIOD)
#define REPEAT_DISTANCE         (108000 / PERIOD)

enum
{
    IR_IDLE,
    IR_INIT,
    IR_INIT_LOW,
    IR_DATA_HIGH,
    IR_DATA_LOW,
    IR_REPEAT
};

class NECIRDecode
{
    public:

    NECIRDecode(int pin, int timer = 2);
    void init();
    void stateMachine();
    uint32_t getNext();

    private:

    HardwareTimer irTimer;
    int pin;
	int currentState;
    size_t len;
    uint32_t mask, next, received[IRCODE_BUF_LEN];
    uint16_t pw, repeatpw;
    bool mayRepeat;
};

#endif
