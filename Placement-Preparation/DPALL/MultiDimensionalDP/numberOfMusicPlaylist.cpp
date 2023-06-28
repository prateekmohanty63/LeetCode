#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// T(N)=O(n*goal*k)


class Solution {
public:
int mod=1000000007;
int nVal;
int kVal;
    long long solve(int n,int goal,int k,vector<vector<vector<long long>>>&dp)
    {
        if(goal==0)
        {
            // if all number have not been taken atleast once
            if(n<=0)return 1;

            return 0;
        }

        if(dp[n][goal][k]!=-1)return dp[n][goal][k];

        long long ans=0;

        if(k>0)
        {
            // I have to take unique songs
            ans+=n*solve(n-1,goal-1,k-1,dp)%mod;
        }
        else{
            // take unique song or previously played songs
           if(n<=0)
           {
               // taking repeated value 
              ans+=(nVal-kVal)*solve(n,goal-1,k,dp)%mod;
           }
           else{
               // taking repeated value
             ans+=(nVal-kVal-n)*solve(n,goal-1,k,dp)%mod;
           }
           if(n>0){
               // taking unique value
             ans+=n*solve(n-1,goal-1,k,dp)%mod;
           }
        }
        return dp[n][goal][k]=ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        
        nVal=n;
        kVal=k;
       vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(goal+1, vector<long long>(k+2, -1)));
        int res=solve(n,goal,k+1,dp);
       // for(int i=0;i<k;i++)res*=(i+1);

        return res;

    }
};

// wrong logic
class Solution {
public:
    int mod=1000000007;

    int solve(int n,int goal,int k,int index,unordered_map<int,int>mp)
    {
        // base case
        // 1 playlist is built
        if(index==goal)
        {
            
           for(int i=1;i<=n;i++)
           {
               if(mp.find(i)==mp.end())return 0;

           }
            for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;

            cout<<endl;
            return 1;
        }

        int ans=0;

        // we have the option of choosing from n-different songs
        for(int i=1;i<=n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                // means the song has not been played before
                // then we can take the song 
                mp[i]=index;
                ans+=(solve(n,goal,k,index+1,mp))%mod;
               
            }
            else{
                // the song has been played before
                int lastPlayed=mp[i];
                if((index-lastPlayed-1)>=k)
                {
                    mp[i]=index;
                    ans+=(solve(n,goal,k,index+1,mp))%mod;
                    
                }
            }
        }
    return ans%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        
        unordered_map<int,bool>orgMap;
        unordered_map<int,int>mp;

        for(int i=1;i<=n;i++)orgMap[i]=true;

        int ans=solve(n,goal,k,0,mp)%mod;

        return ans%mod;
    }
};

    

int main()
{
    
    return 0;
}