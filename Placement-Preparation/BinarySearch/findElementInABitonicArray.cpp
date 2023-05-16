#include<iostream>
#include<vector>
using namespace std;


// index of peak element 
int findBiTonicPoint(vector<int>&vec)
{
    int start=0;
    int end=vec.size()-1;
    int n=vec.size();

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(mid-1>=0 && mid+1<n && vec[mid]>vec[mid-1] && vec[mid]>vec[mid+1])return mid;

        else if(mid+1<n && vec[mid+1]>vec[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }     
  return -1;
}

int increasingBinarySearch(vector<int>&vec,int start,int end,int  target)
{
    int left=start;
    int right=end;

    while(left<=right)
    {
        int mid=left+(right-left)/2;

        if(vec[mid]==target)return mid;

        else if(vec[mid]<target)
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int descreasingBinarySearch(vector<int>&vec,int start,int end,int target)
{
    int left=start;
    int right=end;

    while(left<=right)
    {
        int mid=left+(right-left)/2;

        if(vec[mid]==target)return mid;

        else if(vec[mid]<target)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

int main()
{
    vector<int>vec={-3, 9, 18, 20, 17, 5, 1};
    int point=findBiTonicPoint(vec);

    int ind=increasingBinarySearch(vec,0,point,20);
    int ind1=descreasingBinarySearch(vec,point,vec.size()-1,20);

    if(ind!=-1)cout<<ind;

    else if(ind1!=-1)cout<<ind1;

    else cout<<-1;
    return 0;
}