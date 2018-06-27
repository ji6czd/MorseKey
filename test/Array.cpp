#include <array>
#include <iostream>

int main()
{
	typedef std::array<char, 5> morseChar;
	morseChar Tbl = {1,2,3,4,5};
  std::array<morseChar, 50> MorseTable;
	std::cout << sizeof(MorseTable) << std::endl;
	return 0;
}
