#include<iostream>
#include<iomanip> // for set precision()

using namespace std;

int main()
{
	cout << setprecision(16);
	//show 16 digits

	float fValue;
	fValue = 1.222222222222222222222222222222222222222f;

	cout << fValue << endl;
	fValue= 111.222222222222222222222222222222222222222f;

	cout << fValue << endl;
	fValue = 111111.222222222222222222222222222222222f;

	double dValue = 111111.22222222222222222222222222222222222;

	double dValue2 = 0.1;


	
	cout << fValue << endl;

	cout << dValue << endl;

	cout << setprecision(17) << dValue2 << endl;

	double dSum = dValue2 + dValue2  + dValue2 + dValue2 + dValue2 + dValue2 + dValue2 + dValue2 + dValue2 + dValue2;
	
	cout << dSum << endl;

	return 0;
}
