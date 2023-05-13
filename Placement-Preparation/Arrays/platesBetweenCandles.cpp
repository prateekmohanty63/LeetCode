#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time complexity: O(n+m)

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        int n=s.length();
        vector<int>vec;
        vector<int>preSum(n,0);
        vector<int>candleStartPos(n,-1);
        vector<int>candleEndPos(n,-1);
       
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')count++;
            preSum[i]=count;
        }
        
        int currPos=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='|'){
               currPos=i;
            }
             candleStartPos[i]=currPos;
        }

        currPos=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='|')
            {
                currPos=i;
            }
            candleEndPos[i]=currPos;
        }
     

        for(int i=0;i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];

            int startBoundary=candleStartPos[start];
            int endBoundary=candleEndPos[end];
            
            if(startBoundary>=endBoundary)vec.push_back(0);
          
           else if(startBoundary==-1 || endBoundary==-1)vec.push_back(0);

          else 
            vec.push_back(preSum[endBoundary]-preSum[startBoundary]);
        }
        return vec;
    }
};


class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        vector<int>res;

      
        int n=s.length();
        int count=0;

        int start=queries[0][0];
        int end=queries[0][1];

        unordered_map<int,bool>plates;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='|')
            {
                plates[i]=true;
            }
        }


        for(int i=0;i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            while(start<end && s[start]!='|')start++;
            while(start<end && s[end]!='|')end--;

            if(start==end)res.push_back(0);
            else if(end-start==1)res.push_back(0);
            
            else{
                count=(end-start)-1;
           for(int i=start+1;i<end;i++)
           {
               if(plates.find(i)!=plates.end())count--;
           }
           res.push_back(count);
        }
           

        }

        return res;
    }
};

int main()
{
    
    return 0;
}