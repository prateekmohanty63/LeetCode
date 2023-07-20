#include<iostream>
using namespace std;


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        
        int rmax=INT_MIN;
        int cmax=INT_MIN;
        vector<int>rowSum;
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            
            for(int j=0;j<n;j++)
            {
                sum+=matrix[i][j];
            }
            rmax=max(rmax,sum);
            rowSum.push_back(sum);
            sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[j][i];
            }
            cmax=max(cmax,sum);
        }
        
        int res=0;
        int maxim=max(rmax,cmax);
        
        for(auto it:rowSum)
        {
            res+=(maxim-it);
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends

int main()
{
    
    return 0;
}