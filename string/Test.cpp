#define _CRT_SUCURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(s2, 2, 5);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	s1 = s2;
	string::iterator it1 = s1.begin();
	while (it1 != s1.end()) {
		(*it1)--;
		++it1;
	}

	cout << s1 << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it2 = v.begin();
	while (it2 != v.end()) {
		cout << (*it2) << " " << endl;
		++it2;
	}
	

	return 0;
}