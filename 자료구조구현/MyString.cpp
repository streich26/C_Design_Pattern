#include "MyString.h"
using namespace std;



MyString::MyString(const char* b)
{
	len = strlen(b) + 1;
	ab = new char[len];
	strcpy_s(ab, len, b);
}
MyString::MyString(const MyString& s)
{
	len = s.len; ab = new char[len]; strcpy_s(ab, len, s.ab);
}

MyString MyString::operator+ (const MyString& ref)
{
	char* ac = new char[len + ref.len - 1];
	int newlen = len + ref.len - 1;
	strcpy_s(ac,newlen, ab); strcat_s(ac, newlen, ref.ab);
	MyString temp(ac);
	delete[] ac;
	return temp;
}

MyString& MyString::operator=(const MyString& ref)
{
	if (ab != NULL) delete[] ab;
	len = ref.len;	ab = new char[len]; strcpy_s(ab,len, ref.ab);
	return *this;
}
MyString::~MyString() {
	if (ab != NULL) delete[] ab;
}

bool MyString::operator==(const MyString& ref) {
	return strcmp(ab, ref.ab) ? false : true;
}

ostream& operator<<(ostream& os, const MyString& s) {
	os << s.ab;
	return os;
}
istream& operator>> (istream& is, MyString& s) {
	char str[100];  is >> str;  s = MyString(str);
	return is;
}

int main(void)
{
	MyString s("asdf");
	MyString s1("Dfdsfds");
	MyString s2 = s1 + s;
	cout << s2 << endl;
	bool a = s == s;
	cout << a;
}

// 필요없는 연산자.(-)
//MyString MyString::operator-(const MyString& ref)
//{
//	// 빼려는 둘의 크기를 다시 할당한다.
//	char* ac2 = new char[len];
//	// ref.len과 len을 뺀 값을 저장한다.
//	int len2 = len - ref.len;
//	// ac2에 ref.ab의 문자열을 뺴는 코드다. (if문을 작성해서 해야한다.)
//	if (sizeof(ab) > sizeof(ref.ab)) {
//		strcpy_s(ac2, len, ab);
//	}
//	if (sizeof(ref.ab) > sizeof(ab)) {
//		strcpy_s(ac2, ref.len, ref.ab);
//	}
//	// ac를 다시 할당받아준다.
//	char* ac = new char[len2 - 1];
//	// ac2를 delete한다.
//	delete[] ac2;
//	// 다시 생성자로 만든다.
//	MyString temp(ac);
//	delete[] ac;
//	return temp;
//}