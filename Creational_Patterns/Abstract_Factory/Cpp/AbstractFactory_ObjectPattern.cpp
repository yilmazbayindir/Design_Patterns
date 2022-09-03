#include <iostream>

using namespace std;

class AbstractProductA
{
public:
	virtual ~AbstractProductA()
	{
		cout << "~AbstractProductA()" << endl;
	}

	virtual void GiveInfo() = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
	~ConcreteProductA1()
	{
		cout << "~ConcreteProductA1()" << endl;
	}

	void GiveInfo() override
	{
		cout << "ConcreteProductA1::GiveInfo()" << endl;
	}
};

class ConcreteProductA2 : public AbstractProductA
{
public:
	~ConcreteProductA2()
	{
		cout << "~ConcreteProductA2()" << endl;
	}

	void GiveInfo() override
	{
		cout << "ConcreteProductA2::GiveInfo()" << endl;
	}
};

class AbstractProductB
{
public:
	virtual ~AbstractProductB()
	{
		cout << "~AbstractProductB()" << endl;
	}

	virtual void GiveInfo() = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
public:
	~ConcreteProductB1()
	{
		cout << "~ConcreteProductB1()" << endl;
	}

	void GiveInfo() override
	{
		cout << "ConcreteProductB1::GiveInfo()" << endl;
	}
};

class ConcreteProductB2 : public AbstractProductB
{
public:
	~ConcreteProductB2()
	{
		cout << "~ConcreteProductB2()" << endl;
	}

	void GiveInfo() override
	{
		cout << "ConcreteProductB2::GiveInfo()" << endl;
	}
};

class AbstractFactory
{
public:
	virtual ~AbstractFactory()
	{
		cout << "~AbstractFactory()" << endl;
	}

	virtual AbstractProductA *CreateProductA() = 0;
	virtual AbstractProductB *CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
	~ConcreteFactory1()
	{
		cout << "~ConcreteFactory1()" << endl;
	}

	AbstractProductA *CreateProductA() override
	{
		return new ConcreteProductA1();
	}

	AbstractProductB *CreateProductB() override
	{
		return new ConcreteProductB1();
	}
};

class ConcreteFactory2 : public AbstractFactory
{
public:
	~ConcreteFactory2()
	{
		cout << "~ConcreteFactory2()" << endl;
	}

	AbstractProductA *CreateProductA() override
	{
		return new ConcreteProductA2();
	}

	AbstractProductB *CreateProductB() override
	{
		return new ConcreteProductB2();
	}
};

void ClientCode(AbstractFactory *p_AbstractFactory, AbstractProductA *p_AbstractProductA, AbstractProductB *p_AbstractProductB)
{
	p_AbstractProductA = p_AbstractFactory->CreateProductA();
	p_AbstractProductB = p_AbstractFactory->CreateProductB();

	p_AbstractProductA->GiveInfo();
	p_AbstractProductB->GiveInfo();

	cout << endl;

	delete p_AbstractProductA;
	delete p_AbstractProductB;
}

int main()
{
	AbstractFactory *myAbstractFactory = nullptr;
	AbstractProductA *myAbstractProductA = nullptr;
	AbstractProductB *myAbstractProductB = nullptr;

	myAbstractFactory = new ConcreteFactory1();
	ClientCode(myAbstractFactory, myAbstractProductA, myAbstractProductB);
	delete myAbstractFactory;

	cout << "---------------------------------------" << endl;

	myAbstractFactory = new ConcreteFactory2();
	ClientCode(myAbstractFactory, myAbstractProductA, myAbstractProductB);
	delete myAbstractFactory;

	return 0;
}


