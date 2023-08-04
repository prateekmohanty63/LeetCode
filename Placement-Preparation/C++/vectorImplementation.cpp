#include<iostream>
using namespace std;

class Vector {
    private:
    int *array;
    int capacity;
    int size;

    

    public:
   
   // constructor
     Vector(){
        capacity=1;
        size=0;
     };
    Vector(int initialSize)
    {
        array=new int[initialSize];
        capacity=initialSize;
        size=0;
    }

    // destructor
    ~Vector(){
        delete[]array;
    }

    int Size(){
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    int getIndex(int ind)
    {
        if(ind>=size)
        {
            throw out_of_range("Index out of bounds");
        }
        return array[ind];
    }

    void pushBack(int value)
    {
        if(size==capacity)
        {
            Resize();
        }
        array[size++]=value;
    }
    void popBack()
    {
        if(size>0){
            --size;
        }
    }

    private:
    void Resize(){
        if(capacity==0)capacity=1;

        else capacity=2*capacity;

        int *newArray=new int[capacity];

        for(int i=0;i<size;i++)
        {
            newArray[i]=array[i];
        }
        array=newArray;
    }
};

int main()
{
   Vector vec;
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);

    std::cout << "Vector size: " << vec.Size() << std::endl;
    for (size_t i = 0; i < vec.Size(); ++i) {
        std::cout << vec.getIndex(i) << " ";
    }
    std::cout << std::endl;

    vec.popBack();
    std::cout << "Vector size after pop: " << vec.Size() << std::endl;
    
    return 0;
}