#include <iostream>
#include <string>
using namespace std;




void PrintWordsFromAAAtoZZZ()
{
	cout << "\n";
	string Word = "";

	for (int Counter1 = 65; Counter1 <= 90; Counter1++)
	{


		for (int Counter2 = 65; Counter2 <= 90; Counter2++)
		{
			for (int Counter3 = 65; Counter3 <= 90; Counter3++)
			{
				Word += char(Counter1);
				Word += char(Counter2);
				Word += char(Counter3);

				cout << Word << endl;

				Word = "";
			}


		}
		
		cout << "\n----------------------\n";
	}


}





int main()
{

	PrintWordsFromAAAtoZZZ();



	return 0;

}
