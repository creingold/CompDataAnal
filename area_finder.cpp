/*
 * Craig Reingold
 * 8/26/15
 * Area Finder
 */

#include <iostream>

using namespace std;

int multiply(int length, int width)
{
	int area;
	area = length * width;
	return area;
}

int main()
{
	int length;
	int width;

	cout << "What is the length of your rectangle?" << endl;
	cin >> length;

	cout << "what is the width of your rectangle?" << endl;
	cin >> width;

	int area = multiply(length, width);

	cout << "The area of your rectangle is " << area << endl;

	return 0;
}
