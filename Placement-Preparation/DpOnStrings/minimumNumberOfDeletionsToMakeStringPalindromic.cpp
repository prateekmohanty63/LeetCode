#include<iostream>
#include<algorithm>
using namespace std;


int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int maxPali(string s,int m)
{
    string a=s;
    reverse(s.begin(),s.end());
    int n=m;
    
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)dp[i][0]=0;
    
    for(int i=0;i<=n;i++)dp[0][i]=0;
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==s[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int minDeletions(string str, int n) { 
    //complete the function here 
    
    return abs(n-maxPali(str,n));
} 

int main()
{
    
    return 0;
}