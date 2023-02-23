#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int res=w;

        priority_queue<pair<int,int>>pq;

        int n=profits.size();

        vector<pair<int,int>>pr;

        for(int i=0;i<n;i++)
        {
            pr.push_back(make_pair(capital[i],profits[i]));
        }

        // sorting the vector of pairs

        sort(pr.begin(),pr.end());

        for(int i=0;i<pr.size();i++)
        {
            cout<<pr[i].first<<" "<<pr[i].second<<endl;
        }
       int i=0;
        for(i=0;i<n;i++)
        {
            if(pr[i].first<=w)
            {
                pair<int,int>a=make_pair(pr[i].second,pr[i].first);
                pq.push(a);
            }
            else break;
        }

        int ptr=i;

        while(!pq.empty() && k!=0)
        {
            res+=pq.top().first;
            pq.pop();

           while(ptr<pr.size() && pr[ptr].first<=res)
           {
               pair<int,int>a=make_pair(pr[ptr].second,pr[ptr].first);
               pq.push(a);
               ptr++;
           }
            k--;
        }

      return res;
    }
};

int main()
{
    
    return 0;
}