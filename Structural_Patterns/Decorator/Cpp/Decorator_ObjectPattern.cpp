#include <iostream>

using namespace std;

class Component
{
public:
	virtual ~Component()
	{
		cout << "~Component()" << endl;
	}

	virtual void Operation() = 0;
};

class ConcreteComponent : public Component
{
public:
	~ConcreteComponent()
	{
		cout << "~ConcreteComponent()" << endl;
	}

	void Operation() override
	{
		cout << "ConcreteComponent::Operation()" << endl;
	}
};

class Decorator : public Component
{
public:
	virtual ~Decorator()
	{
		cout << "~Decorator()" << endl;
	}

	Decorator(Component *p_Component) : m_Component(p_Component) {}

	virtual void Operation() override
	{
		m_Component->Operation();
	}

private:
	Component *m_Component;
};

class ConcreteDecoratorA : public Decorator
{
public:
	~ConcreteDecoratorA()
	{
		cout << "~ConcreteDecoratorA()" << endl;
	}

	ConcreteDecoratorA(Component *p_Component) : Decorator(p_Component) {}

	void Operation() override
	{
		Decorator::Operation();
		AddedBehavior();
	}

	void AddedBehavior()
	{
		cout << "ConcreteDecoratorA::AddedBehavior" << endl;
	}
};

class ConcreteDecoratorB : public Decorator
{
public:
	~ConcreteDecoratorB()
	{
		cout << "~ConcreteDecoratorB()" << endl;
	}

	ConcreteDecoratorB(Component *p_Component) : Decorator(p_Component) {}

	void Operation() override
	{
		Decorator::Operation();
		AddedBehavior();
	}

	void AddedBehavior()
	{
		cout << "ConcreteDecoratorB::AddedBehavior" << endl;
	}
};

void ClientCode(Component *p_Component)
{
	p_Component->Operation();
}

int main()
{
	Component *myConcreteComponent = new ConcreteComponent();
	Component *myConcreteDecoratorA = new ConcreteDecoratorA(myConcreteComponent);
	Component *myConcreteDecoratorB = new ConcreteDecoratorB(myConcreteDecoratorA);

	cout << "BEFORE DECORATORS" << endl;
	ClientCode(myConcreteComponent);
	cout << endl;

	cout << "AFTER DECORATORS" << endl;
	ClientCode(myConcreteDecoratorB);
	cout << endl;

	delete myConcreteComponent;
	delete myConcreteDecoratorA;
	delete myConcreteDecoratorB;

	return 0;
}


