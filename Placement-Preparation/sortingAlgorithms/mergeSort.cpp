#include<iostream>
#include<vector>
using namespace std;

// The list of size N is divided into a max of Logn parts, 
// and the merging of all sublists into a single list takes O(N) time

// T(n)=O(nlogn)
// S(n)=O(n)

void merge(vector<int>&vec,int start,int end)
{
    int mid=start+(end-start)/2;

   

   int len1=mid-start+1;
   int len2=end-mid;

    vector<int>vec1(len1),vec2(len2);

   // copy values 
   int k=start;
   for(int i=0;i<len1;i++)
   {
      vec1[i]=vec[k++];
   }
   for(int i=0;i<len2;i++)
   {
       vec2[i]=vec[k++];
   }

    // merge the two sorted array 
    int ptr1=0;
    int ptr2=0;
    k=start;

    while(ptr1<vec1.size() && ptr2<vec2.size())
    {
        if(vec1[ptr1]<vec2[ptr2])
        {
             vec[k++]=vec1[ptr1++];
        }
        else{
             vec[k++]=vec2[ptr2++];
        }
    }

    while(ptr1<vec1.size())vec[k++]=vec1[ptr1++];

    while(ptr2<vec2.size())vec[k++]=vec2[ptr2++];
}

void mergeSort(vector<int>&vec,int start,int end)
{
    // base case 
    if(start>=end)return ;
     int mid=start+(end-start)/2;

    // sort the left part of the array 
    mergeSort(vec,start,mid);

    // sort the right part of the array 
    mergeSort(vec,mid+1,end);

    // merge both the arrays 
    merge(vec,start,end);
}

int main()
{
    vector<int>vec={2,5,1,6,9};
    int start=0;
    int end=vec.size()-1;
    mergeSort(vec,start,end);

    for(auto it:vec)cout<<it<<" ";
    return 0;
}