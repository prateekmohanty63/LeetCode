#include<iostream>
using namespace std;

//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int sum=0;
        
        if(N<M)return -1;
        
        for(int i=0;i<N;i++)sum+=A[i];
        
        int start=0;
        int end=sum;
        int res=INT_MAX;
        
        while(start<=end)
        {
            // maximum number of books that can 
            int mid=start+(end-start)/2;
            int currCount=0;
            int noStudents=1;
            int maxBooks=INT_MIN;
            
            for(int i=0;i<N;i++)
            {
                if(currCount+A[i]<=mid)
                {
                    currCount+=A[i];
                }
                else{
                    currCount=A[i];
                    noStudents++;
                }
                maxBooks=max(maxBooks,currCount);
            }
            
            if(noStudents>M)
            {
                start=mid+1;
            }
            else{
                 res=min(res,maxBooks);
                end=mid-1;
            }
            
        }
        return res;
        
    }
};

//{ Driver Code Starts.

// } Driver Code Ends

int main()
{
    
    return 0;
}