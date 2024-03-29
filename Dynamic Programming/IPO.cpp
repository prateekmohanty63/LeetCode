#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;



// optimized solution

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

// memoized solution
// still TLE
// Time Complexity: O(n^2)
// But N can be till 10^5 , hence TLE

class Solution {
public:

   
   
   int maxCapital(vector<int>&profit,vector<int>&capital,int w,int k,int i,unordered_map<string,int>&dp)
   {
       // base case

       if(i>=capital.size())return 0;

       if(k==0)return 0;

       string res=to_string(w)+"*"+to_string(k)+"*"+to_string(i);

       if(dp.find(res)!=dp.end())return dp[res];
       

       if(capital[i]>w)
       {
           return dp[res]=maxCapital(profit,capital,w,k,i+1,dp);
       }
       else{
           // we have the option of choosing if we want to do the project or not
           return dp[res]=max(profit[i]+maxCapital(profit,capital,w+profit[i],k-1,i+1,dp),maxCapital(profit,capital,w,k,i+1,dp));
          
       }
      
   }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        unordered_map<string,int>dp;
       int res=maxCapital(profits,capital,w,k,0,dp);

    
        return w+res;
    }
};



// solution correct
// giving TLE
// Time Complexity: O(2^n)

class Solution {
public:

   
   
   int maxCapital(vector<int>&profit,vector<int>&capital,int w,int k,int i)
   {
       // base case

       if(i>=capital.size())return 0;

       if(k==0)return 0;
       

       if(capital[i]>w)
       {
           return maxCapital(profit,capital,w,k,i+1);
       }
       else{
           // we have the option of choosing if we want to do the project or not
           return max(profit[i]+maxCapital(profit,capital,w+profit[i],k-1,i+1),maxCapital(profit,capital,w,k,i+1));
          
       }
      
   }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
       int res=maxCapital(profits,capital,w,k,0);

    
        return w+res;
    }
};

int main()
{
    
    return 0;
}