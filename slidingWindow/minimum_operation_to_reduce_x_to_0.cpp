#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// solution correct
// but t(n)=O(2^n)
// hence gives TLE
class Solution {
public:
    
    void solve(vector<int>nums,int x,int count,int &min)
    {
        if(x==0){
            if(count<min)min=count;
        }
        
        if(!nums.size() || x<0)return ;
        
        int l=nums[0];
        int r=nums[nums.size()-1];
        
        nums.pop_back();
        solve(nums,x-r,count+1,min);
        nums.push_back(r);
        
        nums.erase(nums.begin()+0);
        solve(nums,x-l,count+1,min);
        nums.insert(nums.begin(),l);
        
        
    }
    int minOperations(vector<int>& nums, int x) {
        
        int sum=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(sum<x)return -1;
        
        if(nums[n-1]>x && nums[0]>x)return -1;
        
        int count=0;
        
        int min=INT_MAX;
        
        solve(nums,x,count,min);
        
        if(min==INT_MAX)return -1;
        
        return min;
    }
};

int main()
{
    
    return 0;
}