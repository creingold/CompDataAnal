/*
Craig Reingold
09/04/2015
Gaussian Distribution Generator

This program beings with a function that will generate normal distributions, given a mean and standard deviation.
It will then print out a histogram of the normal distribution generated.

*/

#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstdlib>
#include<ctime>

using namespace std;

srand ( time ( 0 ) );

const double g_pi = 3.1415926;

// ##########################################################

//Edit the section below to adjust the output

const float rangeMin = -10.0;
const float rangeMax = 10.0;
const float binSize = 0.2;
const float numberOfBins = 100;

// ###########################################################


float Normal ( float mean, float stddev ){
	//This function will generate the normal distribution with given mean and standard deviation
	
	float R1;
	R1 = (float) rand() / (float) (RAND_MAX);
	float R2;
	R2 = (float) rand() / (float) (RAND_MAX);

	return mean + std * cos(2*g_pi*R1) * sqrt(-log(R2) );
}

int main{
	//This is where the histogram will be generated

	float hist[numberOfBins] = {0};
	const float mean = 0;
	const float stddev = 2;

	//Filling the histogram
	for ( int i = 0 ; i < 10000 ; i += 1 ){

		float toFill = Normal(mean, stddev);
		for ( int j = rangeMin ; j < rangeMax ; j += 1 ){
			if ( toFill >= j * binSize && toFill < (j + 1)*binSize ){
				hist[j] += 1;
				break;
			}
		}
		
	}



}
