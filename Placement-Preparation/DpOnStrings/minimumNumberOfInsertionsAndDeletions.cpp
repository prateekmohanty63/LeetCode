#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;


// } Driver Code Ends
class Solution{
		
    int lcs(string str1,string str2,int i,int j,vector<vector<int>>&dp)
    {
        int n=str1.length();
        int m=str2.length();
        
        if(i>=n || j>=m)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(str1[i]==str2[j])
        {
            return dp[i][j]=1+lcs(str1,str2,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=max(lcs(str1,str2,i+1,j,dp),lcs(str1,str2,i,j+1,dp));
        }
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length();
	    int m=str2.length();
	    
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    
	    int maxLcs=lcs(str1,str2,0,0,dp);
	    
	    return abs(str1.length()-maxLcs)+abs(str2.length()-maxLcs);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends

int main()
{
    
    return 0;
}