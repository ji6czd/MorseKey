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
	inBuffer.clear();
	return true;
}

char Morse::Detect(char s)
{
	inBuffer.push_back(s);
	return ' ';
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
