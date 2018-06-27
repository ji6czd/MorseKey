#include <iostream>
#include <fstream>
#include "MorsePi.hpp"
using namespace std;

int main()
{
	MorsePi morseOut;
	const char msg[] = "HELLO WORLD";
	for (auto c : msg) {
		morseOut.putc(c);
	}
	std::cout << std::endl;
	return 0;
}
