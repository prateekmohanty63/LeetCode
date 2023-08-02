#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

// T(N)=O(n)
// S(N)=O(n)

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        vector<int>res(k,0);


        map<int,unordered_map<int,int>>mp;

        int n=logs.size();

        for(int i=0;i<n;i++)
        {
            int userId=logs[i][0];
            int minute=logs[i][1];
            mp[userId][minute]=1;
            
        }

        for(auto it:mp)
        {
            // cout<<it.first<<" ";

            // for(auto itr:it.second)
            // cout<<itr.first<<" ";

            int sz=it.second.size();

            res[sz-1]++;
            cout<<endl;
        }

        return res;
    }
};

int main()
{
    
    return 0;
}