#include <M5Stack.h>
#include "SoundOut.hpp"

#define TONE 700

void setup()
{
	M5.begin();
	sOut.begin();
}

class Morse {
public:
	Morse();
	bool keyIn() { return true; };
	bool keyOff() { return true; };
	bool Start() {return true; };
	bool sendC(char c);
	char Detect(char s);
	bool Clear();
	bool End() { return true; };
	int getSpeed() { return cpm; };
	void setSpeed(int s) { cpm = s; }
private:
	static const unsigned char MorseTable[];
	unsigned short cpm; // モールス符号の速さ
	unsigned int sShort_t; // 短点一つ分の長さ
	void outShort();
	void outLong();
};

#include "../../MorseTable.tbl"

Morse::Morse()
{
	Serial.println(sizeof(MorseTable));
	return;
}

bool Morse::sendC(char c)
{
	if (isspace(c)) {
		Serial.write(" ");
		}
	else if (isalnum(c)) {
		unsigned char s = MorseTable[toupper(c)-0x30];
		while (s != 1) {
			if (s & 0b1) {
				Serial.write('-');
				outLong();
			} else {
				Serial.write('.');
				outShort();
			}
			s >>= 1;
			}
	}
	Serial.write(' ');
	return true;
}

void Morse::outShort() {
	sOut.waitBeep(TONE, cpm*1);
	delay(cpm*1);
}

void Morse::outLong() {
	sOut.waitBeep(TONE, cpm*3);
	delay(cpm*1);
}

Morse mOut;
const char *msg = "Hello World.";
void loop()
{
	Serial.println("Hello World");
	for (const char* c=msg; *c!='\0'; c++) {
		mOut.sendC(*c);
	}
	delay(1000);
  return;
}
