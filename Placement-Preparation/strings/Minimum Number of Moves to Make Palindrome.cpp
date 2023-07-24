#include<iostream>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;


// greedy approach
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int n=s.length();
        int i=0,j=n-1;
        int ans=0;

        while(i<j)
        {
            if(s[i]==s[j])
            {
                // both characters are same 
                i++;
                j--;
            }
            else{
                int found=-1;

                // find index nearest to j which matches with i index
                for(int k=j-1;k>i;k--)
                {
                    if(s[k]==s[i])
                    {
                        found=k;
                        break;
                    }
                }

                // found the character equal to s[i]
                if(found>0)
                {
                    for(int k=found;k<j;k++)
                    {
                        swap(s[k],s[k+1]);
                        ans++;
                    }
                    i++;
                    j--;
                }
                else{
                    swap(s[i],s[i+1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// DFS 
class Solution {
public:
   int solve(string a,int start,int end)
   {
       if(start>=end)return 0;
      // if(end-start==1 && a[start]==a[end])return 0;
       int ans=INT_MAX;

       if(a[start]==a[end])
       return solve(a,start+1,end-1);
       else{
           for(int i=start+1;i<=end;i++)
           {
               if(a[end]==a[i])
               {
                  string temp=a;
                  for(int j=i;j>0;j--)
                  {
                      swap(temp[j],temp[j-1]);
                  } 
                  ans=min(ans,(i-start)+solve(temp,start+1,end-1));
               }
           }
       }
       return ans;
   }
    int minMovesToMakePalindrome(string s) {
        
        int start=0;
        int end=s.length()-1;

      int res=solve(s,start,end);

      return res;
       
    }
};



/// TLE 
// BFS

class Solution {
public:
   bool isPalindrome(string s)
   {
       int start=0;
       int end=s.length()-1;

       while(start<=end)
       {
           if(s[start]!=s[end])return false;
           start++;
           end--;
       }
       return true;
   }
    int solve(string s)
    {
        queue<pair<string,int>>q;
        q.push({s,0});
        unordered_map<string,bool>vis;
        vis[s]=true;

        while(!q.empty())
        {
            string a=q.front().first;
            int moves=q.front().second;
            q.pop(); 
           // cout<<a<<" ";

            if(isPalindrome(a))return moves;

            int n=a.length();
            string temp=a;
            for(int i=0;i<n-1;i++)
            {  
               swap(temp[i],temp[i+1]);

               if(vis.find(temp)==vis.end())
               {
                   vis[temp]=true;
                   q.push({temp,moves+1});
               }
               swap(temp[i],temp[i+1]);
            }
        }
        return -1;
    }
    int minMovesToMakePalindrome(string s) {
        
        int res=solve(s);

        return res;
    }
};

int main()
{
    
    return 0;
}