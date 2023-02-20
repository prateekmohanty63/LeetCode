#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int>res;

        int m=n/2;
        int m1=0-m;

        for(int i=1;i<=m;i++)
        {
            res.push_back(i);
        }

        for(int i=-1;i>=m1;i--)
        {
            res.push_back(i);
        }
        
        if(n%2==0)return res;

        res.push_back(0);

        return res;
    }
};

int main()
{
    
    return 0;
}