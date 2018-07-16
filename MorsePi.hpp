#ifndef _MORSE_PI_
#define _MORSE_PI_
#include <iostream>
#include "Morse.hpp"

class MorsePi: public Morse {
public:
  bool SendChar(char c);
	bool setupIO();
	bool keyIn();
	bool Start();
	uint16_t pulseLength(bool defStat);
};
#endif
