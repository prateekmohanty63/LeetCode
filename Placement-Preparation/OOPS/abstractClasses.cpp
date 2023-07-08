#include<iostream>
using namespace std;

class Animal{
    public: 
    virtual void sound()=0; // pure virtual function
};

class Dog: public Animal 
{
    public:
    void sound(){
        cout<<"Dog: wood!"<<endl;
    }
};

class Cat:public Animal
{
    public:
    void sound(){
        cout<<"cat: Meow!"<<endl;
    }
};

int main()
{
    Dog *dog=new Dog();
    Cat *cat=new Cat();

    dog->sound();
    cat->sound();
    return 0;
}