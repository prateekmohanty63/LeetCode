#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();

        unordered_map<int,int>remainders;
        remainders[0]=1;
        int sum=0;
        int res=0;

        for(int i=0;i<n;i++)
        {
           sum+=nums[i];
           int rem=sum%k;

           if(rem<0)rem+=k;

           if(remainders.find(rem)!=remainders.end())res+=remainders[rem];

           remainders[rem]++;
    
           
        }
        return res;
    }
};

int main()
{
    
    return 0;
}