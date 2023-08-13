#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */
 
 
 int binSearch(vector<int>&nums,int target)
 {
     int start=0;
     int end=nums.size()-1;
     
     while(start<=end)
     {
         int mid=start+(end-start)/2;
         if(nums[mid]==target)return mid;
         
         if(target<nums[mid])start=mid+1;
         
         else end=mid-1;
     }
     return -1;
 }
 
 int findFloor(vector<int>&nums,int target)
 {
     int start=0;
     int end=nums.size()-1;
     
     int res=-1;
     
     while(start<=end)
     {
         int mid=start+(end-start)/2;
         int num=nums[mid];
         
         if(num<target)
         {
            res=mid;
            end=mid-1;
         }
         else{
             start=mid+1;
         }
     }
     return res;
 }

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
   int n=ranked.size();
   int m=player.size();
   map<int,int>mp;
   vector<int>leaderBoard;
   vector<int>res;
   
   for(int i=0;i<n;i++)
   {
       if(mp.find(ranked[i])==mp.end())
       {
           mp[ranked[i]]=true;
           leaderBoard.push_back(ranked[i]);
       }
   }
   
   // assign the initial ranking
   for(int i=0;i<m;i++)
   {
       // check if the player with the same score is already present in the leader board
       
       int currInd=binSearch(leaderBoard,player[i]);
       if(currInd==-1)
       {
          // cout<<"IN";
            int indSmaller=findFloor(leaderBoard,player[i]);
            
            if(indSmaller==-1)
            {
                res.push_back(leaderBoard.size()+1);
                leaderBoard.push_back(player[i]);
                
            }
            else{
                leaderBoard.insert(leaderBoard.begin()+indSmaller,player[i]);
                res.push_back(indSmaller+1);
            }
       }
       else{
           res.push_back(currInd+1);
       }
       
    //    for(auto it:leaderBoard)cout<<it<<" ";
    //    cout<<endl;
   }
   
   
   return res;
}