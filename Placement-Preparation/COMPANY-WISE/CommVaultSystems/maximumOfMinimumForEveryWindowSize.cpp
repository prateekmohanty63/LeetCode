#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution
{
    public:
    
    int solve(int arr[],int n,int windowSize)
    {
        if(windowSize==1)
        {
            int maxim=INT_MIN;
            for(int i=0;i<n;i++)maxim=max(maxim,arr[i]);
          
            
            return maxim;
        }
        if(windowSize==n)
        {
            int minim=INT_MAX;
            
            for(int i=0;i<n;i++)minim=min(minim,arr[i]);
            return minim;
        }
        
        int start=0;
        int end=windowSize-1;
        vector<int>vec;
        
        int minim=INT_MAX;
        int ind=-1;
        
        for(int i=start;i<=end;i++)
        {
           if(arr[i]<=minim)
           {
               minim=arr[i];
               ind=i;
           }
        }
        vec.push_back(minim);
        start++;
        end++;
        
        while(end<n)
        {
             if(arr[end]<=minim)
             {
                 minim=arr[end];
                 ind=end;
             }
             if(ind>=start && ind<=end)
             {
                 vec.push_back(arr[ind]);
             }
             else{
                 int mini=INT_MAX;
                 int in;
                for(int i=start;i<=end;i++)
                {
                    if(arr[i]<=mini)
                    {
                        mini=arr[i];
                        in=i;
                        
                    }
                }
                vec.push_back(mini);
                minim=mini;
                ind=in;
             }
             
             start++;
             end++;
             
        }
        
        int res=INT_MIN;
        // cout<<windowSize<<" ";
        
        // for(auto it:vec)cout<<it<<" ";
        // cout<<endl;
        
        for(auto it:vec)res=max(res,it);
        
        return res;
    }
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int>res;
        
        for(int i=1;i<=n;i++)
        {
            int a=solve(arr,n,i);
            res.push_back(a);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}