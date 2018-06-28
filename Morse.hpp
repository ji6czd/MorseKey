#ifndef _MORSE_KEY_
#define _MORSE_KEY_

#include <array>
#include <vector>
#include <cctype>
#include <time.h>
#include <unistd.h>

class Morse {
public:
	typedef std::array<char, 5> MorseChar;
	Morse();
	virtual bool setupIO() { return true; };
	virtual bool keyIn();
	virtual bool keyOff();
	virtual bool Start() {return true; };
	char Detect(char s);
	bool Clear();
	bool End();
	virtual bool putc(char c) { return true; };
	virtual int getSpeed() { return cpm; };
protected:
	static std::array<MorseChar, 50> MorseTable; // モールス符号表
private:
	uint8_t cpm; // モールス符号の速さ
	std::vector<char> inBuffer; // 入力中の符号列
	uint16_t sShort_t; // 短点一つ分の長さ
	timespec t_keyIn, t_keyOff;
};
#endif

