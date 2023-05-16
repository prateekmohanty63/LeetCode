#include<iostream>
#include<vector>
using namespace std;


// Brute force approach 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size(); 

        for(int i=1;i<n;i++)
        {
            int currNum=arr[i];
            int flag=0;

            for(int j=0;j<i;j++)
            {   
                if(j+1<n){
                if(arr[j+1]<=arr[j])flag=1;
                }
            }
            for(int j=i;j<n;j++)
            {
                if(j+1<n)
                if(arr[j]<=arr[j+1])flag=1;
            }
            if(flag==0)return i;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}