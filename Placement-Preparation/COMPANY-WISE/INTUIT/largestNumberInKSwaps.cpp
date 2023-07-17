#include<iostream>
using namespace std;


// T(N)=O(n!/(n-k)!)

class Solution
{
    
    string solve(string str,int index,int k)
    {
        // base case
        int n=str.length();
        if(k==0)return str;
        
        if(index>=n)return str;
        
        string ans=str;
        
      
        
        // we have the option of swapping 
        // or not swapping at the given index
        
        // suppose we choose to swap in the given index
        
        for(int i=index+1;i<n;i++)
        {
            
            if(str[index]<str[i])
            {
                string temp=str;
                swap(temp[index],temp[i]);
                
                ans=max(ans,solve(temp,index+1,k-1));
            }
        }
        
        // if we dont choose to swap
       
        ans=max(ans,solve(str,index+1,k));
        
        return ans;
        
       
    }

    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
     
       string res=solve(str,0,k);
       return res;
       
    }
};

int main()
{
    
    return 0;
}