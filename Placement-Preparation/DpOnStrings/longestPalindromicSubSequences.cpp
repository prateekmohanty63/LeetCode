#include<iostream>
#include<set>
using namespace std;


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