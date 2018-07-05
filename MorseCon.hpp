#ifndef _MORSE_CON_
#define _MORSE_CON_
#include <iostream>
#include "Morse.hpp"

class MorseCon: public Morse {
public:
	bool putc(char c);
	bool keyIn();
	bool keyOff();
};
#endif
