#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;




class Solution {
public:
     
     int dp[1004][1002];
     int maxScore(vector<pair<int,int>>&v,int pre,int i)
     {
          // base case

          if(i>=v.size())return 0;
        
         if(dp[pre+1][i]!=-1)return dp[pre+1][i];

      if(pre == -1){
        return dp[pre+1][i] =max(maxScore(v , -1 , i+1) , v[i].second + maxScore(v , i , i+1)) ;
    }
    if(v[pre].first < v[i].first &&  v[pre].second > v[i].second){
        return dp[pre+1][i] = maxScore(v , pre , i+1) ;
    }
    return dp[pre+1][i] = max(v[i].second + maxScore(v , i , i+1) , maxScore(v , pre , i+1)) ;
     }


    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        memset(dp , -1 , sizeof(dp)) ;
    vector<pair<int,int>>v ;
    
    for(int i=0 ; i<ages.size() ; i++){
        v.push_back(make_pair(ages[i] ,scores[i])) ;
    }
    
    sort(v.begin() , v.end()) ;
    
    int ans = maxScore(v , -1 , 0 ) ;

    return ans;
    }
};



// giving TLE , cause memoization not applied correctly (logic is correct)
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