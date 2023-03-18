#include<iostream>
#include<vector>
using namespace std;


class BrowserHistory {
public:

  vector<string>history;
  int currPtr=-1;

    BrowserHistory(string homepage) {
        
        history.push_back(homepage);
        currPtr=0;
    }
    
    void visit(string url) {
        
        history.insert(history.begin()+currPtr+1,url);
        currPtr++;

        history.erase(history.begin()+currPtr+1,history.end());
    }
    
    string back(int steps) {
        
        if(currPtr-steps>=0)
        {
           currPtr-=steps;
        }
        else{
            currPtr=0;
        }
        return history[currPtr];
    }
    
    string forward(int steps) {
        
        int r=history.size();

        if(currPtr+steps<r)
        {
            currPtr+=steps;
        }
        else{
            currPtr=r-1;
        }
        return history[currPtr];
    }
};

int main()
{
    
    return 0;
}