#ifndef _MORSE_KEY_
#define _MORSE_KEY_

#include <vector>
#include <cctype>
#include <cstdint>
#include <time.h>
#include <unistd.h>
using namespace std;
class Morse {
public:
	Morse();
	virtual bool setupIO() { return true; };
	virtual bool keyIn();
	virtual bool keyOff();
	virtual bool Start() {return true; };
	char Detect(char s);
	bool Clear();
	virtual bool End();
	virtual bool SendChar(char c) { return true; };
	virtual int getSpeed() { return cpm; };
  virtual uint16_t pulseLength(bool defStat) { return 0; };
protected:
	static const uint8_t MorseTable[];
	uint8_t cpm; // モールス符号の速さ
	std::vector<unsigned char> inBuffer; // 入力中の符号列
	uint16_t shortSig; // 短点一つ分の長さ
private:
};
#endif

