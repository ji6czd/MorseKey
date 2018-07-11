#include <iostream>
#include <wiringPi.h>
#include <softTone.h>
#include "MorsePi.hpp"
#include <unistd.h>
#include <time.h>
#define KEY 5
#define BZ 6

bool MorsePi::putc(char c)
{
	if (std::isspace(c)) {
			std::cout << " ";
		}
	else if (std::isalnum(c)) {
		uint8_t s = MorseTable[toupper(c)-0x30];
		while (s != 1) {
			if (s & 0b1) {
				std::cout << '-';
			} else {
				std::cout << '.';
			}
			s >>= 1;
			}
	}
		std::cout << " ";
	return true;
}
bool MorsePi::setupIO()
{
	if (!wiringPiSetupGpio())  {
		return false;
	}
	pinMode(KEY, INPUT);
	pullUpDnControl(KEY, PUD_UP);
	if (!softToneCreate(BZ)) {
		return false;
	}
	return true;
}

bool MorsePi::keyIn()
{
	return true;
}

