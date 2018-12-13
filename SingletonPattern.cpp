#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton* s_instance;
    Singleton(){}
public:
	// static and public function
    static Singleton *getInstance();
};


Singleton* Singleton::s_instance = 0;
// This static class instantiate the Singleton class if the instance does not exist.
// If the instance exists it does something else.
Singleton* Singleton::getInstance()
{
    if(!s_instance) {
        s_instance = new Singleton();
        std::cout << "There is no instance so we created one.\n";
        return s_instance;
    }else{
        std::cout << "Hey this is the same instance!\n";
      return s_instance;
    }
}

// Main operates as the client.
// We call the getInstance twice, only the first time the instance is created.
// then is being used differently.
int main()
{
	Singleton *singlA = Singleton::getInstance();
	Singleton *singlB = Singleton::getInstance();
	return 0;
}

// Output
// There is no instance so we created one.
// Hey this is the same instance!
 