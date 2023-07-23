#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
  
    vector<vector<int>>res;
    
    
    void solve(vector<int>&candidates,int target,int ind,vector<int>&vec,int pre)
    {
       
        if(target==0)
        {
            res.push_back(vec);
            return ;
        }

        if(ind==candidates.size() || target<0)return ;

        solve(candidates,target,ind+1,vec,target);
        

        // way to removing duplicates
         if(ind > 0 && candidates[ind - 1] == candidates[ind] && pre == target) return; 
     
     vec.push_back(candidates[ind]);
     solve(candidates,target-candidates[ind],ind+1,vec,target);
     vec.pop_back();

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

      vector<int>vec;
       sort(candidates.begin(),candidates.end());
      solve(candidates,target,0,vec,0);
         

       
        return res;
    }
};

int main()
{
    
    return 0;
}