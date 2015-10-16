/*
Craig Reingold
10/7/15
Vector 1 Practice

Just practicing using vectors.
*/

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int main(){

	vector<int> v1;
	vector<int> v2;

	// Filling and Appending the v1 vector

	for ( int i = 0 ; i < 10 ; i ++ ){
		v1.push_back(i);
		v2.push_back(10+i);
	}

	for ( int j = 0 ; j < v2.size() ; j++ ){
		v1.push_back(v2[j]);
	}

	for ( int k = 0 ; k < v1.size() ; k++ ){
		v1.at(k) = v1.at(k)*v1.at(k);
		cout << v1.at(k) << endl;
	}

	// Doing the things with the even and odd vectors

	vector<int> v3;

	for ( vector<int>::iterator l = v1.begin() ; l != v1.end() ; l++ ){
		if ( *l % 2 != 0 ){
			v3.push_back(*l);
		}
	}

	for ( vector<int>::iterator m = v1.begin() ; m != v1.end() ; m++ ){
		if ( *m % 2 == 0 ){
			v1.erase(m);
			m += (-1);
		}
	}

	// Declaring iterators to run over both of the thingys.

	vector<int>::iterator n = v1.begin();
	vector<int>::iterator nn = v3.begin();

	for ( n ; n < v1.end() ; n++ ){
		if ( *n != *nn ){
			cout << "You broke it " << endl;
			exit(1);
		}	
		nn++;	
	}
	cout << "Victory!" << endl;

	for ( vector<int>::iterator p = v3.end() ; p != v3.begin() ; p += (-1) ){
		cout << *(p-1) << endl;
	}

	return 0;

}
