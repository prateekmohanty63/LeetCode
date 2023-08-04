#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& A, int k) {

    int n=A.size();
    if(k==0)return n>=1 ? A[0]:-1;  // if no moves allowed, return the topmost element if any
    if(k==1)return n==1?-1:A[1]; // if only one move is allowed, we can only remove the topmost element
    if (n == 1) return k % 2 == 0 ? A[0] : -1; // if `N == 1`, we can return the topmost element if `k` is a even number (keep removing the topmost element and adding it back).

      int mx=*max_element(begin(A),begin(A)+min(k-1,n));

        if (k < n) mx = max(mx, A[k]); // If `k < N`, we can take all the topmost `k` elements and return the one left at the top

        return mx;
    }
};

int main()
{
    
    return 0;
}