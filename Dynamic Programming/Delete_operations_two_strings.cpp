#include<iostream>
#include<map>
#include<vector>
using namespace std;

// Runtime: 54 ms, faster than 20.04% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 12.2 MB, less than 49.22% of C++ online submissions for Delete Operation for Two Strings.

class Solution {
public:
    int maxLength(string &word1,string &word2,int n,int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1));
         int result;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
             
                if(i==0 || j==0)
                    dp[i][j]=0;
                
                else if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return n+m-2*dp[n][m];
    }
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
       
        
        int maxSubsequence=maxLength(word1,word2,n,m);
        
        cout<<maxSubsequence;
        
        return maxSubsequence;
        
    }
};


// recursion gives TLE

class Solution {
public:
    int maxLength(string &word1,string &word2,int i,int j)
    {
        if(i==word1.length() || j==word2.length())return 0;
        
        // if equal
        
        if(word1[i]==word2[j])
        {
            return 1+maxLength(word1,word2,i+1,j+1);
        }
        
        // if not equal
        else{
            return max(maxLength(word1,word2,i+1,j),maxLength(word1,word2,i,j+1));
        }
    }
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        
        int maxSubsequence=maxLength(word1,word2,0,0);
        
        cout<<maxSubsequence;
        
        return m+n-2*maxSubsequence;
        
    }
};

// solution doesn't pass all test cases (926/1306)

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.length();
        int m=word2.length();
        int count=0;
        map<char,int>map1,map2;
        
        
        for(int i=0;i<n;i++)
        {
            map1[word1[i]]++;
        }
        
         for(int i=0;i<m;i++)
        {
            map2[word2[i]]++;
        }
        
        for(int i=0;i<m;i++)
        {
            auto it = map1.find(word2[i]);
            if(it==map1.end()){
                it->second=0;
                count++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            auto it=map2.find(word1[i]);
            if(it==map2.end()){
                it->second=0;
                count++;
            }
        }
       // if present
        map<char,int>::iterator itr;
        
        for(itr=map1.begin();itr!=map1.end();itr++)
        {
            char a=itr->first;
            auto it=map2.find(a);
            if(it!=map2.end())
            {
                count+=abs(itr->second-it->second);
                
                if(itr->second>it->second)
                {
                    it->second=0;
                    itr->second-=it->second;
                }
                else{
                    itr->second=0;
                    it->second-=itr->second;
                }
            }
        }
        
        // remaining characters
        string a,b;
        for(itr=map1.begin();itr!=map1.end();itr++)
        {
            if(itr->second!=0){
                a+=itr->first;
            }
        }
        
          for(itr=map2.begin();itr!=map2.end();itr++)
        {
            if(itr->second!=0){
                b+=itr->first;
            }
        }
        cout<<a<<" "<<b;
       return count;
        
    }
};

int main()
{
    
    return 0;
}