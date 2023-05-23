#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;


class Solution {
public:


    int maxim=INT_MIN;

    int asciiValue(string a)
    {
        int res=0;
        for(int i=0;i<a.length();i++)res+=int(a[i]);

        return res;
    }

    int maxSubSequence(string s1, string s2,int x,int y)
    {
        // your code here
        
        vector<vector<int>>vec(x+1,vector<int>(y+1));
        
        // initilization
        
      
        
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 || j==0)vec[i][j]=0;
                
                else if(s1[i-1]==s2[j-1])
                vec[i][j]=int(s1[i-1])+vec[i-1][j-1];
                
                else
                vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
            }
        }
        return vec[x][y];
    }
    int minimumDeleteSum(string s1, string s2) {
        
        
        if(s1==s2)return 0;
        set<string>vec1;

       int n=s1.length();
       int m=s2.length();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       
        
        int a=maxSubSequence(s1,s2,n,m);
        cout<<a<<" ";

        int b=asciiValue(s1);
        int c=asciiValue(s2);


        

        return (b-a)+(c-a);

    }
};

int main()
{
    
    return 0;
}