#include <iostream>

using namespace std;

class Product
{
public:
	virtual ~Product()
	{
		cout << "~Product()" << endl;
	}

	virtual void GiveInfo() = 0;
};

class ConcreteProduct : public Product
{
public:
	~ConcreteProduct()
	{
		cout << "~ConcreteProduct()" << endl;
	}

	void GiveInfo() override
	{
		cout << "ConcreteProduct::GiveInfo()" << endl << endl;;
	}
};

class Creator
{
public:
	virtual ~Creator()
	{
		cout << "~Creator()" << endl;
	}

	void Operation()
	{
		cout << "Creator::Operation()" << endl;

		Product *myProduct = this->FactoryMethod();
		myProduct->GiveInfo();
		RemoveProduct(myProduct);
	}

	void RemoveProduct(Product *p_Product)
	{
		delete p_Product;
	}

	virtual Product *FactoryMethod() = 0;
};

class ConcreteCreator : public Creator
{
public:
	~ConcreteCreator()
	{
		cout << "~ConcreteCreator()" << endl;
	}

	Product *FactoryMethod() override
	{
		return new ConcreteProduct();
	}
};

void ClientCode(Creator *p_Creator)
{
	p_Creator->Operation();
}

int main()
{
	Creator *myCreator = new ConcreteCreator();

	ClientCode(myCreator);

	delete myCreator;

	return 0;
}


