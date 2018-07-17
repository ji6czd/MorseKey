#include <iostream>
#include <wiringPi.h>
#include <softTone.h>
#include "MorsePi.hpp"
#include <unistd.h>
#include <time.h>
#define KEY 5
#define BZ 6
#define DEF_SHORT 100

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
	setShortSig(pulseLength(false));
}

bool MorsePi::keyOff()
{
	setShortSig(pulseLength(true));
}

bool MorsePi::Start()
{
	while(1) {
		keyOff();
		if (getShortSig() > (DEF_SHORT*0.7*3) && getShortSig() < (DEF_SHORT*1.3*3)) {
			// 短点三つ分のスペースを検出したら
			Detect(0);
		}
		keyIn();
		if (getShortSig() > (DEF_SHORT*0.7*3) && getShortSig() < (DEF_SHORT*1.3*3)) {
			// 短点三つ分を検出したら
			Detect(2);
		} else if (getShortSig() > (DEF_SHORT*0.7) && getShortSig() < (DEF_SHORT*1.3)) {
			// 短点を検出したら
			Detect(1);
		}
	}
	return true;
}

uint16_t MorsePi::pulseLength(bool defStat)
{
	timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	while(1) {
		while(digitalRead(KEY) == defStat) {
		; // waiting pin state changed
		}
		usleep(5000);
		if (digitalRead(KEY) != defStat) break;
		// 5ms待ってみて状態が変化してなかったら本物。そうでなければおそらくチャタリング
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	uint16_t len = (end.tv_sec-start.tv_sec)*1000;
	len+=(end.tv_nsec-start.tv_nsec)/1000/1000;
	/*if (defStat == false) 
		std::cout << "Keyin:";
	else
		std::cout << "Keyoff:";
		std::cout << len << endl;*/
	return len;
}
