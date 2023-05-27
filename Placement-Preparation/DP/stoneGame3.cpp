#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
  
  int solve(vector<int>&arr,int i)
  {
      // base case
      int n=arr.size();

      if(i>=n)return 0;

    

      // we either take 1 , 2 or 3 values
      int takeOne,takeTwo=INT_MIN,takeThree=INT_MIN;
      
      takeOne=arr[i]-solve(arr,i+1);

      if(i+1<n)
      takeTwo=arr[i]+arr[i+1]-solve(arr,i+2);


      if(i+2<n)
      takeThree=arr[i]+arr[i+1]+arr[i+2]-solve(arr,i+3);

      return max({takeOne,takeTwo,takeThree});
      
    
      
      
  }

    string stoneGameIII(vector<int>& stoneValue) {
        
        int n=stoneValue.size();
        int sum=0;

       int score=solve(stoneValue,0);

       if(score==0)return "Tie";

       if(score>0)return "Alice";

       return "Bob";
    }
};

int main()
{
    
    return 0;
}