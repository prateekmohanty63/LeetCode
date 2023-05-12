#include<iostream>
#include<algorithm>
using namespace std;

// T(N):O(nlogn)

 int binSearch(int arr[],int n,int target)
  {
      int start=0;
      int end=n-1;
      
      while(start<=end)
      {
          int mid=start+(end-start)/2;
          
          if(arr[mid]==target)return mid;
          
          else if(target>arr[mid])
          {
              start=mid+1;
          }
          else end=mid-1;
      }
      return -1;
  }

	int findKRotation(int arr[], int n) {
	    // code here
	    
	    int firstEle=arr[0];
	    sort(arr,arr+n);
	    
	    int sortedArrayIndex=binSearch(arr,n,firstEle);
	   // cout<<sortedArrayIndex<<" ";
	    
	    if(sortedArrayIndex==0)return 0;
	    return (n-sortedArrayIndex);
	    
	}


int main()
{
    
    return 0;
}