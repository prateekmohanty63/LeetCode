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


int main()
{
    
    return 0;
}