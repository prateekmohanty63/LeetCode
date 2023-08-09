#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solve(int n,vector<int>&vec)
{
    int noOnes=0;
    int noZeros=0;

    for(auto it:vec)
    {
        if(it==0)noZeros++;
        else noOnes++;
    }
    if(noOnes==0)return -1;
   int res=INT_MAX;
   
   int start=0;
   int end=noOnes-1;
   int currOnes=0;
   
   for(int i=start;i<=end;i++)
   {
       if(vec[i]==1)currOnes++;
   }
   
   res=min(res,noOnes-currOnes);
   end++;
   
   while(end<n)
   {
       if(vec[start]==1)currOnes--;
       if(vec[end]==1)currOnes++;
       
       res=min(res,noOnes-currOnes);
       
       start++;
       end++;
   }

    return res;
}

int minSwaps(int arr[], int n) {

    // Complete the function
    vector<int>vec;
    
    for(int i=0;i<n;i++)
    vec.push_back(arr[i]);
    
    int res=solve(n,vec);
    
    return res;
}

int main()
{
    
    return 0;
}