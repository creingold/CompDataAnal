/*
Craig Reingold
10/5/15
Reading Data into a Histogram

This program will 
- Create two 1000-element arrays to hold data histograms
- Create an array to store the buffer and header from the input file
- Declare a pointer that will 'scan' the buffer array using pointer arithmetic
- Read the header and the buffer into an array
- Use the pointer to skip the header data
- Read in the detector number and the deposited energy, and save the energy to an appropriote histogram.
- Repeat 3-5 to read the whole data file, minimizing the number of loops and variables to make the code faster and more memory efficient
- Once the whole input file is read, save the generated histograms into a file in a three column table, bin, hist1 and hist2
- Use plotting software to plot the histograms
*/

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(){
	ifstream dataFile("week6_data.dat");
	if ( !dataFile ){
		cout << "OH NO! WE'VE LOST POWER IN THE MAIN ENGINES! WE'RE GOING DOWN!!!" << endl;
		cout << "Just kidding.  But seriously, I couldn't find the data file. Goodbye." << endl;
		exit(1);
	}

	ofstream histFile("week6_hist.dat");
	if ( !histFile ){
		cout << "OH NO! WE'VE LOST POWER IN THE MAIN ENGINES! WE'RE GOING DOWN!!!" << endl;
		cout << "Got ya again!  I really can't open a file to store the results though ... so ... bye felicia ... " << endl;
		exit(1);
	}

	// Declaring histogram arrays to store the detector data

	int detector0[1000] = {0};
	int detector1[1000] = {0};

	// Declaring an array to store the buffer

	float buffer[210];

	int iDetector;
	float energy;

	// While we haven't reached the end of the file ...
	while ( !dataFile.eof() ){

	// Reading in the buffer
		for ( int c = 0 ; c < 210 ; c++ ){
			dataFile >> buffer[c];
		}

		for ( int d = 10 ; d < 210 ; d += 2 ){
			iDetector = (int) buffer[d];
			energy = buffer[d+1];


			if ( iDetector == 0 ){
				for ( int h = 0 ; h < 1000 ; h++){
					if ( energy >=  0.5 * h and energy  < 0.5*(h + 1) ){
						detector0[h] += 1;
					}
				}

			}

			if ( iDetector == 1 ){
				for ( int h = 0 ; h < 1000 ; h++){
					if ( energy >=  0.5 * h and energy  < 0.5*(h + 1) ){
						detector1[h] += 1;
					}
				}
			}


		}
	}

	dataFile.close();

	// Writing to the output file

	for ( int i = 0 ; i < 1000 ; i ++ ){
		histFile << i << '\t' << detector0[i] << '\t' << detector1[i] << endl;
	}


	histFile.close();

	return 0;
}
