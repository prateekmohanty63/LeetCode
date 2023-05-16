#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
        int minNum=INT_MIN;
        stack<int>stk;
       
       for(int i=n-1;i>=0;i--)
       {
           if(nums[i]<minNum)return true;

           else{
               while(!stk.empty() && nums[i]>stk.top())
               {
                   minNum=stk.top();
                   stk.pop();
               }
           }
           stk.push(nums[i]);
       }
   return false;
    }
};

int main()
{
    
    return 0;
}