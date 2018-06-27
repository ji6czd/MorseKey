#include <iostream>
#include <wiringPi.h>
#include "MorsePi.hpp"

bool MorsePi::putc(char c)
{
	if (std::isspace(c)) {
			std::cout << " ";
		}
	else if (std::isalnum(c)) {
		for (auto s : MorseTable.at(std::toupper(c-0x30))) {
			std::cout << s;
		}
	}
		std::cout << " ";
	return true;
}
