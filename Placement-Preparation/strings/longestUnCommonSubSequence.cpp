#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
   
    bool isSubSequence(string a,string b,int i,int j)
    {
        // base case
        if(i==0)return true;

        if(j==0)return false;


        if(a[i-1]==b[j-1])return isSubSequence(a,b,i-1,j-1);

        return isSubSequence(a,b,i,j-1);
    }

    int findLUSlength(vector<string>& strs) {
        
        int maximLen=INT_MIN;
        int n=strs.size();
        
        for(int i=0;i<n;i++)
        {
            string a=strs[i];
            int len=a.length();
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     if(isSubSequence(a,strs[j],a.length(),strs[j].length()))
                     {
                         flag=1;
                         break;
                     }
                }
            }
            if(flag==0)maximLen=max(maximLen,len);
        }
        
        if(maximLen==INT_MIN)return -1;
        return maximLen;
    }
};

int main()
{
    
    return 0;
}
