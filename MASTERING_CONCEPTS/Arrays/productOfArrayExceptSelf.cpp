#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();

        vector<int>prefixProduct(n,0);
        vector<int>postfixProduct(n,0);
        vector<int>res(n,0);

        prefixProduct[0]=nums[0];

      // prefix multiplicatiom 

        for(int i=1;i<n;i++)
        {
            int num=prefixProduct[i-1]*nums[i];
            prefixProduct[i]=num;
        }

        postfixProduct[n-1]=nums[n-1];

        // postfix multiplication 

        for(int i=n-2;i>=0;i--)
        {
            int num=postfixProduct[i+1]*nums[i];
            postfixProduct[i]=num;
        }

       res[0]=postfixProduct[1];

       for(int i=1;i<n-1;i++)
       {
           int prod=prefixProduct[i-1]*postfixProduct[i+1];
           res[i]=prod;
       }
        
       res[n-1]=prefixProduct[n-2];

       return res; 
    }
};

int main()
{
    
    return 0;
}