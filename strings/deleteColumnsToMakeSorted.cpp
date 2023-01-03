#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n=strs.size();
        int m=strs[0].length();
        int res=0;
        

        for(int i=0;i<m;i++)
        {
            string a;

            for(int j=0;j<n;j++)
            {
                a+=strs[j][i];
            }

          
            string b=a;
            sort(b.begin(),b.end());
              cout<<a<<" "<<b<<endl;

              if(a!=b)res++;
            
        }

       
        return res;
    }
};

int main()
{
    
    return 0;
}