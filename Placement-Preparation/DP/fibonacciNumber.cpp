#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        
        vector<int>dp;
        
        dp.push_back(0);
        dp.push_back(1);
        
        for(int i=2;i<=n;i++)
        {
            int a=dp[i-1]+dp[i-2];
            dp.push_back(a);
        }
        
        return dp[n];
    }
};

int main()
{
    
    return 0;
}