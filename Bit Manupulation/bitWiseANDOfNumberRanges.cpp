#include<iostream>
using namespace std;

// Bitwise AND of number ranges
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left==0 || right==0)return 0;

        if(left==right)return left;

        int x=log2(left);
        int y=log2(right);

        if(y-x>=1)return 0;

        long long ans = left;
        for(long long i=left+1;i<=right;i++) ans&=i; 
        return ans;
    }
};

// TLE


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int res=0;

        for(int i=left;i<=right;i++)
        {
            res=res&i;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}