#include<iostream>
#include<climits>
using namespace std;


class Solution {
public:
    int longestContinuousSubstring(string s) {

        int n=s.length();
        if(n==1)return 1;
        int maxLen=INT_MIN;
        
        int start=0;
        int end=0;

        while(end+1<n)
        {
           if(s[end+1]-s[end]==1)
           {
               maxLen=max(maxLen,end+1-start);
           }
           else{
                start=end+1;
           }
           end++;
        }
        
        if(maxLen==INT_MIN)return 1;
        return maxLen+1;
    }
};

int main()
{
    
    return 0;
}