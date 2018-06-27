#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cctype>

class Morse {
public:
	typedef std::array<char, 5> MorseChar;
	Morse();
	bool keyIn();
	bool keyOff();
	char Detect(char s);
	bool Clear();
	bool End();
	bool putc(char c);
private:
	static std::array<MorseChar, 50> MorseTable; // モールス符号表
	std::vector<char> inBuffer; // 入力中の符号列
	uint16_t sShort_t; // 短点一つ分の長さ
};

std::array<Morse::MorseChar, 50> Morse::MorseTable;
Morse::Morse()
{
	#include "MorseTable.tbl"
	std::cout << sizeof(MorseTable) << std::endl;
	return;
}

bool Morse::putc(char c)
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

int main()
{
	Morse morseOut;
	const char msg[] = "HELLO WORLD";
	for (auto c : msg) {
		morseOut.putc(c);
	}
	std::cout << std::endl;
	return 0;
}
