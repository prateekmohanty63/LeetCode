#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 1 approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();

        unordered_map<int,bool>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=true;
        }

        for(int i=0;i<=n;i++)
        {
            if(mp.find(i)==mp.end())return i;
        }
      
      return -1;

    }
};

// 2nd approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();

        int sum=0;
        

        for(int i=0;i<n;i++)
        {

            sum+=nums[i];
        }

        int reqSum=n*(n+1)/2;

        cout<<reqSum<<" "<<sum;

        return reqSum-sum;
    }
};


// 3rd approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();

        // suppose n=4

        // we calculate (0^1^3^4)^(0^1^2^3^4) == 2
        
        int tar=0;
        int i=0;

        for(i=0;i<n;i++)
        {
            tar=tar^nums[i]^i;
        }
       
       tar=tar^i;

       return tar;
       
    }
};


int main()
{
    
    return 0;
}