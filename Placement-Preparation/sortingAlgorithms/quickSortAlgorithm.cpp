#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&vec,int s,int e)
{
    // choosing the pivot element 
    int pivot=vec[s];

    int cnt=0;

    for(int i=s+1;i<=e;i++)
    {
        if(vec[i]<=pivot){
            cnt++;
        }
    }
     
     // place pivot index at correct position
    int pivotIndex=s+cnt;
    swap(vec[pivotIndex],vec[s]);

    // keep all smaller to left of pivot and all greater to right of pivot
    int i=s,j=e;

    while(i<pivotIndex && j>pivotIndex){
     
     // search for greater element in the left part 
     while(vec[i]<=pivot)i++;

     // search for smaller element in the right part
     while(vec[j]>pivot)j--;

     // now swap 
     if(i<pivotIndex && j>pivotIndex)swap(vec[i++],vec[j--]);
        
    }

   return pivotIndex;

}

void quickSort(vector<int>&vec,int s,int e)
{
    // base case
    if(s>=e)return ;

    // partition index (correct position of the pivot element)
    int p=partition(vec,s,e);

    // left part sort 
    quickSort(vec,s,p-1);

    // right part sort 
    quickSort(vec,p+1,e);
}

int main()
{
    vector<int>vec={3,2,4,5,1,4,7,9};
    int n=vec.size();
    quickSort(vec,0,n-1);

    for(auto it:vec)cout<<it<<" ";
    return 0;
}