#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

// T(N)=O(n*2^16*16) == O(n*2^16)
// S(N)=O(n*2^16)

class Solution {
public:
vector<int>res;

void solve(int index,vector<vector<int>>&people_skill,int &reqMask,int mask,vector<int>&ans,vector<vector<int>>&dp)
{
    // base case
    if(index==people_skill.size())
    {
       // check if all the skills are included
       if(mask==reqMask)
       {
           if(res.size()==0 || (ans.size()<res.size()))res=ans;
       }
       return ;
    }

    if(dp[index][mask]!=-1)
    {
        if(dp[index][mask]<=ans.size())return ;
    }
    
    // dont pick the person
    solve(index+1,people_skill,reqMask,mask,ans,dp);

    // pick the person
    ans.push_back(index);
    int newMask=mask;
    for(auto it:people_skill[index])newMask|=(1<<it);

    solve(index+1,people_skill,reqMask,newMask,ans,dp);

    // undo the change in Pick
    ans.pop_back();
     
     // if answer found update DP
    if(ans.size()>0)dp[index][mask]=ans.size();

}
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
         unordered_map<string,int>skillMap;
        vector<vector<int>>pep;
   
        int n=req_skills.size();
        int m=people.size();

        for(int i=0;i<n;i++)
        {
            skillMap[req_skills[i]]=i;
        }

        for(int i=0;i<people.size();i++)
        {
            vector<int>vec;
            for(int j=0;j<people[i].size();j++)
            {
                int num=skillMap[people[i][j]];
               // cout<<num<<" ";
                vec.push_back(num);
            }
            pep.push_back(vec);
        }

        int mask=0;
        
        // required bit mask
        for(auto it:req_skills)
        {
            int num=skillMap[it];
            mask|=(1<<num);
        }
       vector<int>ans;
       vector<vector<int>>dp(m+1,vector<int>((1<<16)+1,-1));
        solve(0,pep,mask,0,ans,dp);

        return res;
    }
};


class Solution {
public:
     int ans;
     int ansBit=61;
     int countSetBits(int n)
{
   int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
      long long solve(vector<vector<int>>&people,int &reqBitMask,int currMask,int index,int peopleBit,vector<vector<int>>&dp)
      {
          // base case
          int n=people.size();
          if(currMask==reqBitMask)
          {  
             
             int a=countSetBits(peopleBit);
            
             if(a<ansBit)
             {
                 ans=peopleBit;
                 ansBit=a;
             }
              return 0;
          }
          if(index>=n)return 61;

          if(dp[index][currMask]!=-1)return dp[index][currMask];

          // we have the option of choosing the person 
          // or not choosing the person
         
          int newMask=currMask;
          for(auto it:people[index])
          {
              newMask|=(1<<it);
          }
         // cout<<newMask<<" ";
        
          int newPeopleBit=(peopleBit|(1<<index));
          int taken=1+solve(people,reqBitMask,newMask,index+1,newPeopleBit,dp);
          int notTaken=0+solve(people,reqBitMask,currMask,index+1,peopleBit,dp);
       

          return dp[index][currMask]=min(taken,notTaken);

          
      }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        unordered_map<string,int>skillMap;
        vector<vector<int>>pep;
   
        int n=req_skills.size();
        int m=people.size();

        for(int i=0;i<n;i++)
        {
            skillMap[req_skills[i]]=i;
        }

        for(int i=0;i<people.size();i++)
        {
            vector<int>vec;
            for(int j=0;j<people[i].size();j++)
            {
                int num=skillMap[people[i][j]];
               // cout<<num<<" ";
                vec.push_back(num);
            }
            pep.push_back(vec);
        }

        int mask=0;
        
        // required bit mask
        for(auto it:req_skills)
        {
            int num=skillMap[it];
            mask|=(1<<num);
        }
       //cout<<mask<<" ";
       int num=pow(2,16)+1;
       vector<vector<int>>dp(m+1,vector<int>(num,-1));
        int peopleReq=solve(pep,mask,0,0,0,dp);
        // cout<<peopleReq;
       cout<<ans;
       vector<int>res;
       int k=0;
        while (ans) {
       if((ans & 1)==1)res.push_back(k);
        ans >>= 1;
        k++;
    }
     
        return res;
    }
};

int main()
{
    
    return 0;
}