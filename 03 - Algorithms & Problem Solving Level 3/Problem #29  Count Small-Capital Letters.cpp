#include <iostream>
#include "MyPrint.h"
#include <string>
#include "MyRead.h"
using namespace std;



enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 3 };

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{

	if (WhatToCount == enWhatToCount::All)
	{
		return S1.length();
	}

	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			Counter++;

		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			Counter++;

	}


	return Counter;

}
int main()
{
	string S1 = MyRead::ReadString();

	cout << "\nMethod 1 \n\n";

	cout << "\nString Length: " << S1.length();
	cout << "\nCapital Letters Count= " << MyPrint::CountCapitalLetters(S1);
	cout << "\nSmall Letters Count= " << MyPrint::CountSmallLetters(S1);

	cout << "\n\nMethod 2 \n\n";

	cout << "\nString Length: " << CountLetters(S1);
	cout << "\nCapital Letters Count= " << CountLetters(S1, enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count= " << CountLetters(S1, enWhatToCount::SmallLetters);

	system("pause>0");

}