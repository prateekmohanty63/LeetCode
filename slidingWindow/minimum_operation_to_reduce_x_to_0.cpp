#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// sliding window

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum=0;
        int n=nums.size();
        
        int target=accumulate(nums.begin(),nums.end(),-x);
        cout<<target<<" ";
        
        if(target<0) return -1;
        if(target==0) return nums.size();
        
        
        if(nums[n-1]>x && nums[0]>x)return -1;
        
       int ans=-1;
       int l=0,r=0;
       int cur=0;
        
        while(r<nums.size())
        {
            cur+=nums[r];
            
            while(cur>=target)
            {
                if(cur==target){
                    ans=max(ans,r-l+1);
                }
                cur-=nums[l];
                l++;
            }
            r++;
        }
        
       if(ans==-1)return ans;
        
        return nums.size()-ans;
       
    }
};


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