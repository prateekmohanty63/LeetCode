#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        map<int,vector<int>>mp;
        int n=score.size();

        for(int i=0;i<n;i++)
        {
            mp[score[i][k]]=score[i];
        }

        vector<vector<int>>res;

        for(auto it:mp)
        res.push_back(it.second);

        reverse(res.begin(),res.end());

        return res;
    }
};

int main()
{
    
    return 0;
}