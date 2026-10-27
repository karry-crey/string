#define _CRT_SUCURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test_string() {
	string s1;
	const string s2("hello world");
	string s3(s2);
	string s4(s2, 2, 5);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	//[begin,end）
	s1 = s2;
	string::iterator it1 = s1.begin();
	while (it1 != s1.end()) {
		(*it1)--;
		++it1;
	}

	cout << s1 << endl;

	string::reverse_iterator it3 = s1.rbegin();
	while (it3 != s1.rend()) {
		cout << *it3 << endl;
		++it3;
	}
	cout << endl;


	for (auto ch : s1) {
		cout << ch << " ";
	}
	cout << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it2 = v.begin();
	while (it2 != v.end()) {
		cout << (*it2) << " " << endl;
		++it2;
	}
}


void test_string2() {
	string s1("123456");
	cout << s1.max_size() << endl;
	//均不包含'\0'  strlen()也是
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void test_string3() {
	string s2;
	size_t old = s2.capacity();
	//缩容要重新开辟空间，一般不缩容
	//缩容是以时间换空间
	cout << "capacity:" << old << endl;
	for (size_t i = 0; i < 100; i++) {
		s2.push_back('x');
		if (s2.capacity() != old) {
			cout << "capacity:" << s2.capacity() << endl;
			old = s2.capacity();
		}
	}
}

void test_string4() {
	string s1("123456");
	cout <<"size:"<< s1.size() << endl;
	cout <<"capacity:"<< s1.capacity() << endl;

	//确定知道需要多少空间，提前开辟好，避免扩容，提高效率
	s1.reserve(100);
	cout << "size:" << s1.size() << endl;
	cout << "capacity:" << s1.capacity() << endl;
}
void test_string5() {
	string s2("123456");
	s2.resize(10);
	s2.push_back('x');
}

void test_string6() {
	string s1("123456");
	s1[2]++;
	cout << s1 << endl;
	s1.at(0)--;
	cout << s1 <<endl;
	char c1 = s1.at(3);
	cout << c1 << endl;
}

void test_string7() {
	string s1("hello world");
	//s1.push_back(' ');
	//s1.append("hello k");
	//s1.append(10, 'x');
	//s1 += ' ';
	//s1 += "hello world";
	s1.assign(10, 'y');
	cout << s1 << endl;
	string s2("hello");

	//insert谨慎使用,底层数据挪动，效率低下
	s2.insert(0, "x");
	cout << s2 << endl;
	//erase谨慎使用
	string s3("hello world");
	s3.erase(5, 1);
	cout << s3 << endl;
	s3.erase(5);
	cout << s3 << endl;
	//replace谨慎使用
	string s4("hello world");
	s4.replace(5, 1, "_");
	cout << s4 << endl;

	string s5("hello world hello world1");
	//	size_t pos = s5.find(" ");
	//	while (pos != string::npos) {
	//		s5.replace(pos, 1, "%%");
	//		pos = s5.find(" ",pos+2);
	//	}
	//	cout << s5 << endl;
	//}
	string s6;
	s6.reserve(s5.size());
	for (auto ch : s5) {
		if (ch == ' ')
			s6 += "%%";
		else
			s6 += ch;
	}

}


int main() {
	try {
		test_string7();
	}
	catch(const exception& e){
		cout << e.what() << endl;
	}
	return 0;
}