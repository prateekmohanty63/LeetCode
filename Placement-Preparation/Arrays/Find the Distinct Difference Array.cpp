#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>prefix(n),suffix(n),res;
        unordered_map<int,int>freq,freq1;
        
        prefix[0]=1;
        freq[nums[0]]=1;
        
        for(int i=1;i<n;i++)
        {
            freq[nums[i]]++;
            
            prefix[i]=freq.size();
        }
        
        for(auto it:prefix)cout<<it<<" ";
        cout<<endl;
        
        for(int i=n-1;i>=1;i--)freq1[nums[i]]++;
       
        suffix[0]=freq1.size();
        
        for(int i=1;i<n;i++)
        {
            freq1[nums[i]]--;
            if(freq1[nums[i]]==0)freq1.erase(nums[i]);
            
            suffix[i]=freq1.size();
            
        }
        
    for(auto it:suffix)cout<<it<<" ";
        for(int i=0;i<n;i++)
        {
            res.push_back(prefix[i]-suffix[i]);
        }
        cout<<endl;
        return res;
    }
};

int main()
{
    
    return 0;
}