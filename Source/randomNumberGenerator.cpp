#include<iostream>
#include<cstdlib> // for rand() and srand()
#include<ctime> // for time()

using namespace std;

int main()
{
	//print out the maximum value that can be generated
	cout << RAND_MAX << endl;
	
	srand ( time(0) ) ; //set intitial seed value to system clock

	for ( int nCount = 0; nCount < 100 ; nCount += 1 )
	{
		cout << rand() << "\t";
	
		if ((nCount + 1) % 5 == 0)
			cout << endl;
	}
	return 0;
}
