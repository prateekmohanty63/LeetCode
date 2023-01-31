#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
   
     int maxScore(vector<pair<int,int>>&board,int i,int score,unordered_map<string,int>&dp)
     {
          // base case

          if(i>=board.size())return 0;
        
         

          int currAge=board[i].first;
          int currScore=board[i].second;

           string a=to_string(i)+"*"+to_string(score);

           if(dp.find(a)!=dp.end())return dp[a];

          if(score>currScore)
          {
              return dp[a]=maxScore(board,i+1,score,dp);
          }
          else{
              int maxim=max(score,currScore);
              return dp[a]=max(currScore+maxScore(board,i+1,maxim,dp),maxScore(board,i+1,score,dp));
          }
     }


    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n=scores.size();

       
        vector<pair<int,int>>board;

        for(int i=0;i<n;i++)
        {
            board.push_back(make_pair(ages[i],scores[i]));
        }

        sort(board.begin(),board.end());

        // for(auto it:board)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        unordered_map<string,int>dp;
        int res=maxScore(board,0,-1,dp);

        return res;
         
    }
};

int main()
{
    
    return 0;
}