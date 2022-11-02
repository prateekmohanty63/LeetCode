#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


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