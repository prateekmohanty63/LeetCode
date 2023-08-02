#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    int solve(string &s,int ind,int x,int y,int &n)
    {
        // base case
        int m=s.length();

        if(ind>=m)return 0;

        if(x<0 || x>=n)return 0;
        if(y<0 || y>=n)return 0;

        char a=s[ind];

        if(a=='L'){
            if(y-1>=0)
           return 1+solve(s,ind+1,x,y-1,n);

           else return 0;
        }

        else if(a=='R'){
        if(y+1<n)
        return 1+solve(s,ind+1,x,y+1,n);

        else return 0;

        }

        else if(a=='U'){
        if(x-1>=0)
        return 1+solve(s,ind+1,x-1,y,n);

        else return 0;
        }

        else{
            if(x+1<n)
            return 1+solve(s,ind+1,x+1,y,n);

            else return 0;
        }
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        vector<int>res;

        int m=s.length();

        for(int i=0;i<m;i++)
        {
            int a=solve(s,i,startPos[0],startPos[1],n);
            res.push_back(a);
        }

      return res;
    }
};

int main()
{
    
    return 0;
}