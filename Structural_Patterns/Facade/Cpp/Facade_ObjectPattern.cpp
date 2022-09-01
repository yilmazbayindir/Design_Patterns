#include <iostream>

using namespace std;

class SubSystemA
{
public:
	~SubSystemA()
	{
		cout << "~SubSystemA()" << endl;
	}

	void Operation()
	{
		cout << "SubSystemA::Operation()" << endl;
	}
};

class SubSystemB
{
public:
	~SubSystemB()
	{
		cout << "~SubSystemB()" << endl;
	}

	void Operation()
	{
		cout << "SubSystemB::Operation()" << endl;
	}
};

class SubSystemC
{
public:
	~SubSystemC()
	{
		cout << "~SubSystemC()" << endl;
	}

	void Operation()
	{
		cout << "SubSystemC::Operation()" << endl;
	}
};

class Facade
{
public:
	~Facade()
	{
		cout << "~Facade()" << endl;

		delete m_SubSystemA;
		delete m_SubSystemB;
		delete m_SubSystemC;
	}

	Facade()
	{
		m_SubSystemA = new SubSystemA();
		m_SubSystemB = new SubSystemB();
		m_SubSystemC = new SubSystemC();
	}

	void Operation1()
	{
		cout << "Facade::Operation1()" << endl;

		m_SubSystemA->Operation();
		m_SubSystemB->Operation();
	}
	void Operation2()
	{
		cout << "Facade::Operation2()" << endl;

		m_SubSystemC->Operation();
	}
private:
	SubSystemA *m_SubSystemA;
	SubSystemB *m_SubSystemB;
	SubSystemC *m_SubSystemC;
};

void ClientCode(Facade *p_Facade)
{
	p_Facade->Operation1();
	cout << endl;
	p_Facade->Operation2();
}

int main()
{
	Facade *myFacade = new Facade();

	ClientCode(myFacade);
	cout << endl;

	delete myFacade;

	return 0;
}


