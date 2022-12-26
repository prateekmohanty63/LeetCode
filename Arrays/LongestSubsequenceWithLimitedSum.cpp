#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();
        vector<int>res;

        int sum=0;

        for(int i=0;i<n;i++)
        sum+=nums[i];

        for(int i=0;i<m;i++)
        {
            int target=queries[i];
            int tmpSum=sum;
            
            if(target>=sum)res.push_back(nums.size());

            else{
                  int k=nums.size()-1;

                  while(k>=0 && tmpSum>target)
                  {
                      tmpSum-=nums[k];
                      k--;
                  }
                  res.push_back(k+1);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}