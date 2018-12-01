// The Abstract Factory design pattern is from my blog in medium platform.
// It is a 4-minute guide to this design pattern and a simple diagram that explains it.
// link

#include <iostream>

// After the underscore I define the role of the class in this design patern.

// class DoorHandle_AbstractProduct		[FromBlog]: keyword number 2
// class BMWDoorHandle_Product			[FromBlog]: keyword number 1
// class FordDoorHandle_Product			[FromBlog]: keyword number 1

// class DoorWindow_AbstractProduct		[FromBlog]: keyword number 2
// class BMWDoorWindow_Product			[FromBlog]: keyword number 1
// class FordDoorWindow_Product			[FromBlog]: keyword number 1

// class Car_AbstractFactory   			[FromBlog]: keyword number 4
// class BMWCar_ConcreteFactory			[FromBlog]: keyword number 3
// class FordCar_ConcreteFactory		[FromBlog]: keyword number 3

/*
	@brief: The abstract product class
			defines the doorHandle products which inherit from it.
*/
class DoorHandle_AbstractProduct
{
public:
	virtual void printSerialNumber() = 0;
};

/* 
	@brief: This is another abstract class of a different family of products.
*/
class DoorWindow_AbstractProduct 
{
public:
	virtual void printSerialNumber() = 0;
};
 
/*
	@brief: This is product-specific code
*/
class BMWDoorHandle_Product : public DoorHandle_AbstractProduct 
{
public:
	void printSerialNumber (){
		std::cout << " DoorHandle_Product: BMW123 \n";
       }
};
 
class FordDoorHandle_Product : public DoorHandle_AbstractProduct 
{
public:
	void printSerialNumber (){
		std::cout << " DoorHandle_Product: Ford123 \n";
       }
};

class BMWDoorWindow_Product : public DoorWindow_AbstractProduct 
{
public:
	void printSerialNumber (){
		std::cout << " DoorWindow_Product: BMW456 \n";
       }
};
 
class FordDoorWindow_Product : public DoorWindow_AbstractProduct {
public:

	void printSerialNumber (){
		std::cout << " DoorWindow_Product: Ford456 \n";
       }
};


/*
	@brief: It is an abstract class of a car Factory.
	When our factory needs an update to be able to create another type of product we just need to add a pure virtual function herefor axample it could be createWheel
*/
class Car_AbstractFactory 
{
public:
	virtual DoorHandle_AbstractProduct* createDoorHandle () = 0;
	virtual DoorWindow_AbstractProduct* createDoorWindow () = 0;
};

/*
	@brief: This is the concrete factory that needs to be hidden from user as much as possible. It inherits from the abstract factory class and in this example it is strictly related to BMW "products".
*/
class BMWCar_ConcreteFactory : public Car_AbstractFactory 
{
public:
	DoorHandle_AbstractProduct* createDoorHandle (){
		return new BMWDoorHandle_Product;
	}
	DoorWindow_AbstractProduct* createDoorWindow (){
		return new BMWDoorWindow_Product;
	}
};
/*
	@brief: The same as above but for Ford brand
*/ 
class FordCar_ConcreteFactory : public Car_AbstractFactory 
{
public:
	DoorHandle_AbstractProduct* createDoorHandle (){
		return new FordDoorHandle_Product;
	}
	DoorWindow_AbstractProduct* createDoorWindow (){
		return new FordDoorWindow_Product;
	}
};


int main()
{
	// Client needs a doorHandle and a doorWindow
	Car_AbstractFactory* abstractFactory;
	DoorHandle_AbstractProduct *dHandle_AbstractProduct;
	DoorWindow_AbstractProduct *dWindow_AbstractProduct;

	// The client needs products from Ford brand
	abstractFactory = new FordCar_ConcreteFactory;

	// So the Ford concrete factory creates them and returns them to the client
	dHandle_AbstractProduct = abstractFactory->createDoorHandle();
	dWindow_AbstractProduct = abstractFactory->createDoorWindow();

	// Client uses the products
	dHandle_AbstractProduct -> printSerialNumber();
	dWindow_AbstractProduct -> printSerialNumber();

	// Now the client wants products but from BMW brand
	abstractFactory = new BMWCar_ConcreteFactory;

	// So the BMW concrete factory creates them and returns them to the client
	dHandle_AbstractProduct = abstractFactory->createDoorHandle();
	dWindow_AbstractProduct = abstractFactory->createDoorWindow();

	// Client uses the products
	dHandle_AbstractProduct -> printSerialNumber();
	dWindow_AbstractProduct -> printSerialNumber();

	return 0;
}