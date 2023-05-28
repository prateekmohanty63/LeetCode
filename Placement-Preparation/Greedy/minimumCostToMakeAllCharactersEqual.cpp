#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        
        // storing index's where inversion should be done 
        vector<int>invArr;
        int n=s.length();
        long long ans=LLONG_MAX;
        
        for(int i=0;i<n;i++)
        {
            int k=i;
            while(k<n && s[i]==s[k])k++;
            invArr.push_back(k-1);
            i=k-1;
        }
        
        int m=invArr.size();
        
        vector<long long>preFix(m,0),suffix(m,0);
        
        // storing the prefix array (cost if 1st operation is done)
        preFix[0]=invArr[0]+1;
        for(int i=1;i<m;i++)
        {
            preFix[i]=preFix[i-1]+(invArr[i]+1);
        }
        
        // storing the suffix array (cost if the 2nd operation is done)
        suffix[m-1]=n-(invArr[m-1]+1);
        for(int i=m-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+(n-(invArr[i]+1));
        }
        
        for(int i=0;i<m-1;i++)
        {
            long long a=preFix[i]+suffix[i+1];
            ans=min(ans,a);
        }
        ans=min(ans,min(preFix[m-1],suffix[0]));
        
        for(auto it:invArr)cout<<it<<" ";
        
        return ans;
    }
};

int main()
{
    
    return 0;
}