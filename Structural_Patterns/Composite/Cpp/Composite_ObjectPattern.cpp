#include <iostream>
#include <list>

using namespace std;

class Component
{
protected:
	int m_id;

public:
	virtual ~Component()
	{
		cout << "~Component" << endl;
	}

	Component(int p_id) : m_id(p_id) {}

	virtual void Add(Component *p_Component) {}
	virtual void Remove(Component *p_Component) {}
	virtual void Operation() = 0;
};

class Composite : public Component
{
public:
	~Composite()
	{
		cout << "~Composite" << endl;
	}

	Composite(int p_id) : Component(p_id){}

	void Add(Component *p_Component) override
	{
		m_children.push_back(p_Component);
	}

	void Remove(Component *p_Component) override
	{
		m_children.remove(p_Component);
	}

	void Operation() override
	{
		cout << "Composite(ID:" << m_id << ")::Operation()" << endl;
		for(Component *child : m_children)
		{
			child->Operation();
		}
	}

private:
	list<Component *> m_children;
};

class Leaf1 : public Component
{
public:
	~Leaf1()
	{
		cout << "~Leaf1" << endl;
	}

	Leaf1(int p_id) : Component(p_id) {}

	void Operation() override
	{
		cout << "Leaf1(ID:" << m_id << ")::Operation()" << endl;
	}
};

class Leaf2 : public Component
{
public:
	~Leaf2()
	{
		cout << "~Leaf2" << endl;
	}

	Leaf2(int p_id) : Component(p_id) {}

	void Operation() override
	{
		cout << "Leaf2(ID:" << m_id << ")::Operation()" << endl;
	}
};

void ClientCode(Component *p_Component)
{
	p_Component->Operation();
}

int main()
{
	Component *leaf1 = new Leaf1(11);
	Component *leaf2 = new Leaf2(21);
	Component *leaf3 = new Leaf1(22);
	Component *leaf4 = new Leaf1(23);

	Component *composite1 = new Composite(10); //root
	Component *composite2 = new Composite(20);

	composite1->Add(leaf1);
	composite1->Add(composite2);
	composite2->Add(leaf2);
	composite2->Add(leaf3);
	composite2->Add(leaf4);
	ClientCode(composite1);
	cout << endl;

	composite2->Remove(leaf3);
	ClientCode(composite1);
	cout << endl;

	delete leaf1;
	delete leaf2;
	delete leaf3;
	delete leaf4;
	delete composite1;
	delete composite2;

	return 0;
}




