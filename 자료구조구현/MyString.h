#pragma once
#include <iostream>
using namespace std;
#define _CRT_NONSTDC_NO_WARNINGS
class MyString {
private:
	char* ab;
	int len;
public:
		MyString(const char* b);
		MyString(const MyString& s);
		friend ostream& operator<< (ostream& os, const MyString& s);
		friend istream& operator>> (istream& is, MyString& s);
		MyString& operator=(const MyString& ref);
		MyString operator+(const MyString& ref);
		//MyString operator-(const MyString& ref);

		bool operator==(const MyString& ref);
		~MyString();
};




