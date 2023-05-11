#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
 

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        vector<int>res;
       int start=0;
       int end=k-1;
       int n=nums.size();

       unordered_map<int,int>mp;
       for(int i=start;i<=end;i++)
       {
           mp[nums[i]]++;
       }
       
 
       while(end<=(n-1))
      {
           // finding the xth neg element    
           int temp=x;
           int i=-50;
           for(i=-50;i<0;i++)
           {  
               
                if(mp.find(i)!=mp.end())
                {
                    temp-=mp[i];
                }
                if(temp<=0)break;  
           }   
          
           if(i>=0)res.push_back(0);   

           else res.push_back(i);
          
         
           mp[nums[start]]--;
           start++;
           end++;
           if(end<n)
           mp[nums[end]]++;
       }

       return res;
    }
};

int main()
{
    
    return 0;
}