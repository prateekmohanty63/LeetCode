#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


int aux(vector<vector<int>>&A,int index,int prevColor,vector<vector<int>>&dp)
{
   
    // base case
    int n=A.size();
    
    if(index>=n)return 0;
    
    int ans=INT_MAX;

    if(dp[index][prevColor+1]!=-1)return dp[index][prevColor+1];
    
 //  cout<<"IN";
    
   
    if(prevColor==-1)
    {
        // we have all 3 options 
        int red=A[index][0]+aux(A,index+1,1,dp);
        int blue=A[index][1]+aux(A,index+1,2,dp);
        int green=A[index][2]+aux(A,index+1,3,dp);
        
        ans=min({ans,red,blue,green});
    }
    else{
        
        if(prevColor==1)
        {
            int blue=A[index][1]+aux(A,index+1,2,dp);
            int green=A[index][2]+aux(A,index+1,3,dp);
            ans=min({ans,blue,green});
        
        }
        else if(prevColor==2)
        {
            int red=A[index][0]+aux(A,index+1,1,dp);
            int green=A[index][2]+aux(A,index+1,3,dp);
            ans=min({ans,red,green});
        }
        else{
             int red=A[index][0]+aux(A,index+1,1,dp);
            int blue=A[index][1]+aux(A,index+1,2,dp);
            ans=min({ans,red,blue});
        }
    }
    
    return dp[index][prevColor+1]=ans;
}




int main()
{
    vector<vector<int>>A={{1,2,3},{10,11,12}};
    int n=A.size();

    vector<vector<int>>dp(n+1,vector<int>(5,-1));
    
    int res=aux(A,0,-1,dp);
    cout<<res;
    
   
    return 0;
}