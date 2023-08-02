#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// T(N)=O(NlogN)
// S(N)=O(1)

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n=piles.size();

        int start=0;
        int my=n-2;
        int end=n-1;
        int res=0;

        sort(piles.begin(),piles.end());

        while(start<my)
        {
            res+=piles[my];
            start++;
            my-=2;
            end-=2;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}