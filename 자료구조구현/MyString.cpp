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

// �ʿ���� ������.(-)
//MyString MyString::operator-(const MyString& ref)
//{
//	// ������ ���� ũ�⸦ �ٽ� �Ҵ��Ѵ�.
//	char* ac2 = new char[len];
//	// ref.len�� len�� �� ���� �����Ѵ�.
//	int len2 = len - ref.len;
//	// ac2�� ref.ab�� ���ڿ��� ���� �ڵ��. (if���� �ۼ��ؼ� �ؾ��Ѵ�.)
//	if (sizeof(ab) > sizeof(ref.ab)) {
//		strcpy_s(ac2, len, ab);
//	}
//	if (sizeof(ref.ab) > sizeof(ab)) {
//		strcpy_s(ac2, ref.len, ref.ab);
//	}
//	// ac�� �ٽ� �Ҵ�޾��ش�.
//	char* ac = new char[len2 - 1];
//	// ac2�� delete�Ѵ�.
//	delete[] ac2;
//	// �ٽ� �����ڷ� �����.
//	MyString temp(ac);
//	delete[] ac;
//	return temp;
//}