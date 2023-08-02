#include<iostream>
using namespace std;

// virtual functions 

class MyBase {
    public:
    void show()
    {
        cout<<"Base class show function called"<<endl;
    }
    virtual void print()
    {
        cout<<"Base class Print function called"<<endl;
    }
};

class MyDerived : public MyBase 
{   
     public:
    void show()
    {
        cout<<"Derived class show function called"<<endl;
    }
     void print()
    {
        cout<<"Derived class Print function called"<<endl;
    } 
};


// pure virtual function 

// abstract class 
class Shape{
    public:
    virtual void getArea()=0;  // pure virtual function 
};

class Circle: public Shape{
    public: 
    void getArea()
    {
        int r=10;
        cout<<"Area of circle: "<<3.14*r*r<<endl;

    }
};

class Rectangle: public Shape{
    public: 
    void getArea()
    {
        int l=10;
        int b=5;
        cout<<"Area of rectangle: "<<l*b<<endl;

    }
};


// implementation of function over-riding 

class Base{

    public:
    
     void greet()
     {
        cout<<"Hello from base class";
     }
};

class Derived: public Base 
{
    public:
      void greet()
      {
        cout<<"Hello from derived class";
      }
};



int main()
{
// {
//     MyBase *baseptr;
//     MyDerived derivedObj;

//     baseptr=&derivedObj;

   //  baseptr->print();   // derived class base function was called
   //  baseptr->show();    // while show is not a virtual function hence the show function of base class is  called
    
    // Circle *obj=new Circle();
    // obj->getArea();

    // Rectangle *obj1=new Rectangle();
   //  obj1->getArea();
   
   Derived objDerived;
   Base *a=&objDerived;
   a->greet();
   
   cout<<endl;

   Base *b=new Derived;
   b->greet();
    return 0;
}