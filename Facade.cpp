#include <iostream>
using namespace std;

/*
 * @brief Subsystem1 and 2 below are to be used by the Facade.
*/
class Waiter_Subsystem1
{
public:
  void writeOrder()   { cout << " Waiter writes client's order\n";}
  void sendToKitchen(){ cout << " Send order to kitchen\n";}
  void serveCustomer(){ cout << " Yeeei customer is served!!!\n";}
};
class Kitchen_Subsystem2
{
public:
    void prepareFood(){ cout << " Cook food\n";}
    void callWaiter() { cout << " Call Waiter\n";}
    void washDishes() { cout << " Wash the dishes\n";}
};

/*
 * @brief Facade is using the above subsystems to simplify it for the client
*/
class Order_Facade
{
private:
    Waiter_Subsystem1 waiter;
    Kitchen_Subsystem2 kitchen;
public:
    void orderFood()
    {
        cout << "A series of interdependent calls on various subsystems:\n";
        waiter.writeOrder();
        waiter.sendToKitchen();
        kitchen.prepareFood();
        kitchen.callWaiter();
        waiter.serveCustomer();
        kitchen.washDishes();
    }
};

/*
 * @brief main operates as a client
*/
int main(int argc, char *argv[])
{
    // Simple for the client 
    // no need to know the order or the 
    // dependencies among various subsystems.
    Order_Facade facade;
    facade.orderFood();
return 0;
}

// Output
// A series of interdependent calls on various subsystems:
//  Waiter writes client's order
//  Send order to kitchen
//  Cook food
//  Call Waiter
//  Yeeei customer is served!!!
//  Wash the dishes