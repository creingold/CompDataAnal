/*
 * Hello world example 3
 * 08/26/2015
 * Craig Reingold
 */

#include <iostream>

using namespace std;

void SayHello(string name)
{

	cout << "Hello " << name << endl;

}

string GetName()
{
	cout << "What is your name?" << endl;
	string name;
	cin >> name;
	return name;
}


int main()
{
	string name = GetName();
	SayHello(name);
	return 0;
}
