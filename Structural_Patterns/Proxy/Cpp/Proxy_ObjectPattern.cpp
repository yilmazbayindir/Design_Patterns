//This is an example of "virtual proxy". 
//As you know, a virtual proxy creates expensive objects on demand.

#include <iostream>

using namespace std;

class Subject
{
public:
	virtual ~Subject()
	{
		cout << "~Subject()" << endl;
	}

	virtual void Request() = 0;
};

class RealSubject: public Subject
{
public:
	~RealSubject()
	{
		cout << "~RealSubject()" << endl;
	}

	void Request() override
	{
		cout << "RealSubject::Request()" << endl;
	}
};

class Proxy: public Subject
{
public:
	~Proxy()
	{
		cout << "~Proxy()" << endl;
		delete m_RealSubject;
	}

	RealSubject *GetRealSubject()
	{
		if(m_RealSubject == nullptr)
		{
			m_RealSubject = new RealSubject();
		}
		return m_RealSubject;
	}

	void Request() override
	{
		cout << "Proxy::Request()" << endl;

		GetRealSubject()->Request();
	}

private:
	RealSubject *m_RealSubject{nullptr};
};

void ClientCode(Subject *p_Subject)
{
	p_Subject->Request();
}

int main()
{
	Subject *myProxy = new Proxy();

	ClientCode(myProxy);
	cout << endl;

	delete myProxy;

	return 0;
}


