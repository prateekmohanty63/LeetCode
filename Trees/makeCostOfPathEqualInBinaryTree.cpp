#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

int res=0;

  bool isLeaf(int i,int n)
  {
       if(2*i>n && 2*i+1>n)return true;

       return false;
  }

  int DFS(int i,vector<int>&cost,int n)
  {  
     if(isLeaf(i,n))return cost[i-1];

     int left=DFS(i*2,cost,n);
     int right=DFS(i*2+1,cost,n);

     res+=abs(left-right);

     return max(left,right)+cost[i-1];
  }

    int minIncrements(int n, vector<int>& cost) {
        
    DFS(1,cost,n);

        return res;
    }
};

int main()
{
    
    return 0;
}