#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// T(N)=O(n*n*26)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        
        int maxProd=INT_MIN;
        vector<int>checkDup(26,0);

        for(int i=0;i<n;i++)
        {
            string a=words[i];
            for(auto it:a)
            checkDup[it-'a']++;
            
            for(int j=i+1;j<n;j++)
            {
                string b=words[j];
                int flag=0;
                for(auto itr:b)
                {
                    if(checkDup[itr-'a']!=0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    int n=a.length();
                    int m=b.length();
                    maxProd=max(maxProd,n*m);
                }
            }
            for(int i=0;i<26;i++)checkDup[i]=0;
        }
        
        if(maxProd==INT_MIN)return 0;
        return maxProd;
    }
};

int main()
{
    
    return 0;
}