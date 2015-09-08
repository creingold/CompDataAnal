#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	int hist[100] = {0}; //initialize the array for the histogram
	int randNumber;

	srand ( time(0) ) ; //set intitial seed value to the system clock

	for (int nCounter = 0 ; nCounter < 10000 ; nCounter += 1 )
	{	
		//generate a number in the range 0 to 1000
		randNumber = rand() % 1000;

		//scan through the array and increment the histogram "bin"
		for ( int ii = 0; ii < 100 ; ii += 1 )
		{
			//histogram binned to 10
			if ( randNumber >= ii *10 && randNumber < (ii+1)*10 )
			{
				hist[ii] += 1;
				//debug: check if the number is saved in the bin we want
				//cout << randNumber << " " << ii << endl;
				break;
			}
		}
	}

	cout << hist << endl; //this didn't work, but I am moving on anyway

	return 0;
}
