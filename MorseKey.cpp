#include <iostream>
#include <fstream>
#include "MorsePi.hpp"
using namespace std;

int main()
{
	MorsePi morseOut;
	const char msg[] = "Hello World";
	for (auto c : msg) {
		morseOut.SendChar(c);
	}
	std::cout << std::endl;
	morseOut.Start();
	return 0;
}
