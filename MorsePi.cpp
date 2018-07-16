#include <iostream>
#include <wiringPi.h>
#include <softTone.h>
#include "MorsePi.hpp"
#include <unistd.h>
#include <time.h>
#define KEY 5
#define BZ 6
using namespace std;
bool MorsePi::SendChar(char c)
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
	shortSig = pulseLength(true);
}

bool MorsePi::Start()
{
	while(1) {
		while(digitalRead(KEY)) {
			; // waiting keyin...
		}
		keyIn();
		std::cout << shortSig << std::endl;
		keyOff();
	}
	return true;
}

uint16_t MorsePi::pulseLength(bool defStat)
{
	timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	while(digitalRead(KEY) != defStat) {
		; // wating pin state changed
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	return (end.tv_nsec-start.tv_nsec)*1000;
}
