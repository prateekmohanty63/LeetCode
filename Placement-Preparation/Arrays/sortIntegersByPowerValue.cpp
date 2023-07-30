#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int getPowerValue(int num)
    {
        int res=0;

        while(num!=1)
        {
            if(num%2==0)num/=2;

            else num=(3*num+1);
            res++;
        }
        return res;
    }
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>>vec;

        for(int i=lo;i<=hi;i++)
        {
            pair<int,int>pr;
            pr.first=getPowerValue(i);
            pr.second=i;
            vec.push_back(pr);
        }
        for(auto it:vec)cout<<it.first<<" "<<it.second<<endl;
        sort(vec.begin(),vec.end());

        return vec[k-1].second;
    }
};

int main()
{
    
    return 0;
}