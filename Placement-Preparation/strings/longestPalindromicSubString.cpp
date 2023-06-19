#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();

        int maxLen=INT_MIN;
        string res;
        
        for(int i=0;i<n-1;i++){
            
            int currIndex=i;
            int prevIndex=i-1;
            int nextIndex=i+1;
            
            // odd length palindrome
            while(prevIndex>=0 && nextIndex<n && s[prevIndex]==s[nextIndex]){
               prevIndex--;
               nextIndex++;
            }
            
            if(nextIndex-prevIndex-1>maxLen){
               maxLen=max(maxLen,nextIndex-prevIndex-1);
               res=s.substr(prevIndex+1,maxLen);
            }
           

            // even length palindrome
            currIndex=i;
            nextIndex=i+1;

            while(currIndex>=0 && nextIndex<n && s[currIndex]==s[nextIndex]){
                currIndex--;
                nextIndex++;
            }
            if(nextIndex-currIndex-1>maxLen){
                cout<<"IN";
               maxLen=max(maxLen,nextIndex-currIndex-1);
               res=s.substr(currIndex+1,maxLen);
            }
        }
        cout<<maxLen;
        if(maxLen==INT_MIN){
            string res;
            res+=s[0];
            return res;
        }
        return res;

    }
};

int main()
{
    
    return 0;
}