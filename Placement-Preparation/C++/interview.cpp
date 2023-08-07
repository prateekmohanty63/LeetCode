#include<iostream>
#include<stdlib.h>
using namespace std;


// 1. Dynamic memory allocation in c , cpp 


void dynamicMemory()
{
    // int* allocated_with_malloc=malloc(5*sizeof(int));
    // int* allocated_with_calloc=calloc(5,sizeof(int));

    // if(allocated_with_calloc==NULL || allocated_with_malloc==NULL)
    // {
    //     cout<<"Allocation failed";
    // }

    // // remember to always free dynamically allocated memory 
    // free(allocated_with_malloc);
    // free(allocated_with_calloc);
}


// 2. polymorhpism in cpp

// 1. compile time polymorphism 
//    -> function overloading , operator overloading


class complieTimePoly
{
    public:
    int real;
    int img;

    complieTimePoly(int real,int img)
    {
        this->real=real;
        this->img=img;
    }

    void display()
    {
        cout<<real<<"+"<<img<<"*i"<<endl;
    }

    int func1(int a,int b)
    {
       return a*b; 
    }

    int func1(int a,int b,int c)
    {
        return a*b*c;
    }
    // this wont work as changing only the return type , will give an error 
    // double func1(int a, int b)
    // {
    //     return a*b;
    // }

    complieTimePoly& operator +(complieTimePoly a)
    {
        real+=a.real;
        img+=a.img;
        return *this;
    }
};


// 2. runtime polymorhpism 
//    -> function over-riding 
//    -> 1. virtual function , pure virtual function 
//    -> 2. abstract classes , interface  


class runTimePoly
{
    public: 

    virtual void func1()
    {
        cout<<"hello I am base class func-1"<<endl;
    }

    ~ runTimePoly()
    {
        cout<<"Run time poly desctructor called"<<endl;
    }

};

class runTimePolyDer: public runTimePoly
{
    public:
     void func1()
     {
        cout<<"Hello I am derived class func-1"<<endl;
     }
};

class abstractClass
{
    // run time polymorphism 
    public:
    void func1()
    {
        cout<<"Hello from func1"<<endl;
    }

    virtual void func2()=0;
    virtual void func3()=0;
};

class abstractDer: public abstractClass
{
    public: 
    void func2()
    {
        cout<<"This is func-2 from implentation of abstract class"<<endl;
    }

    void func3()
    {
        cout<<"This is func-3 from implementation of abstract class"<<endl;
    }
};


class interfaceClass
{
    virtual void func1()=0;
    virtual void func2()=0;
    virtual void func3()=0;
};

class interfaceClassDer: public interfaceClass
{
    public:

      void func1()
      {
        cout<<"Hello from func-1 interface class"<<endl;
      }

      void func2()
      {
        cout<<"Hello from func-2 interface class"<<endl;
      }
      void func3()
      {
        cout<<"Hello from func-3 interface class"<<endl;
      }

      ~ interfaceClassDer()
      {
        cout<<"Interface class destructor called"<<endl;
      }
};


// 3. friend function and classes 

class MyClass {
private:
    int x;

public:
    MyClass(int value) : x(value) {}

    // Declare the friend function
    friend void friendFunction(const MyClass& obj);

    ~ MyClass()
    {
        cout<<"Myclass destructor called"<<endl;
    }

    friend class myBestFriend;
};

void friendFunction(const MyClass& obj)
{
    std::cout << "Friend function accessing private member: " << obj.x << std::endl;
}

class myBestFriend
{
    public:
     void display(MyClass& obj)
     {
        cout<<"This value I have derived from my friend class from above: "<<obj.x<<endl;
     }
};

// 4. The four pillars of OOPS

//  -> Inheritance
//  -> Encapsulation
//  -> Polymorphism
//  -> Abstraction 


// Inheritance

class parentClass
{
    public:
    int data;

   virtual void display()
    {
        cout<<"Hello from parent class"<<endl;
    }
};

// a. Single Inheritance

class childClass1: public parentClass
{
    public:
    int data1=100;
      void display()
      {
          cout<<"Hello from child-class-1 , I have data: "<<data<<endl;
      }
};


// b. Multilevel inheritance 

class childClass2: public childClass1
{
    public:
    void display()
    {
        cout<<"Hello from child-class-2 , I have data: "<<data<<" "<<data1<<endl;
    }
};

// Multiple inheritance

class childClass3: public parentClass, public runTimePoly
{
     public:

     void display()
     {
         cout<<"Hello I am part of multiple inheritance: "<<data<<" "<<endl;
         func1();

     }
};


// Multipath inheritance

class fruit 
{
    public:
    void display()
    { 
       cout<<"Hello I am fruit class"<<endl;
    }
};

class mango : public fruit
{
    public:
    void display()
    {
        cout<<"Hello I am mango , a child of fruit class"<<endl;
    }
};

class guava: public fruit
{
    public: 
    void display()
    {
        cout<<"Hello I am guava, a child of fruit class"<<endl;
    }
};

class taste: public mango , public guava
{
    public: 
    void display()
    {
        cout<<"Hello all the fruits are tasty"<<endl;
    }
};


// mutltiple inheritance and ambiguity problem

// Base class-1
class A 
{
    public: 
     void printMessage()
     {
        cout<<"Class A print message function"<<endl;
     }
};

// Base class-2
class B 
{
    public: 
    void printMessage()
    {
        cout<<"Class B print message function"<<endl;
    }
};

class AB: public A, public B
{
   public: 
    void printMessage()
    {
        // hence we use the scope resolution operator 
        // to class the function of a specific class
        // scope resolution operator 
        A::printMessage();
        B::printMessage();
        cout<<"Class AB print message"<<endl;
    }
};


// multipath inheritance
// Dimond pronlem,

class base{
    protected: 
    int val;
};

class derived1: virtual public base
{
    public:
      derived1()
      {
        val=1 ;
      }
};

class derived2: virtual public base 
{
    public:
    derived2()
    {
        val=2;
    }
};

class derived3: public derived1 , public derived2
{
    public: 
   // 2 copies of val in derived 3
    void getValue()
    {
        cout<<"Int value is: "<<val<<endl;
    }
};


// Encapsulation 

// By definition, encapsulation describes bundling data 
// and methods that work on that data within one unit

// We often often use this concept to hide an object’s internal representation or state from the outside.
//  This is called information hiding

class Student
{
    private:
    string name;
    int age;
    double cgpa;

    public: 
    Student(string name,int age,double cgpa)
    {
        this->name=name;
        this->age=age;
        this->cgpa=cgpa;
    }
   
   // getter methods
    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    double getCgpa()
    {
        return cgpa;
    }

    // setter methods

    void setName(string n)
    {
        name=n;
    }
    void setAge(int a)
    {
        if(a>=0)
        {
            age=a;
        }
    }

    void setGPA(double g)
    {
        if(g>=0.0 && g<=4.0)
        {
            cgpa=g;
        }
    }
};


// Polymorphism

// There are 2 types of polymorphism 
// -> Compile time polymorphism
// -> Run time polymorphism


// Compile time polymorphism 
// a. Function overloading
// b. operator overloading

class complex 
{
    public:
    int real;
    int img;
    
    complex(){};

    complex(int a,int b)
    {
        real=a;
        img=b;
    }
    
    void display()
    {
        cout<<real<<"+"<<"i"<<img<<endl;
    }

    // function overloading
    int add(int a,int b)
    {
        return a+b;
    }
    int add(int a,int b,int c)
    {
        return a+b+c;
    }

   // operator overloading
    complex& operator +(complex c)
    {
        real+=c.real;
        img+=c.img;
        return *this;
    }

};


// runtime polymorphism
// 1. function overriding

class shape
{
    protected:

    int length;
    int breadth;

    virtual void getArea()=0;

};

class square : public shape
{
    public:
    square(int a,int b)
    {
        length=a;
        breadth=b;
    }
    void getArea()
    {
        cout<<length*breadth<<endl;
    }
};


// Abstraction 

// implemented using abstract classes and interfaces in cpp 


class Shape 
{
    public: 
    virtual double calculateArea()=0;
    virtual void display()=0;
};

class Circle:public Shape 
{
    private:
    double radius;

    public: 
    Circle(double r)
    {
        radius=r;
    }
   
   double calculateArea(){
    return 3.14*radius*radius;
   }

   void display(){
        std::cout << "Circle with radius " << radius << std::endl;
    }

};


// Static variables and members 

class staticExample
{
    static int count;
    int data;

    public:
    staticExample(int data)
    {
        this->data=data;
        count++;
    }

    static int getCount(){
        return count;
    }
};


// Exception handling in cpp using try anc catch

void exceptionHandling()
{
    try{
        int numerator=10;
        int denominator=0;

        if(denominator==0)
        {
            throw runtime_error("Division by zero");
        }
    }
    catch(exception e)
    {
        cout<<e.what()<<endl;
    }
}


// exception handling in cpp 

class class1
{
    void func(){
    int numerator;
    int denominator;
    try{
         if(denominator==0)throw runtime_error("Division by zero");
    }
    catch(exception e)
    {
        cout<<e.what();
    }
}
};

// custom exception 

// class MyCustomException: public exception{
//     public:

//     char* what(char* msg){
//         return msg;
//     }
// };

int func()
{
    try{
        int a=0;
        if(a==0)
        throw "Please enter valid input";
    }
    catch(string a)
    {
        cout<<a;
    }
    catch(...){
        cout<<"Any exception";
    }
}

int staticExample::count=0;


int main()
{
    // 1.
    complieTimePoly *obj=new complieTimePoly(1,1);
    obj->display();

    complieTimePoly *obj1=new complieTimePoly(2,2);

    complieTimePoly arg1(1,1);
    complieTimePoly arg2(2,2);
    complieTimePoly res=arg1+arg2;
    res.display();


    // 2. 

    runTimePolyDer obj2;
    runTimePoly *obj3=&obj2;
    
    obj3->func1();
   
   abstractDer* obj4=new abstractDer();
   obj4->func1();
   obj4->func2();
   obj4->func3();

   interfaceClassDer* obj5=new interfaceClassDer();
   obj5->func1();
   obj5->func2();
   obj5->func3();


   // 3. 
  MyClass a(10);
   friendFunction(a);

   myBestFriend* obj6=new myBestFriend();
   obj6->display(a);
 

 // 4. 
  childClass1 obj7; 
  parentClass* obj8=&obj7;
  obj8->display();
  
  childClass2 obj9;
  obj9.display();

  childClass3 obj10;
  obj10.display();

  taste obj11;
  obj11.display();

  AB obj12;
//   obj12.printMessage()   error (multiple inheritance ambiguity)
obj12.printMessage();

 derived3 obj13;
 obj13.getValue();

 cout<<endl;


 // encapsulation 

 Student student("Alice", 20, 3.8);

    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Student Age: " << student.getAge() << std::endl;
    std::cout << "Student GPA: " << student.getCgpa() << std::endl;

    student.setName("Bob");
    student.setAge(22);
    student.setGPA(3.5);

    std::cout << "\nUpdated Student Info:" << std::endl;
    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Student Age: " << student.getAge() << std::endl;
    std::cout << "Student GPA: " << student.getCgpa() << std::endl;

    complex obj15(1,2);
    complex obj16(1,2);
   cout<<obj15.add(1,2)<<endl;
   cout<<obj15.add(1,2,3)<<endl;

   complex obj17;
   obj17=obj15+obj16;
   obj17.display();
   

   square obj18(1,2);
   obj18.getArea();

   Circle obj19(2);
   cout<<obj19.calculateArea()<<endl;
   obj19.display();
   

   staticExample obj20(1);
   staticExample obj21(1);
   cout<<"Static count called: "<<staticExample::getCount()<<endl;

   // exception handling in cpp 
   exceptionHandling(); 
 

    return 0;
}