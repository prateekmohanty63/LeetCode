#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int minimumDeletions(string a) {
        
         int n=a.length();

        vector<int>totalAs(n,0);
        if(a[n-1]=='a')totalAs[n-1]=1;
        else totalAs[n-1]=0;

        for(int i=n-2;i>=0;i--)
        {
            if(a[i]=='a')totalAs[i]=1+totalAs[i+1];

            else totalAs[i]=totalAs[i+1];
        }

        // for(auto it:totalAs)
        // cout<<it<<" ";

        int res=INT_MAX;

        int prevBCount=0;

        for(int i=0;i<n;i++)
        {
            if(a[i]=='b')
            {
                // if we leave this B as it is 
                // then we have to change all a's after this position to b
                // similarily we will have to change all b's before that index to a

                res=min(res,totalAs[i]+prevBCount);
                prevBCount++;
            }
        }
        
        // change all B's in string to A
        res=min(res,prevBCount);
        if(res==INT_MAX)return 0;

        return res;
    }
};

int main()
{
    
    return 0;
}