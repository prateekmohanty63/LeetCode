#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    bool makeSquare(vector<int>&matchsticks,int i,int &n,vector<int>&sides,int &target)
    {
        if(i==n)return true;
        
        for(int j=0;j<4;j++)
        {
            if(sides[j]+matchsticks[i]<=target)
            {
                sides[j]+=matchsticks[i];
                if(makeSquare(matchsticks,i+1,n,sides,target))return true;
                
                // backtrack
                sides[j]-=matchsticks[i];
            }
            
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
         
        int n=matchsticks.size();
        
        
        // perimeter should be even
         int sum=0;
        for(int i=0;i<n;i++)
        sum+=matchsticks[i];
        
        if(sum%4!=0)return false;
        
        
        
        // one side length will be obvisously the longest matchstick
        
        int side1=sum/4;
        
        vector<int>side(4,0);
        
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        if(matchsticks[0]>side1)return false;
        
        
        
        
        int i=0;
       
        return makeSquare(matchsticks,i,n,side,side1);
        
        
    }
};