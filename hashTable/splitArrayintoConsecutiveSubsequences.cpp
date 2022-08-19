#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


// Runtime: 221 ms, faster than 23.14% of C++ online submissions for Split Array into Consecutive Subsequences.
// Memory Usage: 61.3 MB, less than 15.47% of C++ online submissions for Split Array into Consecutive Subsequences.


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        
        unordered_map<int,int>freq;
        unordered_map<int,int>hypotheticalMap;
        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            // if freqeuncy is 0 continue
            
            if(freq[nums[i]]==0)continue;
            
            // find if the element exists
            
            if(hypotheticalMap.find(nums[i])==hypotheticalMap.end() || hypotheticalMap[nums[i]]==0)
            {
                // element not present in the map
                
                // the element along with itself takes next 2 element
                freq[nums[i]]--;
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                
                hypotheticalMap[nums[i]+3]++;
            }
            else{
                
                // if it is present in the hypothetical map, then it can join the subsequence
                freq[nums[i]]--;
                
                hypotheticalMap[nums[i]+1]++;
                
                hypotheticalMap[nums[i]]--;
            }
            
        }
        
        for(auto it:freq)
        {
            cout<<it.second<<" ";
            if(it.second!=0)return false;
        }
        
        return true;
    }
};



class Solution {
public:
    vector<int> getValue(map<int,vector<int>>kmap,int index)
    {
        map<int,vector<int>>::iterator itr=kmap.begin();
        advance(itr, index);
       return itr->second;
    }
    bool isPossible(vector<int>& nums) {
        
        
        int n=nums.size();
        
        map<int,vector<int>>kmap;
        
        kmap[0].push_back(nums[0]);
        
       
    
        
      int k=0;
        for(int i=1;i<n;i++)
        {  
             
            vector<int>vec1=getValue(kmap,k);
            
            if(nums[i]-vec1[vec1.size()-1]==1)
                kmap[k].push_back(nums[i]);
            
            else{
                int flag=0;
                cout<<kmap.size()<<" ";
                for(int j=0;j<kmap.size()-1;j++)
                {
                    vector<int>vec=getValue(kmap,i);
                    
                    if(nums[i]-vec[vec.size()-1]==1)
                    {
                        kmap[j].push_back(nums[i]);
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    k++;
                    kmap[k].push_back(nums[i]);
                }
            }
        }
        
        for(auto it:kmap)
        {
            for(int j=0;j<it.second.size();j++)cout<<it.second[j]<<" ";
            cout<<endl;
        }
        
       
        
        for(int i=0;i<kmap.size();i++)
        {
            vector<int>vec1=getValue(kmap,i);
            if(vec1.size()<3)return false;
        }
        
       
        return true;
    }
};


class Solution {
public:
    
    vector<int> getValue(map<int,vector<int>>kmap,int index)
    {
        map<int,vector<int>>::iterator itr=kmap.begin();
        advance(itr, index);
       return itr->second;
    }
    bool isPossible(vector<int>& nums) {
        
        
        int n=nums.size();
        
        map<int,vector<int>>kmap;
        
        kmap[0].push_back(nums[0]);
        
        int k=0;
        
        map<int,vector<int>>itr;
        
        for(int i=1;i<n;i++)
        {
            vector<int>vec1=getValue(kmap,k);
            
            if(nums[i]-vec1[vec1.size()-1]==1)
                kmap[k].push_back(nums[i]);
            
            else{
                k++;
                kmap[k].push_back(nums[i]);
            }
        }
        
        int flag=0;
        
        for(auto it:kmap)
        {
            cout<<it.second.size()<<" ";
            if(it.second.size()<3)flag=1;
        }
        if(flag==0)return true;
        
        return false;
    }
};

int main()
{
    
    return 0;
}