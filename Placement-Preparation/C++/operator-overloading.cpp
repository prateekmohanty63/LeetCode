#include<iostream>
using namespace std;

class Complex {
    private:
        int real,imag;
    public: 
      Complex()
      {
         real=0;
         imag=0;
      }
      Complex(int r,int i)
      {
        real=r;
        imag=i;
      }

      void print()
      {
        cout<<real<<"+"<<imag<<"i"<<endl;
      }

      // operator overloading
      Complex operator +(Complex c)
      {
        Complex temp;
        temp.real=real+c.real;
        temp.imag=imag+c.imag;

        return temp;
      }

      Complex& operator ++()
      {
        real++;
        imag++;
        return *this;
      }
};

int main()
{
    Complex *a=new Complex(5,4);
    Complex b(3,6);
    Complex c;

    c=*a+b;

    a->print();
    b.print();
    c.print();

   Complex a1(5,4);
   Complex b1(2,3);
   Complex c1(6,7);
   Complex d1;

   d1=a1+b1+c1;
   d1.print();

   ++a1;  // pre-increment works 
   
   a1.print();

    return 0;
}