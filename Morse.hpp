#ifndef _MORSE_KEY_
#define _MORSE_KEY_

#include <array>
#include <vector>
#include <cctype>

class Morse {
public:
	typedef std::array<char, 5> MorseChar;
	Morse();
	virtual bool keyIn();
	virtual bool keyOff();
	char Detect(char s);
	bool Clear();
	bool End();
	virtual bool putc(char c) { return true; };
protected:
	static std::array<MorseChar, 50> MorseTable; // モールス符号表
private:
	std::vector<char> inBuffer; // 入力中の符号列
	uint16_t sShort_t; // 短点一つ分の長さ
};
#endif

