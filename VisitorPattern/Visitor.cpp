#include <iostream>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    virtual void VisitConcreteElementA(ConcreteElementA *element) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB *element) = 0;
    virtual ~Visitor() {}
};

class ConcreteVisitor1 : public Visitor
{
public:
    ConcreteVisitor1() {}
    void VisitConcreteElementA(ConcreteElementA *element) override
    {
        cout << "ConcreteVisitor1 visiting ConcreteElementA" << endl;
    }
    void VisitConcreteElementB(ConcreteElementB *element) override
    {
        cout << "ConcreteVisitor1 visiting ConcreteElementB" << endl;
    }
};

class ConcreteVisitor2 : public Visitor
{
public:
    ConcreteVisitor2() {}
    void VisitConcreteElementA(ConcreteElementA *element) override
    {
        cout << "ConcreteVisitor2 visiting ConcreteElementA" << endl;
    }
    void VisitConcreteElementB(ConcreteElementB *element) override
    {
        cout << "ConcreteVisitor2 visiting ConcreteElementB" << endl;
    }
};

class Element
{
public:
    virtual void Accept(Visitor *visitor) = 0;
    virtual ~Element() {}
};

class ConcreteElementA : public Element
{
public:
    ConcreteElementA() {}
    void Accept(Visitor *visitor) override
    {
        visitor->VisitConcreteElementA(this);
    }
};

class ConcreteElementB : public Element
{
public:
    ConcreteElementB() {}
    void Accept(Visitor *visitor) override
    {
        visitor->VisitConcreteElementB(this);
    }
};

int main()
{
    Element *elementA = new ConcreteElementA();
    Element *elementB = new ConcreteElementB();

    Visitor *visitor1 = new ConcreteVisitor1();
    Visitor *visitor2 = new ConcreteVisitor2();

    elementA->Accept(visitor1);
    elementB->Accept(visitor1);

    elementA->Accept(visitor2);
    elementB->Accept(visitor2);

    delete elementA;
    delete elementB;
    delete visitor1;
    delete visitor2;

    return 0;
}