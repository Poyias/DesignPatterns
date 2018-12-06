#include <iostream>
using namespace std;
class Pope_Singleton
{
public:
	static Pope_Singleton *getInstance();
	private:
	Pope_Singleton(){}
	static Pope_Singleton* instance;
};

Pope_Singleton* Pope_Singleton::instance = 0;

Pope_Singleton* Pope_Singleton::getInstance()
{
	if(!instance) {
		instance = new Pope_Singleton();
		cout << "getInstance(): Pope instance created\n";
		return instance;
	}
	else 
	{
		cout << "getInstance(): Hey this is the same Pope!\n";
		return instance;
	}
}
int main()
{
	Pope_Singleton *s1 = Pope_Singleton::getInstance();
	Pope_Singleton *s2 = Pope_Singleton::getInstance();
	return 0;
}