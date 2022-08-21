#include <iostream>

using namespace std;

class Target
{
public:
	virtual ~Target()
	{
		cout << "~Target()" << endl;
	}

	virtual void Request()
	{
		cout << "Target::Request()" << endl;
	}
};

class Adaptee
{
public:
	virtual ~Adaptee()
	{
		cout << "~Adaptee()" << endl;
	}

	void SpecificRequest()
	{
		cout << "Adaptee::SpecificRequest()" << endl;
	}

};

class Adapter : public Target
{
public:
	virtual ~Adapter()
	{
		cout << "~Adapter()" << endl;
	}

	Adapter(Adaptee *p_adaptee) : m_adaptee(p_adaptee){}

	virtual void Request()
	{
		cout << "Adapter::Request()" << endl;
		m_adaptee->SpecificRequest();
	}

private:
	Adaptee *m_adaptee;
};

void ClientCode(Target *p_target)
{
	p_target->Request();
}

int main()
{
	cout << "BEFORE CHANGES" << endl;
	Target *my_old_target = new Target();
	ClientCode(my_old_target);
	cout << endl;

	cout << "AFTER CHANGES" << endl;
	Adaptee *my_adaptee = new Adaptee();
	Target *my_new_target = new Adapter(my_adaptee);
	ClientCode(my_new_target);
	cout << endl;

	delete my_old_target;
	delete my_adaptee;
	delete my_new_target;

	return 0;
}




