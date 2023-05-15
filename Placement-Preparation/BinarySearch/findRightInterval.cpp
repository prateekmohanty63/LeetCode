#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    int binSearch(vector<int>&vec,int target)
    {
       int start=0;
       int end=vec.size()-1;
       int n=vec.size();
       int minDiff=INT_MAX;
       int resInd=-1;
       

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(vec[mid]==target)return mid;

           if(target>vec[mid])
           {
              start=mid+1;
           }
           else{
               
               if(mid-1>=0 && target<vec[mid-1])
               {
                   if(vec[mid-1]-target<=minDiff)
                   {
                       resInd=mid-1;
                       minDiff=vec[mid-1]-target;
                   }
               }
               if(vec[mid]-target<=minDiff)
               {
                  resInd=mid;
                  minDiff=vec[mid]-target;
               }
               end=mid-1;
           }
       }
       return resInd;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[intervals[i][0]]=i;
        }
       // sort(intervals.begin(),intervals.end());

        vector<int>res;

        if(n==1)return {-1};

        vector<int>vec;

        for(int i=0;i<n;i++)
        {
            vec.push_back(intervals[i][0]);
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++)
        {
            if(intervals[i][0]>=intervals[i][1])
            {
                res.push_back(mp[intervals[i][0]]);
            }
            else{
                int ind=binSearch(vec,intervals[i][1]);
                if(ind==-1)res.push_back(-1);

                else{
                int ele=vec[ind];
                 res.push_back(mp[ele]);
                }
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}