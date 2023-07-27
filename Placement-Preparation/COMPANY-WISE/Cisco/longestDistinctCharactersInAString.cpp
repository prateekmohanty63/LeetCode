#include<iostream>
using namespace std;

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int start=0;
    int end=1;
    int n=S.length();
    int res=INT_MIN;
    
    if(n==0)return 0;
    
    unordered_map<char,int>mp;
    mp[S[start]]++;
    
    while(end<n)
    {

        mp[S[end]]++;
        
        if(mp[S[end]]==2)
        {
            while(start<end && S[start]!=S[end])
            {
                mp[S[start]]--;
                start++;
            }
            mp[S[start]]--;
            start++;
        
            
        }
        res=max(res,end-start+1);
        end++;
        
    }
    return res;
}

int main()
{
    
    return 0;
}