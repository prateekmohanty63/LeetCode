#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
   
   bool reach(vector<int>&arr,int index,unordered_map<int,bool>&mp)
   {
       // base case

       if(index<0 || index>=arr.size())return false;

       if(arr[index]==0)return true;

       if(mp.find(index)!=mp.end())return false;

       int jump=arr[index];
       mp[index]=true;

      return reach(arr,index+jump,mp) || reach(arr,index-jump,mp);
       
   }

    bool canReach(vector<int>& arr, int start) {
        
       unordered_map<int,bool>mp;
        return reach(arr,start,mp);
    }
};

int main()
{
    
    return 0;
}