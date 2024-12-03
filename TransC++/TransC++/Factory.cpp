#include <iostream>

using namespace std;
class Product
{
public:
	virtual ~Product() {};
	virtual string Name() const = 0;
	virtual string Date() const = 0;
};
class ConcreteProduct1 : public Product
{
public:
	string Name()const override
	{
		return " Product1";
	}
	string Date()const override
	{
		return " 2021.01.02";
	}

};
class ConcreteProduct2 : public Product
{
public:
	string Name()const  override
	{
		return "Product2";
	}
	string Date()const override
	{
		return "2022.10.24";
	}
};
class Creater {
public:
	virtual ~Creater() {};
	virtual Product* FactoryMethod() const = 0;
	string SomeCreate() const {
		Product* product = this->FactoryMethod();
		string result = "Creator: The same creator's code has just worked wit" + product->Name()+ product->Date();
		delete product;
		return result;
	}

};
class ConcreteCreator1 : public Creater {
public:
	Product* FactoryMethod() const override {
		return new ConcreteProduct1();
	}
};
class ConcreteCreator2 : public Creater {
public:
	Product* FactoryMethod() const override {
		return new ConcreteProduct2();
	}
};

void Client(const Creater& creater)
{
	cout << "Client" << creater.SomeCreate() << endl;
}




int main()
{
	cout << "App" << endl;
	Creater* creater = new ConcreteCreator1();
	Creater* creater2 = new ConcreteCreator2();

	cout << creater->SomeCreate() << endl;
	cout << creater2->SomeCreate() << endl;
	delete creater;
	delete creater2;
	return 0;
}