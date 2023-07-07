#include<iostream>
using namespace std;

// Base class 

class Shape {
     protected:
     double width;
     double height;

     public:
     Shape()
     {

     }
       Shape(double w,double h)
       {
        width=w;
        height=h;
       }

       virtual double calculateArea()=0; // Pure virtual function

       void displayInfo()
       {
          cout<<"Width: "<<width<<endl;
          cout<<"Height: "<<height<<endl;
          cout<<"Area: "<<calculateArea()<<endl;
       }


};

// Derived class (inheritance)

class Rectangle: public Shape {
   public:

   Rectangle(double w,double h):Shape(w,h){};

   double calculateArea(){
      return width*height;
   }
};

// Derived class (inheritance)

class Triangle: public Shape{
    public:

    Triangle(double w,double h)
    {
        width=w;
        height=h;
    }

    double calculateArea()
    {
        return 0.5*width*height;
    }
};

int main()
{
    // creating objects
    Rectangle rectangle(4.5,6.2);
    Triangle triangle(3.9,5.1);

    // Polymorphism
    Shape* shape1=&rectangle;
    Shape* shape2=&triangle;

    shape1->displayInfo();
    cout<<"-------------"<<endl;
    shape2->displayInfo();

    return 0;
}