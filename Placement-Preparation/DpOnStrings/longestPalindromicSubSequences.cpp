#include<iostream>
#include<vector>
#include<set>
using namespace std;


// T(n)=O(n*n)
// s(n)=O(n*n)
class Solution {
public:
   
     int longestPalindSubseqRec(vector<vector<int> >& dp, string& s, int i, int j) {
        if(i > j)
            return 0;
        // when one char
        if(i == j)
            return dp[i][j] = 1;
        
        if(dp[i][j] == -1) {
            if(s[i] == s[j])
                dp[i][j] = 2 + longestPalindSubseqRec(dp, s, i+1, j-1);
            else
                dp[i][j] = max(longestPalindSubseqRec(dp, s, i+1, j),
                               longestPalindSubseqRec(dp, s, i, j-1));
        }
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        
        int n=s.length();
        string a=s;
        //reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return longestPalindSubseqRec(dp,s,0,n-1);
    }
};


// TLE 
// O(n^2) + O(2^n)
class Solution {
public:
  
set<string>set1;

bool isPali(string s)
{
    int start=0;
    int end=s.length()-1;

    while(start<=end)
    {
        if(s[start]!=s[end])return false;

        start++;
        end--;
    }
    return true;
}

void generateSubSequences(string input,string output)
 {
     if(input.empty())
     {
         set1.insert(output);
         return ;
     }

    // ith element is taken
     generateSubSequences(input.substr(1),output+input[0]);

   // ith element is not taken

   generateSubSequences(input.substr(1),output);
 }
    int longestPalindromeSubseq(string s) {
        
        int n=s.length();

        int res=0;
        string output="";
        generateSubSequences(s,output);

        for(auto it:set1)
        {
            cout<<it<<" ";
            if(isPali(it))
            {
                int a=it.length();
                res=max(res,a);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}