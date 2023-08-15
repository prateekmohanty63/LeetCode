//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>mp;
        
        for(auto it:str)mp[it]++;
        
        int noChars=mp.size();
        int n=str.length();
        int res=INT_MAX;
        
        if(noChars==1)return 1;
        
        int start=0;
        int end=noChars-1;
        
        unordered_map<char,int>temp;
        for(int i=start;i<=end;i++)
        temp[str[i]]++;
        
        while(end<n)
        {
            if(temp.size()==noChars)
            {
                while(start<=end && temp.size()==noChars)
                {
                    temp[str[start]]--;
                    if(temp[str[start]]==0)temp.erase(str[start]);
                    start++;
                }
                res=min(res,end-start+2);
            }
             end++;
             
            if(end<n)
            temp[str[end]]++;
          
        }
        return res;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
   
}
// } Driver Code Ends