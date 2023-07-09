#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// T(N)=O(nlogn)
// S(N)=O(N)
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        long long res;
        int n=weights.size();

        vector<long long>prSum;

        for(int i=1;i<n;i++)
        {
            long long sum=(long long)weights[i-1]+weights[i];
            prSum.push_back(sum);
        }
        sort(prSum.begin(),prSum.end());

        long long minSum=0;
        for(int i=0;i<k-1;i++)minSum+=(long long)prSum[i];

        long long maxSum=0;

        for(int i=0;i<k-1;i++)maxSum+=(long long)prSum[prSum.size()-i-1];
        
        res=(long long)(maxSum-minSum);
        return res;
    }
};

int main()
{
    
    return 0;
}