#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
   
   int maxLines(vector<int>&nums1,unordered_map<int,vector<int>>&pos,int i,int &minPosLine,vector<vector<int>>&dp)
   {
       // base case
       if(i>=nums1.size())return 0;

       int ele=nums1[i];

       if(dp[i][minPosLine+1]!=-1)return dp[i][minPosLine+1];

       // if element in not present in the map , we cannot make a line , we proceed ahead

       if(pos.find(ele)==pos.end())
       return dp[i][minPosLine+1]=maxLines(nums1,pos,i+1,minPosLine,dp);

       // if element is present in the map , we have various choices

       // we can only make a non-intersecting line 

      int minNotIntersecting=INT_MAX;

      for(auto it:pos[ele])
      {
        
          if(it>minPosLine)
         {
              minNotIntersecting=min(minNotIntersecting,it);
          }
          
      }

      // we have the option of making a line or not making a line once match is found

      if(minNotIntersecting!=INT_MAX)
       return dp[i][minPosLine+1]=max(1+maxLines(nums1,pos,i+1,minNotIntersecting,dp),maxLines(nums1,pos,i+1,minPosLine,dp));

       else return dp[i][minPosLine+1]=maxLines(nums1,pos,i+1,minPosLine,dp);
   }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,vector<int>>pos,pos1;
        
        int m=nums2.size();
        int n=nums1.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<vector<int>>dp1(m+1,vector<int>(n+1,-1));


        for(int i=0;i<nums2.size();i++)
        {
            
            pos[nums2[i]].push_back(i);
        }

        for(int i=0;i<nums1.size();i++)
        {
            pos1[nums1[i]].push_back(i);
        }
        int minPos=-1;
        int minPos1=-1;
       // cout<<maxLines(nums1,pos,0,-1)<<" "<<maxLines(nums2,pos1,0,-1);
        return max(maxLines(nums1,pos,0,minPos,dp),maxLines(nums2,pos1,0,minPos1,dp1));
    }
};

int main()
{
    
    return 0;
}