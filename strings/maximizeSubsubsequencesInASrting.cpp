#include<iostream>
using namespace std;

// TLE
// 127/172

class Solution {
public:
    long long maxOccurance(string text,string pattern)
    {
        char firstChar=pattern[0];
        char secondChar=pattern[1];
        int n=text.length();

        long long count=0;

        for(int i=0;i<text.length();i++)
        {
            if(text[i]!=firstChar)continue;

            for(int j=i+1;j<n;j++)
            {
                if(text[j]==secondChar)count++;
            }
        }
        return count;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long res=0;
         int n=text.length();
         long long maxRes=INT_MIN;

         char a=pattern[0];
         string a1;
         a1+=a;


         char b=pattern[1];
         string b1;
         b1+=b;

        // cout<<a1<<" "<<b1;
        
        for(int i=0;i<=n;i++)
        {
            string temp=text;
           
            temp.insert(i,a1);
            //cout<<temp<<" ";
            maxRes=max(maxRes,maxOccurance(temp,pattern));

            temp=text;
            temp.insert(i,b1);
            maxRes=max(maxRes,maxOccurance(temp,pattern));
        }



        return maxRes;
    }
};

int main()
{
    
    return 0;
}