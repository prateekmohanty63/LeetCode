#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int n=pref.size();
        vector<int>res(n);
        res[0]=pref[0];

        for(int i=1;i<n;i++)
        {
            int ele=pref[i-1]^pref[i];
            res[i]=ele;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}