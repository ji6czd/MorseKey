#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cctype>
#include "Morse.hpp"
#include "MorseTable.tbl"

Morse::Morse()
{
	shortSig=60;
	std::cout << sizeof(MorseTable) << std::endl;
	return;
}

bool Morse::Clear()
{
	inBuffer = 1;
	return true;
}

bool Morse::End()
{
	Clear();
	return true;
}

bool Morse::keyIn()
{
	return true;
}

bool Morse::keyOff()
{
	return true;
}

char Morse::Detect(int s)
{
	std::cout << "Sig:" << s << std::endl;
	switch (s) {
	case 0:
		std::cout << "Complete:" << (int)inBuffer << std::endl;
		inBuffer=1;
		return 'c';
		break;
	case 1:
		inBuffer <<= 1;
		inBuffer += 0;
		break;
	case 2:
		inBuffer <<= 1;
		inBuffer += 1;
		break;
	case -1:
		inBuffer = 1;
		return -1;
		break;
	}
	std::cout << inBuffer << std::endl;
	return 0;
}
