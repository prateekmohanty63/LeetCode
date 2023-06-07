#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
   queue<int>q1,q2;
    MyStack() {
        // q1.empty();
        // q2.empty();
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int ele;
       
       // pop all elements from q1 to q2 except the last element 
       // return the last ele
        while(!q1.empty())
        {
            ele=q1.front();
            q1.pop();

            if(!q1.empty())
            q2.push(ele);
        }

        // pop back the elements from q2 to q1
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }


        return ele;
    }
    
    int top() {
        int ele;

        // pop the element from queue-1 to get the top
        // store the popped element in queue-2
        while(!q1.empty())
        {
            ele=q1.front();
            q1.pop();
            q2.push(ele);
        }
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ele;

    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    
    return 0;
}