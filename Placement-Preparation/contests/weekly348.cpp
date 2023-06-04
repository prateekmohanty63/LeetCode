#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// 1.minimum string left
class Solution {
public:
    int minimizedStringLength(string s) {
        
        int n=s.length();
        
       vector<char>vec;
        unordered_map<char,bool>mp;
        
        
        for(int i=0;i<n;i++)
        {
            char currChar=s[i];
            if(mp.find(currChar)==mp.end())
            {
                vec.push_back(currChar);
                mp[currChar]=true;
            }
        }
        return mp.size();
    }
};

// 2. Semi-Ordered Permutation
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        if(nums[0]==1 && nums[n-1]==n)return 0;
        
        int pos1=-1;
        int posn=-1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)pos1=i;
            
            if(nums[i]==n)posn=i;
        }
        
        if(pos1<posn)return (pos1-0)+((n-1)-posn);
        
        else{
            return (pos1-0)+((n-1)-posn)-1;
        }
        
    }
};

int main()
{
    
    return 0;
}