#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>&mat,int x,int y,vector<vector<int>>&dp)
{
    // base case 

    int n=mat.size();

   // if(x==n-1 &&  y==n-1)return mat[x][y]>=1;

    if(x<0 || x>=n)return 0;

    if(y<0 || y>=n)return 0;

    if(dp[x][y]!=-1)return dp[x][y];

    int ans=0;

    // we have the option of mooving right and down
    
    if(mat[x][y]>=1)
    {
        ans=max(ans,max(1+solve(mat,x-1,y,dp),1+solve(mat,x,y-1,dp)));
    }
    else if(mat[x][y]==0)
    {
        ans=max(ans,max(solve(mat,x-1,y,dp),solve(mat,x,y-1,dp)));
    }
    return dp[x][y]=ans;
}

int main()
{
    
    int n;
    cin>>n;

    vector<vector<int>>mat;
    
    for(int i=0;i<n;i++)
    {
        vector<int>vec;
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
        }
        mat.push_back(vec);
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));


    // moving from top to bottom

    int a=solve(mat,n-1,n-1,dp);
   cout<<a;
   cout<<endl;

    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp.size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // marking the max path as 0
   cout<<endl;

       int i = n-1, j = n-1;
    while(i>=0 and j>=0){
        mat[i][j] = 0;
        if(i-1>=0 and j-1>=0){
            if(mat[i-1][j] > mat[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        else if(i == 0) j--;
        else i--;
    }

    cout<<endl;

   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        dp[i][j]=-1;
    }
   }

   int b=solve(mat,n-1,n-1,dp);

   cout<<endl;

   cout<<a+b;

   
    return 0;
}