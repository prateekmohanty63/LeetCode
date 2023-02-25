#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
   
   bool isTurbulent(vector<int>&arr,int left,int right)
   {
      // if(left==right)return true;

       if(arr[left]==arr[left+1])return false;

       if(arr[left]>arr[left+1])
       {
           int k=0;
          for(int i=left+1;i<right;i++)
          {
              if(k%2==0)
              {
                  if(arr[i]>=arr[i+1])return false;
              }
              else{
                  if(arr[i]<=arr[i+1])return false;
              }
              k++;
          }
       }
       else{
           int k=0;
          for(int i=left+1;i<right;i++)
          {
              if(k%2==0)
              {
                  if(arr[i]<=arr[i+1])return false;
              }
              else{
                  if(arr[i]>=arr[i+1])return false;
              }
              k++;
          }
       }
     return true;
    }
   

    int maxTurbulenceSize(vector<int>& arr) {
        
        int start=0,end=0;
        int maxSize=INT_MIN;

        int n=arr.size();

        if(n==1)return 1;

        if(n==2)
        {
            if(arr[0]<arr[1])return 2;

            if(arr[0]>arr[1])return 2;

            return 1;
        }

        while(end<arr.size())
        {
            if(isTurbulent(arr,start,end))
            {
                  maxSize=max(maxSize,(end-start)+1);
                //  cout<<start<<" "<<end<<endl;
                end++;
            }
            else{
              
                start++;
                end=start+1;
                
            }
        }

      // cout<<maxSize;
       if(maxSize==INT_MIN)return 1;
        //maxSize=max(maxSize,end-start);
        return maxSize;
    }
};

int main()
{
    
    return 0;
}