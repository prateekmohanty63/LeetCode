#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
   
   int floorEle(vector<int>&arr,int target)
   {
       int start=0;
       int end=arr.size()-1;
       int minDiff=INT_MAX;
       int indexEle=-1;
       int n=arr.size();

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(arr[mid]==target)return mid;

           if(target>arr[mid])
           {
               if(mid+1<n && target>arr[mid+1])
               {
                   indexEle=mid+1;
                   minDiff=target-arr[mid+1];
               }
              if(target-arr[mid]<=minDiff)
              {
                  indexEle=mid;
                  minDiff=target-arr[mid];
              }
              start=mid+1;
           }
           else{
             end=mid-1;
           }
       }
       return indexEle;
   }

   int ceilEle(vector<int>&vec,int target)
   {
       int start=0;
       int end=vec.size()-1;
       int minDiff=INT_MAX;
       int indexEle=-1;

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
                       minDiff=vec[mid-1]-target;
                       indexEle=mid-1;
                   }
               }
               if(vec[mid]-target<=minDiff)
               {
                   minDiff=vec[mid]-target;
                   indexEle=mid;
               }
               end=mid-1;
           }
       }
       return indexEle;
   }
 
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>res;

        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX;
        int n=arr.size();
     

        for(int i=0;i<n-1;i++)
        {
            if(i==0)
            {
                minDiff=min(minDiff,arr[i+1]-arr[i]);
            }
            else if(i>0 && i<n-1)
            {
                minDiff=min(minDiff,abs(arr[i]-arr[i+1]));
                minDiff=min(minDiff,abs(arr[i]-arr[i-1]));
            }
            
        }

        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]-arr[i]==minDiff)
            {
                vector<int>vec;
                vec.push_back(arr[i]);
                vec.push_back(arr[i+1]);
                res.push_back(vec);
            }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}