#include<iostream>
#include<map>
#include<vector>


/// OPtimized approach
/// Faster than 100%

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // TWO POINTER APPROACH
        
        if(nums.size()<3)return nums.size();
        
        int j=1,count=0;
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                count++;
                
                if(count<2){
                    nums[j]=nums[i];
                    j++;
                }
            }
            else{
                count=0;
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // TWO POINTER APPROACH
        
        if(nums.size()<3)return nums.size();
        
        int j=1,count=0;
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                count++;
                
                if(count<2){
                    nums[j]=nums[i];
                    j++;
                }
            }
            else{
                count=0;
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};

using namespace std;
// Approach-1
// Runtime: 12 ms, faster than 26.55% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 12 MB, less than 7.09% of C++ online submissions for Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        map<int,int>map1;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            map1[nums[i]]++;
        }
        int k=0;
       map<int,int>::iterator itr;
        
        for(itr=map1.begin();itr!=map1.end();itr++){
            if(itr->second>=2){
                count+=2;
                nums.insert(nums.begin()+k,itr->first);
                k++;
                nums.insert(nums.begin()+k,itr->first);
                k++;
            }
            else{
                count++;
                nums.insert(nums.begin()+k,itr->first);
                k++;
            }
        }
        cout<<count;
        return count;
    }
};