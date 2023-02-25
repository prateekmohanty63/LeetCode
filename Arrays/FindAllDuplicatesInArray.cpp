#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();

        vector<int>res;

        for(int i=0;i<n;i++)
        {
            int num=abs(nums[i]);
           // cout<<num<<" ";

            if(nums[num-1]<0)
            {
                res.push_back(num);
            }
            else{
                nums[num-1]=-1*nums[num-1];
            }


        }

        return res;
    }
};

int main()
{
    
    return 0;
}