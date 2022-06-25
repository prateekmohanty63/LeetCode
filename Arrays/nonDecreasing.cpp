#include<iostream>
#include<vector>
using namespace std;


// Runtime: 40 ms, faster than 52.66% of C++ online submissions for Non-decreasing Array.
// Memory Usage: 29.5 MB, less than 5.88% of C++ online submissions for Non-decreasing Arr

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n=nums.size();
        
        // check if array is already non decreasing
        vector<int>vec1=nums;
        vector<int>vec2=nums;
        vector<int>vec3=nums;
        
        int count=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]-nums[i+1]>0)
            {
                count++;
                if(count>1)return false;
                
                int a=(vec1[i]-vec1[i+1]);
                vec1[i]-=a;
                vec2[i+1]+=a;
                
                
            }
        }
        
        if(count==0)return true;
       
        int flag=0;
        
        for(int i=0;i<n;i++)
        {
            cout<<vec1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<vec2[i]<<" ";
        }
        for(int i=0;i<n-1;i++)
        {
            if(vec1[i]-vec1[i+1]>0)flag+=1;
        }
         for(int i=0;i<n-1;i++)
        {
            if(vec2[i]-vec2[i+1]>0)flag+=1;
        }
        //cout<<flag;
        
        if(flag<2)return true;
      

        
        return false;
   }
};

int main()
{
    
    return 0;
}