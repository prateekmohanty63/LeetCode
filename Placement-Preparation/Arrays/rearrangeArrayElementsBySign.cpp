#include<iostream>
#include<vector>
using namespace std;


// T(N)=O(N)
// S(N)=O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>neg,pos;

        for(auto it:nums)
        {
            if(it<0)neg.push_back(it);

            else pos.push_back(it);
        }

        int p=0;
        int n=0;
        int flag=0;
        vector<int>res;

        while(p<pos.size())
        {
            if(flag==0)
            {
                res.push_back(pos[p]);
                p++;
            }
            else{
                res.push_back(neg[n]);
                n++;
            }
            flag=!flag;
        }
         res.push_back(neg[n]);
        return res;
    }
};

int main()
{
    
    return 0;
}