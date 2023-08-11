#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
  public:
    int lastOccuranceOfElement(int arr[],int target,int n)
    {
        int start=0;
        int end=n-1;
        int ind=-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(arr[mid]==target)
            {
                ind=mid;
                start=mid+1;
            }
            else if(target>arr[mid])
            {
                ind=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
        }
        return ind;
    }
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
    //Your code goes here
        
        // sorting the 2nd array
        sort(arr2,arr2+n);
        vector<int>res;
        
        for(int i=0;i<m;i++)
        {
            int target=arr1[i];
            
            if(target>=arr2[n-1])
            res.push_back(n);
            
            else{
                int ind=lastOccuranceOfElement(arr2,target,n);
                res.push_back(ind+1);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}