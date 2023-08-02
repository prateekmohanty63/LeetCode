#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool>res;
        int m=l.size();

        for(int i=0;i<m;i++)
        {
            int leftIndex=l[i];
            int rightIndex=r[i];
            vector<int>vec;

            for(int j=leftIndex;j<=rightIndex;j++)
            vec.push_back(nums[j]);

            sort(vec.begin(),vec.end());

            if(vec.size()==1)
            {
                res.push_back(true);
            }
            else{
                int diff=vec[1]-vec[0];
                int flag=0;
                for(int j=1;j<vec.size();j++)
                {
                    if(vec[j]-vec[j-1]!=diff)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)res.push_back(true);
                else res.push_back(false);
            }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}