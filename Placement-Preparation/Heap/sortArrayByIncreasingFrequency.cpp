#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {   
        if(a.first==b.first)
        return a.second < b.second;

        return a.first>b.first;
    }
};
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int>res;

        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp>q;
        
        unordered_map<int,int>freq;

        for(auto it:nums)freq[it]++;

        for(auto it:freq){
            pair<int,int>pr;
            pr.first=it.second;
            pr.second=it.first;
            q.push(pr);
        }

        while(!q.empty())
        {
            pair<int,int>fr=q.top();
            int ele=fr.second;
            int fre=fr.first;
            cout<<ele<<" "<<fre<<endl;
            for(int i=0;i<fre;i++)
            res.push_back(fr.second);
            q.pop();
        }

        return res;

    }
};

int main()
{
    
    return 0;
}