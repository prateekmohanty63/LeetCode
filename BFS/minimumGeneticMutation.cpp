#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Genetic Mutation.
// Memory Usage: 6.5 MB, less than 81.49% of C++ online submissions for Minimum Genetic Mutation.


class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>st{bank.begin(),bank.end()};
        
        // end string is not a valid string
        if(!st.count(end))return -1;
        
        // start BFS by pushing into queue
        
        queue<string>Q;
        
        Q.push(start);
        
        int steps=0,s;
        
        string cur,t;
        
        while(!Q.empty())
        {
           s=Q.size();
            
            while(s--)
            {
                cur=Q.front();
                Q.pop();
                
                // if we reach the end mutation
                
                if(cur==end)return steps;
                
                //We erase the cur mutation in order to avoid redundant checking
			st.erase(cur);
                
                // at each index we check the possibility of mutation by replacing it with A,C,G,T
                
                for(int i=0;i<8;i++)
                {
                    t=cur;
                    t[i]='A';
                    if(st.count(t))Q.push(t);
                    t[i]='C';
                    if(st.count(t))Q.push(t);
                    
                    t[i]='G';
                    if(st.count(t))Q.push(t);
                    
                    t[i]='T';
                    if(st.count(t))Q.push(t);
                }
                
            }
            steps++;
        }
        return -1;
    }
};


// this is greedy method
// greedy method wont work here , as there can be many possible combinations to reach the target mutations
// from the all possible paths we need to find the shotest path to reach the target mutation

class Solution {
public:

    
    int minMutation(string start, string end, vector<string>& bank) {
      
        
         if(start==end)return 0;
        
        int count=0;
        
        vector<int>indDiff;
        
        int n=start.length();
        vector<string>::iterator itr;
        
        for(int i=0;i<n;i++)
        {
            if(start[i]!=end[i])indDiff.push_back(i);
        }
        
       
     
       int k=0; 
       while(start!=end)
       {
           int index=indDiff[k];
           string a=start;
           a[index]=end[index];
           
           itr=find(bank.begin(),bank.end(),a);
           
           if(itr!=bank.end())
           {
               start[index]=end[index];
               count++;
               k++;
           }
           else{
               int flag=0;
               for(int i=k+1;i<indDiff.size();i++)
               {
                   index=indDiff[i];
                   
                   a=start;
                   a[index]=end[index];
                   
                   itr=find(bank.begin(),bank.end(),a);
                   
                   if(itr!=bank.end())
                   {
                       start=a;
                       count++;
                       flag=1;
                       break;
                       
                   }
               }
               if(flag==0)break;
           }
           
           if(k>indDiff.size())break;
           
       }
        if(start!=end)return -1;
        
        return count;
        
    }
};

int main()
{
    
    return 0;
}