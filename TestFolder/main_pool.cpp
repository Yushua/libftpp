#include "../includes/libftpp.hpp" 
#include <iostream>

class TestObject {
public:
    TestObject() { std::cout << "TestObject default constructor" << std::endl; }
    TestObject(int value) { std::cout << "TestObject constructor with value [" << value << "]" << std::endl; }
    ~TestObject() { std::cout << "TestObject destructor" << std::endl; }

    void sayHello() const { std::cout << "Hello from TestObject" << std::endl; }
};

int main() {
    // Create a Pool for TestObject
    Pool<TestObject> myPool;

    // Resize the pool to pre-allocate 5 objects
    myPool.resize(5);

    // Acquire an object from the pool
    Pool<TestObject>::Object obj1 = myPool.acquire(15);
    obj1->sayHello();

    {
        // Acquire another object in a different scope
        Pool<TestObject>::Object obj2 = myPool.acquire();
        obj2->sayHello();
    }

    // Acquire another object; this should give us the object that obj2 pointed to
    Pool<TestObject>::Object obj3 = myPool.acquire();
    obj3->sayHello();

    return 0;
}
