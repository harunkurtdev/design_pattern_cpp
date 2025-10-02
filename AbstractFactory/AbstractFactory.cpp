#include <iostream>
#include <string>
using namespace std;

class IShape
{
public:
    virtual void Draw() = 0;
    virtual ~IShape() {}
    IShape() {}
};

class Reactangle : public IShape
{
public:
    void Draw() override
    {
        cout << "Drawing a Rectangle" << endl;
    }
};

class Square : public IShape
{
public:
    void Draw() override
    {
        cout << "Drawing a Square" << endl;
    }
};

class Circle : public IShape
{
public:
    void Draw() override
    {
        cout << "Drawing a Circle" << endl;
    }
};

class Triangle : public IShape
{
public:
    void Draw() override
    {
        cout << "Drawing a Triangle" << endl;
    }
};

class ShapeFactory
{
public:
    virtual IShape *drawRectangle() = 0;
    virtual IShape *drawSquare() = 0;
    virtual IShape *drawCircle() = 0;
    virtual IShape *drawTriangle() = 0;
    virtual ~ShapeFactory() {}
};

class SimpleShapeFactory : public ShapeFactory
{
public:
    IShape *drawRectangle() override
    {
        return new Reactangle();
    }
    IShape *drawSquare() override
    {
        return new Square();
    }
    IShape *drawCircle() override
    {
        return new Circle();
    }
    IShape *drawTriangle() override
    {
        return new Triangle();
    }
};
int main()
{
    ShapeFactory *shapeFactory = new SimpleShapeFactory();

    IShape *shape1 = shapeFactory->drawRectangle();
    shape1->Draw();
    delete shape1;

    IShape *shape2 = shapeFactory->drawSquare();
    shape2->Draw();
    delete shape2;

    IShape *shape3 = shapeFactory->drawCircle();
    shape3->Draw();
    delete shape3;

    IShape *shape4 = shapeFactory->drawTriangle();
    shape4->Draw();
    delete shape4;

    delete shapeFactory;
    return 0;
}
