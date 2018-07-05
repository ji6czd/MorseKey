#include <iostream>
#include "MorseCon.hpp"
#include <time.h>
#include <unistd.h>

bool MorseCon::putc(char c)
{
	if (std::isspace(c)) {
			std::cout << " ";
		}
	else if (std::isalnum(c)) {
		for (auto s : MorseTable[std::toupper(c-0x30)]) {
			std::cout << s;
		}
	}
		std::cout << " ";
	return true;
}

bool MorseCon::keyIn()
{
	return true;
}

bool MorseCon::keyOff()
{
	return true;
}
