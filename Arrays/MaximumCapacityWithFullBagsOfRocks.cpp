#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n=rocks.size();
       
        vector<int>vec;

        for(int i=0;i<n;i++)
        {
            int r=capacity[i]-rocks[i];
            vec.push_back(r);
        }
        
        
        sort(vec.begin(),vec.end());

       // for(auto it:vec)cout<<it<<" "; 
        int k=0;
        while(k<vec.size() && additionalRocks>0)
        {
            if(vec[k]>additionalRocks)break;

            additionalRocks-=vec[k++];
        }
        return k;
    }
};

int main()
{
    
    return 0;
}