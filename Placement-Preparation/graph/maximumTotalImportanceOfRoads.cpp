#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res=0;

        unordered_map<int,long long>adj;

        int m=roads.size();

        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]]++;
            adj[roads[i][1]]++;
        }
        vector<long long>vec;

        for(auto it:adj)
        {
            vec.push_back(it.second);
        }
        sort(vec.begin(),vec.end());

        for(int i=vec.size()-1;i>=0;i--)
        {
            res+=(long long)(n)*(long long)(vec[i]);
            n--;
        }

        return res;

    }
};

int main()
{
    
    return 0;
}