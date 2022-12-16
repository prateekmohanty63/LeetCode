#include<iostream>
using namespace std;


class MyQueue {
public:
 vector<int>vec;   
    MyQueue() {

    

    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    int pop() {
        int a=vec[0];
        vec.erase(vec.begin());

        return a;
    }
    
    int peek() {
        int a=vec[0];

        return a;
    }
    
    bool empty() {
          if(vec.size()==0)return true;

          return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    
    return 0;
}