#include <iostream>
#include <vector>
using namespace std;

class Component
{
public:
    virtual ~Component() {}
    virtual void Add(Component *component) = 0;
    virtual void Remove(int index) = 0;
    virtual void Display(int depth) = 0;
    virtual void Delete(int index) = 0;
    virtual void Operation() = 0;
};

class PrimitiveElement : public Component
{
private:
    string name;

public:
    PrimitiveElement() {}
    ~PrimitiveElement() {}
    void Add(Component *component) override
    {
        cout << "Cannot add to a PrimitiveElement" << endl;
    }
    void Remove(int index) override
    {
        cout << "Cannot remove from a PrimitiveElement" << endl;
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << name << endl;
    }
    void Delete(int index) override
    {
        cout << "Cannot delete from a PrimitiveElement" << endl;
    }
    void Operation() override
    {
        cout << "Performing operation on " << name << endl;
    }
};

class CompositeElement : public Component
{
private:
    vector<Component *> components;

public:
    CompositeElement() {}
    ~CompositeElement()
    {
        for (Component *component : components)
        {
            delete component;
        }
    }
    void Add(Component *component) override
    {
        components.push_back(component);
    }
    void Remove(int index) override
    {
        if (index >= 0 && index < components.size())
        {
            delete components[index];
            components.erase(components.begin() + index);
        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << "Composite Element" << endl;
        for (Component *component : components)
        {
            component->Display(depth + 2);
        }
    }
    void Delete(int index) override
    {
        if (index >= 0 && index < components.size())
        {
            delete components[index];
            components.erase(components.begin() + index);
        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }
    void Operation() override
    {
        cout << "Performing operation on Composite Element" << endl;
        for (Component *component : components)
        {
            component->Operation();
        }
    }
};

int main()
{
    CompositeElement *root = new CompositeElement();
    CompositeElement *subComposite1 = new CompositeElement();
    CompositeElement *subComposite2 = new CompositeElement();

    PrimitiveElement *leaf1 = new PrimitiveElement();
    PrimitiveElement *leaf2 = new PrimitiveElement();
    PrimitiveElement *leaf3 = new PrimitiveElement();

    subComposite1->Add(leaf1);
    subComposite1->Add(leaf2);

    subComposite2->Add(leaf3);

    root->Add(subComposite1);
    root->Add(subComposite2);

    cout << "Displaying the composite structure:" << endl;
    root->Display(1);

    cout << "\nPerforming operations on the composite structure:" << endl;
    root->Operation();

    cout << "\nRemoving a leaf from subComposite1:" << endl;
    subComposite1->Remove(0);
    root->Display(1);

    delete root;

    return 0;
}