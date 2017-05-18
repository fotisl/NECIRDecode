#include <Arduino.h>
#include "NECIRDecode.h"

NECIRDecode decoder(PC15);

void setup()
{
    decoder.init();
}

void loop()
{
    uint32_t next = decoder.getNext();

    if(next) {
        Serial.print("Got IR: ");
        Serial.println(next, HEX);
    }
}
