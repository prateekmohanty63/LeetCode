
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
         vector<double>val;
         int res=0;
         
         for(int i=0;i<n;i++)
         {
             double frac=(double)(numerator[i])/(double)denominator[i];
             val.push_back(frac);
         }
         sort(val.begin(),val.end());
         unordered_map<double,int>freq;
         
         for(auto it:val){
             freq[it]++;
         }
        
         int start=0;
         int end=n-1;
         
         while(start<end)
         {
             double value=val[start]+val[end];
           //  cout<<value<<endl;
             
             if(value==1)
             {
                // cout<<"IN";
                 if(val[start]==val[end])res+=(freq[val[start]]*(freq[val[end]]-1))/2;
                 
                 else
                 res+=(freq[val[start]]*freq[val[end]]);
                 
                 double currStart=val[start];
                 double currEnd=val[end];
                 
                 while(start<n && val[start]==currStart)start++;
                 while(end>=0 && val[end]==currEnd)end--;
             }
             else if(value<1)
             start++;
             
             else end--;
         }
         
         return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends

int main()
{
    
    return 0;
}