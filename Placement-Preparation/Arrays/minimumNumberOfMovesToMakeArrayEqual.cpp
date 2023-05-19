#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n=nums.size();

        if(n<=1)return 0;

        // sum+(n-1)*m = x*n;

        
        // x=minNum+m

        // sum + (n-1)*m = (minNum+m)*n;

        // sum + n*m -m = minNum*n + m*n;

        // sum - m= minNum*n;

        // m=sum - (minNum*n)

        int sum=0;
        int minNum=10000000000;
        for(int i=0;i<n;i++)
        {
            minNum=min(minNum,nums[i]);
            sum+=nums[i];
        }
      
      return (sum-(minNum*n));

    }
};

int main()
{
    
    return 0;
}