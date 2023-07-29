#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
   vector<vector<int>>res;
   map<vector<int>,bool>mp;
   
   void solve(int k,int n,int mask,vector<int>&vec)
   {
       // base case
       if(n==0 && k==0)
       {
          vector<int>v=vec;
          sort(v.begin(),v.end());
           if(mp.find(v)==mp.end())
           {
               res.push_back(v);
               mp[v]=true;
           }
            return ;
       }

       if(n<=0 || k<=0)return ;

       for(int i=1;i<=9;i++)
       {
           int isSet=(mask&(1<<i));

           if(isSet==0)
           {
               int newMask=(mask|(1<<i));
               vec.push_back(i);
               solve(k-1,n-i,newMask,vec);
               vec.pop_back();
           }
       }
   }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        if(n>=46)return {};
        vector<int>vec;
        solve(k,n,0,vec);

        return res;
    }
};

class Solution {
public:
   vector<vector<int>>res;
   map<vector<int>,bool>mp;
   
   void solve(int k,int n,string mask)
   {
       // base case
       if(n==0 && k==0)
       {
            vector<int>vec;

            for(int i=1;i<mask.length();i++)
            {
               if(mask[i]=='1')
               {
                   vec.push_back(i);
               }
            }
            if(mp.find(vec)==mp.end()){
                res.push_back(vec);
                mp[vec]=true;
            }
            return ;
       }

       if(n<=0 || k<=0)return ;

       for(int i=1;i<=9;i++)
       {
          
           if(mask[i]=='0')
           {
              string newStr=mask;
              newStr[i]='1';
               solve(k-1,n-i,newStr);
           }
       }
   }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        if(n>=46)return {};
        string mask="0000000000";
        solve(k,n,mask);

        return res;
    }
};

int main()
{
    
    return 0;
}