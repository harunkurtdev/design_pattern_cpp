#include <iostream>
#include <vector>

class Singleton {
    private:
        static Singleton* instance;
        Singleton() {
            std::cout << "Singleton Instance Created" << std::endl;
        }
    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton();
            }
            return instance;
        }
        void showMessage() {
            std::cout << "Hello from Singleton!" << std::endl;
        }
};
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    if (singleton1 == singleton2) {
        std::cout << "Both instances are the same." << std::endl;
    } else {
        std::cout << "Instances are different." << std::endl;
    }

    return 0;
}