void setup()
{
}
class Morse {
public:
	Morse();
	bool keyIn();
	bool keyOff();
	bool Start() {return true; };
	char Detect(char s);
	bool Clear();
	bool End();
	bool SendChar(char c);
	int getSpeed() { return cpm; };
protected:
	static const unsigned char MorseTable[];
private:
	unsigned char cpm; // モールス符号の速さ
	unsigned int sShort_t; // 短点一つ分の長さ
};
#include "../../MorseTable.tbl"
void loop()
{
}
