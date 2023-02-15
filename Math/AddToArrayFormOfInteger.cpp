#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

// Giving precision error
// going out of long long , because array is of size 10^4

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        long long res=0;
        vector<int>vec;

        int n=num.size();
        int l=1;

        for(int i=0;i<n;i++)
        {
            res+=num[i]*pow(10,n-l);
            l++;
        }

        res+=k;

        string sum=to_string(res);

        for(int i=0;i<sum.length();i++)
        {
            char a=sum[i];
            int r=int(a)-48;
            vec.push_back(r);
        }

        cout<<res;

        return vec;
    }
};

int main()
{
    
    return 0;
}