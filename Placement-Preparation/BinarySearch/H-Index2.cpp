#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// T(n)=O(logn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int start=0;
        int end=citations.size()-1;
        int maxRes=-1;
        int n=citations.size();

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(citations[mid]>=n-mid)
            {
                maxRes=max(maxRes,n-mid);
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        if(maxRes==-1)return 0;
        return maxRes;
    }
};


// T(N)=O(nlogn)
class Solution {
public:
   
   // finding the ceil value we get 

int binSearch(vector<int>&vec,int target)
   {
       int start=0;
       int end=vec.size()-1;
       int ceilIndex=INT_MAX;
       int minDiff=INT_MAX;

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(vec[mid]==target)
           {
               if(target-vec[mid]<=minDiff)
               {
                   minDiff=target-vec[mid];
                   ceilIndex=min(ceilIndex,mid);
               }
               end=mid-1;
           }

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
                     ceilIndex=min(ceilIndex,mid-1);
                  }
              }
              if(vec[mid]-target<=minDiff)
              {
                  minDiff=vec[mid]-target;
                  ceilIndex=min(ceilIndex,mid);
              }
               end=mid-1;
           }
       }
       return ceilIndex;
   }



    int hIndex(vector<int>& citations) {
         int n=citations.size();

         int temp=n;

         while(temp!=0)
         {
             int ind=binSearch(citations,temp);
             if(n-ind>=temp)return temp;

             temp--;
         }
         return 0;
    }
};

int main()
{
    
    return 0;
}