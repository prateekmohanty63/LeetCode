#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>>res;
        vector<int>won;
        vector<int>lost;
      
         int n=matches.size();
         set<int>set1;
      

          for(int i=0;i<n;i++)
          {
              set1.insert(matches[i][0]);
              set1.insert(matches[i][1]);
          }


         unordered_map<int,int>matchesLost;

         for(int i=0;i<n;i++)
         {
            // matches[i][1] lost the match
            matchesLost[matches[i][1]]++;

         }

         for(auto it:set1)
         {
             int a=it;

             if(matchesLost.find(a)==matchesLost.end())
             {
                 won.push_back(a);
             }

             if(matchesLost.find(a)!=matchesLost.end())
             {
                 if(matchesLost[a]==1)
                 {
                     lost.push_back(a);
                 }
             }
         }
         
         sort(won.begin(),won.end());
         sort(lost.begin(),lost.end());

         res.push_back(won);
         res.push_back(lost);

       
        return res;
    }
};

int main()
{
    
    return 0;
}