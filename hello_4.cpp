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

int GetAge()
{

	cout << "How old are you?" << endl;
	int age;
	cin >> age;
	return age;

}

int GetAgeMonth(int age)
{
	return age * 12;
}

int main()
{
	string name = GetName();
	SayHello(name);
	int age = GetAge();
	cout << name << " is " << age << " years old, that is " <<
	   GetAgeMonth(age) << " months." << endl;

	return 0;
}
