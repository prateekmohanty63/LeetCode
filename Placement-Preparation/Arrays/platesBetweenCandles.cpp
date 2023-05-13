#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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