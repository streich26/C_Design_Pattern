#include <iostream>

using namespace std;

void guguDan()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout <<i<<" X "<< j <<" : "<< i * j << endl;
		}
	}
}
int main()
{
	guguDan();
}