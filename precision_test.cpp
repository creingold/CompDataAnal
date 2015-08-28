/** Using this code to determine the precision of float addition

**/

#include<iostream>

using namespace std;

int main()
{
	float fVal1 = 1.345f;

	float fVal2 = 1.123f;

	float fTotal = fVal1 + fVal2; //should be 2.468

	if ( fTotal == 2.468 )
		{ cout << "fTotal is 2.468" << endl; }	
	else {
		cout << "fTotal is not 2.468" <<  endl;
	}

	cout << 5u - 10 << endl;

	return 0;
}
