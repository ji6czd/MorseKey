#ifndef _MORSE_KEY_
#define _MORSE_KEY_

#include <cctype>
#include <time.h>
#include <unistd.h>

class Morse {
public:
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
	static const char MorseTable[][5];
private:
	uint8_t cpm; // モールス符号の速さ
	std::vector<char> inBuffer; // 入力中の符号列
	uint16_t sShort_t; // 短点一つ分の長さ
	timespec t_keyIn, t_keyOff;
};
#include "MorseTable.tbl"
#endif

