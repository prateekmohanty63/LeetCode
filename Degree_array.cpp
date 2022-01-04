#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        if(nums.size()==1)
            return 1;
        
        vector<int>vec1=nums;
        
        int max=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
                max=nums[i];
        }
        
        vector<int>num1(max+1,0);
        
        for(int i=0;i<n;i++)
        {
            num1[nums[i]]++;
        }
        int num_degree=-1;     
        int degree=-1;
        for(int i=0;i<num1.size();i++){
            if(num1[i]>=degree)
            {
                degree=num1[i];
                num_degree=i;
                
            }
        }
        
        int start=-1,end=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num_degree){
                start=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==num_degree){
                end=i;
                break;
            }
        }
        
        return (end-start)+1;
    }
};


/// 2nd approach

