#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;


// T(N)=O(Nlogk)

class Solution {
public:

 typedef pair<int, string> pi;

 class Compare {
public:
    bool operator()(pi below, pi above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;

       priority_queue<pi, vector<pi>, Compare >q;

        for(auto it:words)
        {
            mp[it]++;
        }
       
       for(auto it:mp)
       {
           q.push({it.second,it.first});
           if(q.size()>k)q.pop();
          
       }
       vector<string>res;
       int temp=0;
       while(!q.empty())
       {
           string a=q.top().second;
           res.push_back(a);
           q.pop();
       }
       reverse(res.begin(),res.end());
        return res;
    }
};

// T(N)=O(NlogN)

class Solution {
public:

 typedef pair<int, string> pi;

 class Compare {
public:
    bool operator()(pi below, pi above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;

       priority_queue<pi, vector<pi>, Compare >q;

        for(auto it:words)
        {
            mp[it]++;
        }
       
       for(auto it:mp)
       {
           q.push({it.second,it.first});
          
       }
       vector<string>res;
       int temp=0;
       while(!q.empty())
       {
           string a=q.top().second;
           res.push_back(a);
           q.pop();

           temp++;
           if(temp==k)break;
       }
        return res;
    }
};

int main()
{
    
    return 0;
}