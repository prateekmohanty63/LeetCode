#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int maxProd(vector<int>&vec,int sum,int i)
   {
       // base case
       int n=vec.size();
       if(sum==0)return 1;

       if(i>=n)return 0;

      

       if(sum>=i)
       {
           return max(vec[i]*maxProd(vec,sum-vec[i],i),maxProd(vec,sum,i+1));
       }
       else return maxProd(vec,sum,i+1);
   }

    int integerBreak(int n) {

       vector<int>vec;

       for(int i=1;i<n;i++)
       {
           vec.push_back(i);
       } 

       int res=maxProd(vec,n,0);

       return res;
    }
};

int main()
{
    
    return 0;
}