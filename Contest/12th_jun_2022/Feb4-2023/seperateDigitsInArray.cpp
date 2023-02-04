#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>vec;
        
        for(int i=0;i<n;i++)
        {
            string a=to_string(nums[i]);
            
            for(int j=0;j<a.length();j++)
            {
                int r=a[j]-'0';
                vec.push_back(r);
            }
        }
        return vec;
    }
};

int main()
{
    
    return 0;
}