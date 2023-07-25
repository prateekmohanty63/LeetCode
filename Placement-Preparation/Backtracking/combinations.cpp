#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// optimal solution

class Solution {
public:
   vector<vector<int>>res;
    void solve(int n,int k,int ind,vector<int>&vec)
    {
        // base case
        if(ind>=n+1)
        {
            if(k==0)res.push_back(vec);

            return ;
        }

        // we have the option of including the element in the list
        // or not including it

        vec.push_back(ind);
        solve(n,k-1,ind+1,vec);
        vec.pop_back();

        solve(n,k,ind+1,vec);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>vec;
        solve(n,k,1,vec);
        
        return res;
    }
};

// TLE  
// T(N)=O(k*log(n)*2^n)

class Solution {
public:
   vector<vector<int>>res;
   map<vector<int>,bool>mp;

   void solve(int n,int k,vector<int>&vec)
   {
       // base case
       if(k==0)
       {   vector<int>v=vec;
          sort(v.begin(),v.end());
           if(mp.find(v)==mp.end()){
           mp[v]=true;
           res.push_back(v);
           }
       }

       for(int i=1;i<=n;i++)
       {
           if(find(vec.begin(),vec.end(),i)==vec.end())
           {
               vec.push_back(i);
               solve(n,k-1,vec);
               vec.pop_back();
           }
       }
      
   }
    vector<vector<int>> combine(int n, int k) {
         
         vector<int>vec;
         solve(n,k,vec);

         return res;
    }
};

int main()
{
    
    return 0;
}