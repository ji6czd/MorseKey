void setup()
{
  Serial.begin(9600);
}

class Morse {
public:
	Morse();
	bool keyIn() { return true; };
	bool keyOff() { return true; };
	bool Start() {return true; };
	bool sendC(int c);
	char Detect(char s);
	bool Clear();
	bool End() { return true; };
	int getSpeed() { return cpm; };
private:
	static const unsigned char MorseTable[];
	unsigned short cpm; // モールス符号の速さ
	unsigned int sShort_t; // 短点一つ分の長さ
};

#include "../../MorseTable.tbl"

Morse::Morse()
{
	cpm=45;
	return;
}

bool Morse::sendC(int c)
{
	if (isspace(c)) {
		Serial.write(" ");
		}
	else if (isalnum(c)) {
		unsigned char s = MorseTable[toupper(c)-0x30];
		while (s != 1) {
			if (s & 0b1) {
				Serial.write('-');
			} else {
				Serial.write('.');
			}
			s >>= 1;
			}
	}
	Serial.write(' ');
	return true;
}

Morse mOut;
void loop()
{
	int c = Serial.read();
	if (isalnum(c)) {
		mOut.sendC(c);
		Serial.write("\r\n");
	}
  return;
}
