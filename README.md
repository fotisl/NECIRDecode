# NEC Infrared Decoder library

[![License](https://img.shields.io/badge/license-BSD%203--Clause-green.svg)](https://raw.githubusercontent.com/fotisl/NECIRDecode/master/LICENSE)

A library for decoding remote control codes using the NEC IR transmission
protocol for STM32duino.

# Usage

To use the library, you must first construct an object of type NECIRDecode.
Then you can use any of the methods displayed below.

## Methods

### NECIRDecode(int pin, int timer = 2)

The constructor takes one mandatory argument, which is the pin where the IR
receiver is connected, and one optional argument, which is the timer number
that will be used.

### void init()

The init() method initializes the library. It should usually be called once
in your setup() function.

### void stateMachine()

The state machine engine. It should never be called directly by a user. It is
a public method because it has to be called by the timer interrupt handler.

### uint32\_t getNext()

The getNext() method returns the next IR code received. If no code has been
received, the return value is 0. If a repeat code has been received, the
return value is 0xffffffff.

## Example

A generic example can be found in the examples/ directory.

# Notes

Due to some design issues related to calling the stateMachine() method from the
timer interrupt handler, you can only create a single object of this type at
every program.

The library can only hold a limited number of ir codes. If you don't handle them
in time, new ones will be lost.

# License

The code is licensed under the BSD 3-clause "New" or "Revised" License.
