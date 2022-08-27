#include <iostream>

using namespace std;

class Implementor
{
public:
	virtual ~Implementor()
	{
		cout << "~Implementor()" << endl;
	}

	virtual void OperationImplementor() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
	~ConcreteImplementorA()
	{
		cout << "~ConcreteImplementorA()" << endl;
	}

	void OperationImplementor() override
	{
		cout << "ConcreteImplementorA::OperationImplementor()" << endl;
	}
};

class ConcreteImplementorB : public Implementor
{
public:
	~ConcreteImplementorB()
	{
		cout << "~ConcreteImplementorB()" << endl;
	}

	void OperationImplementor() override
	{
		cout << "ConcreteImplementorB::OperationImplementor()" << endl;
	}
};

class Abstraction
{
public:
	virtual ~Abstraction()
	{
		cout << "~Abstraction()" << endl;
	}

	Abstraction(Implementor *p_ImplementorObject) : imp(p_ImplementorObject) {}

	virtual void Operation()
	{
		cout << "Abstraction::Operation()" << endl;
		imp->OperationImplementor();
	}

protected:
	Implementor *imp;
};

class RefinedAbstraction : public Abstraction
{
public:
	~RefinedAbstraction()
	{
		cout << "~RefinedAbstraction()" << endl;
	}

	RefinedAbstraction(Implementor *p_ImplementorObject) : Abstraction(p_ImplementorObject) {}

	void Operation() override
	{
		cout << "RefinedAbstraction::Operation()" << endl;
		imp->OperationImplementor();
	}
};

void ClientCode(Abstraction *p_Abstraction)
{
	p_Abstraction->Operation();
}

int main()
{
	Implementor *myImplementor;
	Abstraction *myAbstraction;

	myImplementor = new ConcreteImplementorA();
	myAbstraction = new Abstraction(myImplementor);
	ClientCode(myAbstraction);
	cout << endl;
	delete myImplementor;
	delete myAbstraction;

	cout << endl << "****************************" << endl << endl;

	myImplementor = new ConcreteImplementorB();
	myAbstraction = new RefinedAbstraction(myImplementor);
	ClientCode(myAbstraction);
	cout << endl;
	delete myImplementor;
	delete myAbstraction;

	return 0;
}




