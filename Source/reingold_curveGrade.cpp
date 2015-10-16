/*
Craig Reingold
10/14/15
Grade Curver Program

This program does the following

- Writes a function that returns a random number in the range 0 to 100 with a Gaussian distribution with user specified mean and sigma
- Use the function to generate a vector of students' final grades.  nStudents = 100, mean = 75, sigma = 25
- Find the highest, lowest, and average grade.  Use the algorithm function when possible
- The letter grade scale is defined as follows:
	101 > A >= 94
	94 > A- >= 91
	91 > B+ >= 88
	88 > B >= 82
	82 > B- >= 79
	79 > C+ >= 76
	76 > C >= 70
	70 > C- >= 67 
	67 > D >= 64
	64 > F
  Find the number of students that obtained a given letter grade ( use count_if function )
- Create a copy of the grade vector, called curvedGrades
- If the number of students that obtained a grade C+ or lower is greater than the number of students that obtained grades B and higher, curve the result by shifting each point grade by 2 points.  Use the curvedGrades to store the new grades
- Repeat the previous step in the loop until the number of students with grades lower or equal to C+ is not smaller than the number of students with grades greater or equal to B
- Find the highest, lowest, and average curved grade.  Use algorithm functions when possible
- Print out the number of students that received a given letter grade before and after curving.  Print out the lowest, highest and average curved grade.

*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<math.h>
#include<ctime>
#include<algorithm>

using namespace std;

const double g_pi = 3.1415926;

float Normal ( float mean , float stddev ){
	// Defining the normal distribution

	float R1;
	R1 = (float) rand() / (float) (RAND_MAX);
	float R2;
	R2 = (float) rand() / (float) (RAND_MAX);

	return mean + stddev * cos( 2*g_pi*R1 ) * sqrt(-log(R2) );
}

float pseudoRandNumGen(){
	// This function will generate a random number in the range 0 to 100
	float randNum = 101;
	while ( randNum >= 100 ){
		randNum = Normal ( 75 , 25 );

	}

	return randNum;
}

// Defining the letter grades using functions

bool uGotA ( float grade ) { return (grade >= 94); }
bool uGotAm ( float grade ) { return (grade >= 91 and grade < 94); }
bool uGotBp ( float grade ) { return (grade >= 88 and grade < 91); }
bool uGotB ( float grade ) { return (grade >= 82 and grade < 88); }
bool uGotBm ( float grade ) { return (grade >= 79 and grade < 82); }
bool uGotCp ( float grade ) { return (grade >= 76 and grade < 79); }
bool uGotC ( float grade ) { return (grade >= 70 and grade < 76 ); }
bool uGotCm ( float grade ) { return (grade >= 67 and grade < 70); }
bool uGotD ( float grade ) { return (grade >= 64 and grade < 67); }
bool uGotF ( float grade ) { return (grade < 64); }




int main(){

	srand ( time (0) );

	vector<float> finalGrades;
	
	// Filling the finalGrades vector

	for ( int nStudents = 0 ; nStudents < 100 ; nStudents++ ){
		finalGrades.push_back(pseudoRandNumGen());
	}

	// Finding the maximum and minimum elements

	cout << "Highest Grade: " << *max_element( finalGrades.begin() , finalGrades.end() ) << endl;
	cout << "Lowest Grade: " << *min_element( finalGrades.begin() , finalGrades.end() ) << endl;

	// Calculating the mean

	float sumOfGrades;

	for ( vector<float>::iterator c = finalGrades.begin() ; c != finalGrades.end() ; c++ ){
		sumOfGrades += *c;
	}

	float averageGrade = sumOfGrades / (float) finalGrades.size();
	cout << "Average Grade: " << averageGrade << endl;


	// Counting the uncurved letter grades

	int numA = count_if ( finalGrades.begin() , finalGrades.end() , uGotA );
	int numAm = count_if ( finalGrades.begin() , finalGrades.end() , uGotAm );
	int numBp = count_if ( finalGrades.begin() , finalGrades.end() , uGotBp );
	int numB = count_if ( finalGrades.begin() , finalGrades.end() , uGotB );
	int numBm = count_if ( finalGrades.begin() , finalGrades.end() , uGotBm );
	int numCp = count_if ( finalGrades.begin() , finalGrades.end() , uGotCp );
	int numC = count_if ( finalGrades.begin() , finalGrades.end() , uGotC );
	int numCm = count_if ( finalGrades.begin() , finalGrades.end() , uGotCm );
	int numD = count_if ( finalGrades.begin() , finalGrades.end() , uGotD );
	int numF = count_if ( finalGrades.begin() , finalGrades.end() , uGotF );


	cout << "Number of A's : " << numA << endl;
	cout << "Number of A-'s : " << numAm << endl;
	cout << "Number of B+'s : " << numBp << endl;
	cout << "Number of B's : " << numB << endl;
	cout << "Number of B-'s : " << numBm << endl;
	cout << "Number of C+'s : " << numCp << endl;
	cout << "Number of C's : " << numC << endl;
	cout << "Number of C-'s : " << numCm << endl;
	cout << "Number of D's : " << numD << endl;
	cout << "Number of F's : " << numF << endl;

	// Making a copy of the grades called 'Curved Grades'

	vector<float> curvedGrades(finalGrades.begin() , finalGrades.end() );

	// Actually curving
	while ( numCp + numC + numCm + numD + numF >= numA + numAm + numBp + numB +numBm ){
		for ( int d = 0 ; d < curvedGrades.size() ; d ++ ){
			curvedGrades.at(d) += 2;
		}
		numA = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotA );
		numAm = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotAm );
		numBp = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotBp );
		numB = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotB );
		numBm = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotBm );
		numCp = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotCp );
		numC = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotC );
		numCm = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotCm );
		numD = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotD );
		numF = count_if ( curvedGrades.begin() , curvedGrades.end() , uGotF );
		cout << "Didn't find it yet" << endl;
	}

	// Finding the maximum and minimum elements

	cout << "Highest Grade: " << *max_element( curvedGrades.begin() , curvedGrades.end() ) << endl;
	cout << "Lowest Grade: " << *min_element( curvedGrades.begin() , curvedGrades.end() ) << endl;

	// Calculating the mean

	float sumOfGradesCurved;

	for ( vector<float>::iterator c = curvedGrades.begin() ; c != curvedGrades.end() ; c++ ){
		sumOfGradesCurved += *c;
	}

	float averageGradeCurve = sumOfGradesCurved / (float) curvedGrades.size();
	cout << "Average Curved Grade: " << averageGradeCurve << endl;



	cout << "Number of A's after curve: " << numA << endl;
	cout << "Number of A-'s after curve: " << numAm << endl;
	cout << "Number of B+'s after curve: " << numBp << endl;
	cout << "Number of B's after curve: " << numB << endl;
	cout << "Number of B-'s after curve: " << numBm << endl;
	cout << "Number of C+'s after curve: " << numCp << endl;
	cout << "Number of C's after curve: " << numC << endl;
	cout << "Number of C-'s after curve: " << numCm << endl;
	cout << "Number of D's after curve: " << numD << endl;
	cout << "Number of F's after curve: " << numF << endl;

	return 0;
}
