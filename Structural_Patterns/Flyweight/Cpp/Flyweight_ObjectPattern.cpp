#include <iostream>
#include <map>

class Flyweight
{
public:
	virtual ~Flyweight()
	{
		std::cout << "~Flyweight()" << std::endl;
	}

	virtual void Operation(int p_iExtrinsicState) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
	~ConcreteFlyweight()
	{
		std::cout << "~ConcreteFlyweight() for m_iIntrinsicState:" << m_iIntrinsicState << std::endl;
	}

	ConcreteFlyweight(int p_iIntrinsicState) : m_iIntrinsicState(p_iIntrinsicState) {}

	void Operation(int p_iExtrinsicState)
	{
		std::cout << "ConcreteFlyweight::Operation(" << p_iExtrinsicState << ") for m_iIntrinsicState:" << m_iIntrinsicState << std::endl;
	}

private:
	int m_iIntrinsicState;
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
	~UnsharedConcreteFlyweight()
	{
		std::cout << "~UnsharedConcreteFlyweight() for m_iAllState:" << m_iAllState << std::endl;
	}

	UnsharedConcreteFlyweight(int p_iAllState) : m_iAllState(p_iAllState) {}

	void Operation(int p_iExtrinsicState)
	{
		std::cout << "UnsharedConcreteFlyweight::Operation(" << p_iExtrinsicState << ") for m_iAllState:" << m_iAllState << std::endl;
	}

private:
	int m_iAllState;
};

class FlyweightFactory
{
public:
	~FlyweightFactory()
	{
		std::cout << "~FlyweightFactory()" << std::endl;

		for(auto it = flyweights.begin() ; it != flyweights.end(); it++)
		{
			delete it->second;
		}

		flyweights.clear();
	}

	Flyweight *GetFlyweight(int p_iKey)
	{
		if(flyweights.find(p_iKey) != flyweights.end())
		{
			return flyweights[p_iKey];
		}

		Flyweight *myFlyweight = new ConcreteFlyweight(p_iKey*10); // let be IntrinsicState = (10 x key)
		flyweights.insert(std::pair<int, Flyweight*>(p_iKey, myFlyweight));

		return myFlyweight;
	}

private:
	std::map<int, Flyweight*> flyweights;
};

int main()
{
	FlyweightFactory *myFlyweightFactory = new FlyweightFactory();
	Flyweight *myFlyweight_temp;

	myFlyweight_temp = myFlyweightFactory->GetFlyweight(5);
	myFlyweight_temp->Operation(500);

	myFlyweight_temp = myFlyweightFactory->GetFlyweight(6);
	myFlyweight_temp->Operation(600);

	std::cout << std::endl;
	delete myFlyweightFactory;

	return 0;
}


