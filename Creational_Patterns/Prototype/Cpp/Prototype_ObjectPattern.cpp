#include <iostream>

using namespace std;

enum class Types
{
	PROTOTYPE_1 = 0,
	PROTOTYPE_2 = 1,
	MAX_SIZE_OF_PROTOTYPE = 2
};

class Prototype
{
public:
	virtual ~Prototype()
	{
		cout << "~Prototype()" << endl;
	}

	virtual Prototype *Clone() = 0;
	virtual void GiveInfo() = 0;
};

class ConcretePrototype1: public Prototype
{
private:
	int m_iNumber{51};

public:
	~ConcretePrototype1()
	{
		cout << "~ConcretePrototype1()" << endl;
	}

	ConcretePrototype1(int p_iNum) : m_iNumber(p_iNum) {}

	Prototype *Clone()
	{
		return (new ConcretePrototype1(*this));
	}

	void GiveInfo()
	{
		cout << "ConcretePrototype1::GiveInfo(): m_iNumber:" << m_iNumber << endl;
	}
};

class ConcretePrototype2: public Prototype
{
private:
	int m_iNumber2{52};
	float *m_fpNumber2;

public:
	~ConcretePrototype2()
	{
		cout << "~ConcretePrototype2() with m_fpNumber2:" << m_fpNumber2 << endl;

		delete m_fpNumber2;
	};

	ConcretePrototype2(int p_iNum) : m_iNumber2(p_iNum)
	{
		m_fpNumber2 = new float(7.5);
	}

	ConcretePrototype2(const ConcretePrototype2 &p2) //copy constructor for deep copy
	{
		m_iNumber2 = p2.m_iNumber2;
		m_fpNumber2 = new float(*p2.m_fpNumber2);
	}

	Prototype *Clone()
	{
		return (new ConcretePrototype2(*this));
	}

	void GiveInfo()
	{
		cout << "ConcretePrototype2::GiveInfo(): m_iNumber2:" << m_iNumber2 << " ; m_fpNumber2(Address): " << m_fpNumber2 << " -> " << *m_fpNumber2 << endl;
	}
};

class Client
{
private:
	static Prototype *m_Prototypes[((int) Types::MAX_SIZE_OF_PROTOTYPE)];

public:
	static void CreatePrototypes()
	{
		cout << "Client::CreatePrototypes()" << endl;

		m_Prototypes[0] = new ConcretePrototype1(10);
		m_Prototypes[0]->GiveInfo();

		m_Prototypes[1] = new ConcretePrototype2(20);
		m_Prototypes[1]->GiveInfo();

		cout << endl;
	}

	static void RemovePrototypes()
	{
		cout << "Client::RemovePrototypes()" << endl;

		for(int i = 0 ; i < ((int) Types::MAX_SIZE_OF_PROTOTYPE) ; i++)
		{
			delete m_Prototypes[i];
		}
	}

	static Prototype *MakeClone(Types p_Types)
	{
		if( (((int) p_Types) >= ((int) Types::MAX_SIZE_OF_PROTOTYPE)) || (((int) p_Types) < 0) )
		{
			cout << "Client::MakeClone: ERROR: Index: Out of Range, INDEX:" << (int) p_Types << endl;

			return nullptr;
		}
		return m_Prototypes[((int) p_Types)]->Clone();
	}
};
Prototype * Client::m_Prototypes[((int) Types::MAX_SIZE_OF_PROTOTYPE)];

int main()
{
	Prototype *myPrototype = nullptr;

	Client::CreatePrototypes();

	cout << "CLONE_1:" << endl;
	myPrototype = Client::MakeClone(Types::PROTOTYPE_1);
	if(myPrototype != nullptr)
	{
		myPrototype->GiveInfo();
		delete myPrototype;
	}
	cout << endl;

	cout << "CLONE_2:" << endl;
	myPrototype = Client::MakeClone(Types::PROTOTYPE_2);
	if(myPrototype != nullptr)
	{
		myPrototype->GiveInfo();
		delete myPrototype;
	}
	cout << endl;

	Client::RemovePrototypes();

    return 0;
}


