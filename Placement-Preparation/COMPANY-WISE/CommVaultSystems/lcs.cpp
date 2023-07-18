#include<iostream>
#include<vector>
using namespace std;

int solve(string a,string b,int i,int j)
{
    // base case
   int n=a.length();
   int m=b.length();
   int res=0;

   vector<vector<int>>mat(n+1,vector<int>(m+1,0));

   for(int i=0;i<n;i++)
   {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)mat[i][j]=0;

            else if(a[i]==b[j])
            {
                mat[i][j]=1+mat[i-1][j-1];
                res=max(res,mat[i][j]);
            }
            else{
                mat[i][j]=0;
            }
        }
       
   }
   return res;
}

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    int res=solve(a,b,n,m);
    cout<<res;
    return 0;
}