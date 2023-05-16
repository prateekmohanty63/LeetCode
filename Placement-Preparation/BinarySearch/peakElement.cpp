#include<iostream>
#include<vector>
using namespace std;


int binSearch(vector<int>&vec)
{
    int start=0;
    int end=vec.size()-1;
    int n=vec.size();

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(mid==0 && vec[mid]>vec[mid+1])return vec[mid];

        else if(mid==n-1 && vec[mid]>vec[mid-1])return vec[mid];

        else if(mid+1<n && mid-1>=0 && vec[mid]>vec[mid+1] && vec[mid]>vec[mid-1])return vec[mid];

        else if(vec[mid-1]<vec[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int>vec={5,10,20,15};
    vector<int>vec1={1,5,3,5,1,5,4};
    cout<<binSearch(vec1);
    return 0;
}