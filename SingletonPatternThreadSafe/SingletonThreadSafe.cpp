#include <iostream>
#include <mutex>
#include <mutex>

using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx; // Mutex for thread safety
    Singleton() {}

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx); // Lock the mutex
            if (instance == nullptr)
            { // Double-check
                instance = new Singleton();
            }
            mtx.unlock(); // Unlock the mutex
        }
        return instance;
    }
    void showMessage()
    {
        cout << "Hello from Singleton!" << endl;
    }
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton *singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    Singleton *singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    if (singleton1 == singleton2)
    {
        cout << "Both instances are the same." << endl;
    }
    else
    {
        cout << "Instances are different." << endl;
    }

    return 0;
}