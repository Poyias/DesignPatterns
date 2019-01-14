#include<iostream>
#include<string>
 
using namespace std;
 
class MoveLogic
{
public:
    virtual void move() = 0;
};
 
class Walk : public MoveLogic
{
public:
    void move()
    {
        cout << "Move alternating legs\n";
    }
};
 
class Fly : public MoveLogic
{
public:
    void move()
    {
        cout << "Flap wings\n";
    }
};
 
class Animal
{
public:
    virtual void howDoIMove() = 0;
};
 
class Person : public Animal
{
    MoveLogic* _myMoveLogic;
public:
    Person(MoveLogic *obj) :_myMoveLogic(obj){}
    void howDoIMove()
    {
        _myMoveLogic->move();
    }
};
 
class Bird : public Animal
{
    MoveLogic* _myMoveLogic;
public:
    Bird(MoveLogic *obj) :_myMoveLogic(obj){}
    void howDoIMove()
    {
        _myMoveLogic->move();
    }
};
 
int main()
{
    MoveLogic* walk = new Walk();
    MoveLogic* fly  = new Fly();
 
    Animal* animalA = new Person(walk);
    Animal* animalB = new Bird(fly);
 
    animalA->howDoIMove();
    animalB->howDoIMove();
 
    return 1;
}