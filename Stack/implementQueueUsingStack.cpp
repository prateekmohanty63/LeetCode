#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Faster than 100%

class MyQueue {
public:
    stack<int>stk;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        stack<int>tmpStack;

        while(!stk.empty())
        {
            int a=stk.top();
            tmpStack.push(a);
            stk.pop();
        }

        int res=tmpStack.top();
        tmpStack.pop();

        while(!tmpStack.empty())
        {
            int a=tmpStack.top();
            stk.push(a);
            tmpStack.pop();
        }
        return res;
    }
    
    int peek() {
        
        stack<int>tmpStack;

        while(!stk.empty())
        {
            int a=stk.top();
            tmpStack.push(a);
            stk.pop();
        }

        int res=tmpStack.top();

         while(!tmpStack.empty())
        {
            int a=tmpStack.top();
            stk.push(a);
            tmpStack.pop();
        }

        return res;
    }
    
    bool empty() {
        if(stk.empty())return true;

        return false;
    }
};


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