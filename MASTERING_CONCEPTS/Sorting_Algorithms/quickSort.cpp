#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int>&arr,int low,int right)
{
    
  int pivot=arr[right];
  int i=low-1;

  for(int j=low;j<=right-1;j++)
  {
     if(arr[j]<pivot){
         i++;
         swap(arr[i],arr[j]);
     }
  }

   // return the partioning position 
  
    swap(arr[i+1],arr[right]);
   return (i+1);
}


void quickSort(vector<int>&arr,int low,int high)
{
    if(low<high){
        int j=partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

int main()
{
    vector<int>vec={4,3,2,-1,6,5};
    quickSort(vec,0,5);

    for(auto it:vec)
    cout<<it<<" ";
    return 0;
}