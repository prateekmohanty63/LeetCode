#include<iostream>
#include<string>

using namespace std;

// Interface(Abstract class with pure virtual function)
class GFG
{
    public:
    virtual string returnString()=0;
};

class child: public GFG
{
    public:
    string returnString()
    {
        return "GeekforGeeks";
    }
};

int main()
{
    child* obj=new child();
    cout<<obj->returnString();
}