#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Iiterator
{
public:
	virtual	void First() = 0;
	virtual string Next() = 0;
	virtual bool IsDone() = 0;
	virtual string CurrentItem() = 0;
};

class TwitterIterator : public Iiterator
{
private:
	vector<string> _users;
	int _position;
public:
	TwitterIterator(vector<string> users)
	{
		_users = users;
		_position = 0;
	}
	string CurrentItem() override
	{
		return _users[_position];
	}
	void First() override
	{
		_position = 0;
	}
	bool IsDone() override
	{
		return _position >= _users.size();
	}
	string Next() override
	{
		return _users[_position++];
	}
};
class FacebookIterator : public Iiterator
{
private:
	vector<string> _users;
	int _position;
public:
	FacebookIterator(vector<string> users)
	{
		_users = users;
		_position = 0;
	}
	string CurrentItem() override
	{
		return _users[_position];
	}
	void First() override
	{
		_position = 0;
	}
	bool IsDone() override
	{
		return _position >= _users.size();
	}
	string Next() override
	{
		return _users[_position++];
	}
};
class ISocialNetworking
{
public:
	virtual	Iiterator* CreateIterator() = 0;
};
class Twitter : public ISocialNetworking
{
private:
	vector<string> _users;
public:
	Twitter() : _users{ "Kathy", "Lori", "Kristen", "Jamie" } {}
	Iiterator* CreateIterator() override
	{
		return new TwitterIterator(_users);
	}
};
class Facebook : public ISocialNetworking
{
private:
	vector<string> _users;
public:
	Facebook() : _users{ "Mike", "Jason", "Asad", "Sen","Vish","Senthu" } {}
	Iiterator* CreateIterator() override
	{
		return new TwitterIterator(_users);
	}
};
static void PrintUsers(Iiterator* iterate)
{
	iterate->First();
	while (!iterate->IsDone())
	{
		cout << iterate->Next() << endl;
	}
}

int main()
{
	ISocialNetworking* fb = new Facebook();
	ISocialNetworking* tw = new Twitter();

	Iiterator* fbIterator = fb->CreateIterator();
	Iiterator* twIterator = tw->CreateIterator();

	cout << " --- Facebook --- " << endl;
	PrintUsers(fbIterator);
	cout << " --- Twitter --- " << endl;
	PrintUsers(twIterator);

	delete fb;
	delete tw;
	delete fbIterator;
	delete twIterator;
}
