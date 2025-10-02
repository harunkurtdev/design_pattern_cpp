#include <iostream>
#include <vector>

using namespace std;

class Observer
{
private:
    int observerID;

public:
    Observer(int id)
    {
        observerID = id;
    }
    int getID()
    {
        return observerID;
    }
    virtual void update(int value) = 0;
    virtual int getState() = 0;
};

class Subject
{
protected:
    int concreteState;
    vector<Observer *> observerList;

public:
    virtual int GetState() = 0;
    virtual void SetState(int value) = 0;
    void Attach(Observer *o)
    {
        this->observerList.push_back(o);
    }
    void Deattach(Observer *o)
    {
        for (auto it = observerList.begin(); it != observerList.end(); ++it)
        {
            if (*it == o)
            {
                observerList.erase(it);
                break;
            }
        }
    }
    void Notify()
    {
        for (auto it = observerList.begin(); it != observerList.end(); ++it)
        {
            (*it)->update(concreteState);
        }
    }
};

class ConcreteSubject : public Subject
{
public:
    int GetState() override
    {
        return this->concreteState;
    }
    void SetState(int value) override
    {
        this->concreteState = value;
        Notify();
    }
};

class ConcreteObserver : public Observer
{
private:
    int observerState;
public :
    ConcreteObserver(int id) : Observer(id)
    {
        observerState = 0;
    }
    void update(int value) override
    {
        this->observerState = value;
        cout << "Observer " << getID() << " updated with state " << observerState << endl;
    }
    int getState() override
    {
        return observerState;
    }
};

int main()
{
    ConcreteSubject *subject = new ConcreteSubject();

    ConcreteObserver *observer1 = new ConcreteObserver(1);
    ConcreteObserver *observer2 = new ConcreteObserver(2);
    ConcreteObserver *observer3 = new ConcreteObserver(3);

    subject->Attach(observer1);
    subject->Attach(observer2);
    subject->Attach(observer3);

    subject->SetState(10);

    cout << "subject state: " << subject->GetState() << endl;
    cout << observer1->getID() << " state: " << observer1->getState() << endl;
    cout << observer2->getID() << " state: " << observer2->getState() << endl;
    cout << observer3->getID() << " state: " << observer3->getState() << endl;


    subject->SetState(20);
    subject->Deattach(observer2);

    subject->SetState(30);

    delete observer1;
    delete observer2;
    delete observer3;
    delete subject;

    return 0;
}