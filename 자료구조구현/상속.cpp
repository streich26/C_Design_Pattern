#include <iostream>
using namespace std;
class Player
{
public:
    char name[25];
    int movespeed = 0;
    virtual void Move() {
        cout << "Player Move" << endl;
    }  //�����Լ�
};
class Hero : public Player
{
public:
    void Move() { cout << "Hero Move" << endl; }
};
class Enemy : public Player
{
public:
    void Move() { cout << "Enemy Move" << endl; }
};
//�ϳ��� ������� ����
int main()
{
    Player* player[2] =
    { new Hero(), new Enemy() };
    player[0]->Move();
    player[1]->Move();
}
