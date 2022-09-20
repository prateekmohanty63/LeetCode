#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;


// O(1) space complexity
//Runtime: 46 ms, faster than 5.74% of C++ online submissions for Majority Element II.
//Memory Usage: 15.7 MB, less than 97.24% of C++ online submissions for Majority Element II.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>res;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int count=0;
        
        if(n==1)
        {
            res.push_back(nums[0]);
            return res;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
                
                if(count+1>(floor(n/3)) && find(res.begin(),res.end(),nums[i])==res.end())
                {
                    res.push_back(nums[i]);
                    
                }
            }
            else{
                count=0;
                 if(count+1>(floor(n/3)) && find(res.begin(),res.end(),nums[i])==res.end())
                {
                    res.push_back(nums[i]);
                    
                }
                
            }
        }
        
        if(count+1>(floor(n/3)) && find(res.begin(),res.end(),nums[nums.size()-1])==res.end())
        {
                    res.push_back(nums[nums.size()-1]);
                    
        }
        return res;
    }
};


// O(N) space complexity
// O(N) time complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>res;
        
        unordered_map<int,int>mp;
   
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            if(it.second>floor(n/3) && it.second!=-1)
            {
                res.push_back(it.first);
                it.second=-1;
                

            }
        }
        return res;
    }
};


// O(N) space complexity
// O(N) time complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>res;
        set<int>set1;
        
        unordered_map<int,int>mp;
   
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            if(it.second>floor(n/3) && set1.find(it.first)==set1.end())
            {
                res.push_back(it.first);
                set1.insert(it.first);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}