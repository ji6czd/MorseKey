#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cctype>
#include "Morse.hpp"
std::array<Morse::MorseChar, 50> Morse::MorseTable;
Morse::Morse()
{
	#include "MorseTable.tbl"
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
	return 0;
}

bool Morse::keyIn()
{
	clock_gettime(CLOCK_MONOTONIC, &t_keyIn);
	return true;
}

bool Morse::keyOff()
{
}
