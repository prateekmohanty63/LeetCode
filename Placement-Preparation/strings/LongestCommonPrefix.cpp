#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();
        string res;

        int minLen=INT_MAX;
        string str;

        for(auto it:strs)
        {
            if(it.length()<minLen){
                minLen=it.length();
                str=it;
            }
        }

        int k=0;

        while(k<minLen){
            char ele=str[k];

            int flag=0;
            for(int i=0;i<n;i++){
                if(strs[i][k]!=ele)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;

            res+=ele;
            k++;
        }
       
       return res;

    }
};

int main()
{
    
    return 0;
}