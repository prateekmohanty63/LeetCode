#include<iostream>
#include<stack>
#include<climits>
using namespace std;


class MinStack {
public:
    
    stack<pair<int,int>>stk;

    MinStack() {
        
    }
    
    void push(int val) {
        
        // check if the current stack in empty
        if(stk.empty())
        {
            stk.push({val,val});
        }
        else{
            int minEle=min(val,stk.top().second);
            stk.push({val,minEle});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return min(stk.top().first,stk.top().second);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    stack<int>stk;
    stack<int>minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);

        if(minStack.empty())minStack.push(val);

        else{
            int topEle=minStack.top();
            if(val<=topEle){
                minStack.push(val);
            }
        }
    }
    
    void pop() {
        int ele=stk.top();
        stk.pop();

        if(minStack.top()==ele){
            minStack.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
       return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    stack<int>stk;

    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        int res=INT_MAX;
        stack<int>tmpStack;

        while(!stk.empty())
        {
             int ele=stk.top();
             tmpStack.push(ele);
             res=min(res,ele);
             stk.pop();
        }
        while(!tmpStack.empty())
        {
            int ele=tmpStack.top();
            stk.push(ele);
            tmpStack.pop();
        }
        return res;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    
    return 0;
}