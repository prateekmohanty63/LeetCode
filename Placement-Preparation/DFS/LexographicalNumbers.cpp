#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   vector<int>res;

   void solve(int start,int n)
   {
        if(start>n)return ;

        if(start<=n)res.push_back(start);

        for(int i=0;i<=9;i++)
        {
            int nextNum=start*10+i;
            solve(nextNum,n);
        }


   }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=9;i++)
        solve(i,n);

      //  for(auto it:res)cout<<it<<" ";

        return res;
    }
};

int main()
{
    
    return 0;
}