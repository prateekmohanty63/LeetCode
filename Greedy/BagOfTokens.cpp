#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Runtime: 17 ms, faster than 15.52% of C++ online submissions for Bag of Tokens.
//Memory Usage: 10.6 MB, less than 66.86% of C++ online submissions for Bag of Tokens.

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        if(power==0 || tokens.size()==0)return 0;
        
        sort(tokens.begin(),tokens.end());
        
        int n=tokens.size();
        
        int largestScore=0;
        
        int start=0,end=n-1;
        
        int score=0;
        
        // edge case  ( if initial power is less than the least power required return 0 )
        
        if(power<tokens[start])return 0;
        
       while(start<=end)
       {
           if(power>=tokens[start])
           {
               score++;
               power-=tokens[start];
               start++;
           }
           else if(power<tokens[start] && score>0)
           {
               power+=tokens[end];
               score--;
               end--;
           }
           else{
               end--;
           }
           largestScore=max(largestScore,score);
       }
        
        
        return largestScore;
    }
};

int main()
{
    
    return 0;
}