#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product
{
public:
    vector<string> m_Parts;

    void ShowParts() const
    {
        cout << "Product parts: ";
        for(size_t i = 0 ; i < m_Parts.size() ; i++)
        {
            if(m_Parts[i] == m_Parts.back())
            {
                cout << m_Parts[i];
            }
            else
            {
                cout << m_Parts[i] << ", ";
            }
        }
        cout << endl << endl;
    }
};

class Builder
{
public:
    virtual ~Builder(){}
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual void BuildPartC() = 0;
    virtual Product *GetResult() = 0;
};

class ConcreteBuilder : public Builder
{
private:
	Product *m_Product;

public:
    ConcreteBuilder()
    {
        this->Reset();
    }

    ~ConcreteBuilder()
    {
        delete m_Product;
    }

    void Reset()
    {
        this->m_Product = new Product();
    }

    void BuildPartA() override
    {
        this->m_Product->m_Parts.push_back("PartA");
    }

    void BuildPartB() override
    {
        this->m_Product->m_Parts.push_back("PartB");
    }

    void BuildPartC() override
    {
        this->m_Product->m_Parts.push_back("PartC");
    }

    Product *GetResult() override
    {
    	Product *result = this->m_Product;
        this->Reset();
        return result;
    }
};

class Director
{
private:
    Builder *m_builder;

public:
    void set_builder(Builder *p_Builder)
    {
        this->m_builder = p_Builder;
    }

    void Construct()
    {
        this->m_builder->BuildPartA();
        this->m_builder->BuildPartB();
        this->m_builder->BuildPartC();
    }
};

void ClientCode(Director *p_Director, Builder *p_Builder)
{
	Product *myProduct;

	// The Builder pattern can be used with a Director class.
	p_Director->set_builder(p_Builder);
    cout << "Full product:" << endl;
    p_Director->Construct();

    myProduct = p_Builder->GetResult();
    myProduct->ShowParts();
    delete myProduct;

    // Note that the Builder pattern can also be used without a Director class.
    cout << "Custom product:" << endl;
    p_Builder->BuildPartB();
    p_Builder->BuildPartC();

    myProduct = p_Builder->GetResult();
    myProduct->ShowParts();
    delete myProduct;
}

int main()
{
    Director *myDirector = new Director();
	Builder *myBuilder = new ConcreteBuilder();

    ClientCode(myDirector, myBuilder);

    delete myDirector;
    delete myBuilder;

    return 0;
}


