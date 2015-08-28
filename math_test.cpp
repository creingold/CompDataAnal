#include<iostream>

using namespace std;

int main(){
	int x = 3;
	int y , z;

	y = x++;
	z = ++x;

	cout << y << endl;
	cout << z << endl;

	return 0;
}
