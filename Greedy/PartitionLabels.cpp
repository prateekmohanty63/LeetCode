#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


// greedy solution
class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>mp;

        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]=i;
        }

        vector<int>res;
       
       int prev=-1;
       int maxPartition=0;

       for(int i=0;i<s.length();i++)
       {
           maxPartition=max(maxPartition,mp[s[i]]);

           if(maxPartition==i)
           {
               // hence all the element in the partition are covered
               res.push_back(maxPartition-prev);
               prev=maxPartition;
           }
       }

        return res;
    }
};

// recursive solution
class Solution {
public:
  
  vector<int>res;
  void maximPartitions(string s,unordered_map<char,int>&mp,int start,int end)
  {
        // base case
        if(end>=s.length())return ;
        
        int charInd=mp[s[start]];

        int flag=0;
        int maximInd=INT_MIN;

        for(int j=start+1;j<=end;j++)
        {
            int ind=mp[s[j]];

            if(ind>end)
            {
                flag=1;
                maximInd=max(maximInd,ind);
            }
        }
       // cout<<flag<<" ";
        if(flag==0)
        {
            cout<<start<<" "<<end<<endl;
            res.push_back(end-start+1);

            if(end+1<s.length())
           maximPartitions(s,mp,end+1,mp[s[end+1]]);

           else return ;
        }
        else{
            maximPartitions(s,mp,start,maximInd);
        }

       
  }

    vector<int> partitionLabels(string s) {
        
        //vector<int>res;

        int n=s.length();

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)
        {
            // mapping the character values to its maximim index value
            mp[s[i]]=i;
        }

        int maxInd=mp[s[0]];

       maximPartitions(s,mp,0,maxInd);

       return res;

    }
};

int main()
{
    
    return 0;
}