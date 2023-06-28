#include<iostream>
#include<unordered_map>

using namespace std;

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