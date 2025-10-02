#include <string>
#include <iostream>
using namespace std;

class IShape
{
public:
    virtual ~IShape() {}
    virtual string getShape() = 0;
    IShape() {}
};

class Circle : public IShape
{
public:
    string getShape() override
    {
        return "Circle";
    }
    ~Circle() {}
};

class Square : public IShape
{
public:
    string getShape() override
    {
        return "Square";
    }
    ~Square() {}
};

class Creator
{
public:
    virtual ~Creator() {}
    virtual IShape *createCircle() = 0;
    virtual IShape *createSquare() = 0;
    virtual void removeShape(IShape *shape) = 0;
};

class ConcreteCreator : public Creator
{
public:
    ~ConcreteCreator() {}
    IShape *createCircle() override
    {
        return new Circle();
    }
    IShape *createSquare() override
    {
        return new Square();
    }
    void removeShape(IShape *shape) override
    {
        delete shape;
    }
};

int main()
{
    Creator *creator = new ConcreteCreator();

    IShape *shape1 = creator->createCircle();
    cout << "Created shape: " << shape1->getShape() << endl;

    IShape *shape2 = creator->createSquare();
    cout << "Created shape: " << shape2->getShape() << endl;

    creator->removeShape(shape1);
    creator->removeShape(shape2);
    delete creator;

    return 0;
}