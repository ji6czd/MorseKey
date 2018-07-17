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
	virtual char Detect(int s);
	bool Clear();
	virtual bool End();
	virtual bool SendChar(char c) { return true; };
	virtual int getSpeed() { return cpm; };
  virtual uint16_t pulseLength(bool defStat) { return 0; };
protected:
	static const uint8_t MorseTable[];
	uint16_t setShortSig(uint16_t len) { shortSig=len; return shortSig; };
	uint16_t getShortSig() { return shortSig; };
	uint8_t inBuffer; // 入力中の符号列ビット
private:
	uint8_t cpm; // モールス符号の速さ
	uint16_t shortSig; // 短点一つ分の長さ
};
#endif

