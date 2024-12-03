#include<stdio.h>
#include<thread>
using namespace std;

bool flag[2] = { false, false };
int turn = 0;
int cnt;

void ProcessP0()
{
	while (true)
	{
		flag[0] = true;
		turn = 1;
		while (flag[1] && turn == 1);
		if (cnt >= 10) {     // cnt가 10 이상이면 종료
			flag[1] = false;
			break;
		}
		cnt++;
		printf("P0 : %d\n", cnt);
		flag[0] = false;

	}
}
void ProcessP1()
{
	while (true)
	{
		flag[1] = true;
		turn = 0;
		while (flag[0] && turn == 0);
		if (cnt >= 10) {     // cnt가 10 이상이면 종료
			flag[1] = false;
			break;
		}
		cnt++;
		printf("P1 : %d \n", cnt);
		flag[1] = false;

	}
}
int main()
{
	thread t1(ProcessP0);
	thread t2(ProcessP1);

	t1.join();
	t2.join();


	return 0;
}
// 실행결과 
//P0 : 1
//P1 : 2
//P0 : 3
//P1 : 4
//P0 : 5
//P1 : 6
//P0 : 7
//P1 : 8
//P0 : 9
//P1 : 10
//