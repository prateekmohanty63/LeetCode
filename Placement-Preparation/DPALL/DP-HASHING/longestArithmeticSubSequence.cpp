#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=nums.size();
        int maxRes=INT_MIN;

        // starting from last
        for(int i=n-1;i>0;i--)
        {

            for(int j=i-1;j>0;j--)
            {
                int currDiff=nums[i]-nums[j];
                int prevNum=nums[j];
                int count=1;

                for(int k=j-1;k>=0;k--){
                    if(prevNum-nums[k]==currDiff){
                        prevNum=nums[k];
                        count++;
                    }
                }
                maxRes=max(maxRes,count+1);
            }
        }
        return maxRes;
    }
};

int main()
{
    
    return 0;
}