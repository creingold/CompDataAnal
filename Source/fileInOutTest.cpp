/*
For testing input and output capabilities
*/

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(){
	// ofstream is used for writing files
	ofstream fOut("test.dat");

	//Always check if the file was opened properly
	if (!fOut){
		cout << " test.dat could not be opened for writing!" << endl;
		exit(1);
	}

	//Takin in user input
	float number1, number2;
	cout << "What are your two numbers?" << endl;
	cin >> number1 >> number2;

	//Write the numbers to a file
	fOut << number1 << endl << number2 <<endl;

	//Read the numbers back out
	fOut.close();
	
	ifstream fIn("test.dat");

	string str1, str2;
	fIn >> str1 >> str2;

	cout << str1 << " " << str2 << endl;

	return 0;


}
