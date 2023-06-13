#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int res=0;
        
        // storing all the row wise vectors
        map<vector<int>,int>mp;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            mp[grid[i]]++;
        }

        // traversing the column wise vectors

        for(int i=0;i<m;i++){
            vector<int>vec;
            for(int j=0;j<n;j++){
                vec.push_back(grid[j][i]);
            }
            if(mp.find(vec)!=mp.end())res+=mp[vec];
        }


        return res;
    }
};

int main()
{
    
    return 0;
}