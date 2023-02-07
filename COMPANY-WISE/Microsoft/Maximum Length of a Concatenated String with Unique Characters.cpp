#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


class Solution {
public:

int maxPossibleLength(string a,vector<string>&vec,int i)
{
    // base case
   if(i>=vec.size())return 0;

   string curr=vec[i];
   int m=curr.length();

   unordered_map<char,bool>mp;

   for(auto it:a)
   mp[it]=true;
   
   int flag=0;

   for(auto it:curr)
   {
       if(mp.find(it)!=mp.end())
       {
            flag=1;
            break;
       }
   }

   if(flag==0)
   {
       return max(m+maxPossibleLength(a+curr,vec,i+1),maxPossibleLength(a,vec,i+1));
   }
   else return maxPossibleLength(a,vec,i+1);
   
}



    int maxLength(vector<string>& arr) {
        
        int n=arr.size();

        int res=INT_MIN;


        for(int i=0;i<n;i++)
        {
            string currString=arr[i];
            unordered_map<char,bool>mp;
            int flag1=0;
            vector<string>vec;
            int count=currString.length();

            for(int j=0;j<currString.length();j++)
            {
                if(mp.find(currString[j])!=mp.end())
                {
                    flag1=1;
                    break;
                }
                else 
                mp[currString[j]]=true;
            }

            // the string itself is not unique , hence we continue
            if(flag1==1)continue;

            for(int j=i+1;j<n;j++)
            {
                int flag=0;
                unordered_map<char,bool>mp1;
               
                string nxtString=arr[j];

                for(int k=0;k<nxtString.length();k++)
                {
                    if(mp.find(nxtString[k])!=mp.end())
                    {
                        flag=1;
                        break;
                    }
                    if(mp1.find(nxtString[k])!=mp.end())
                    {
                        flag=1;
                        break;
                    }
                    else{
                        mp1[nxtString[k]]=true;
                    }
                    
                }

                

                if(flag==1)continue;

                else{
                   
                    vec.push_back(nxtString);
                }
            }
          
            int lenPos=maxPossibleLength(currString,vec,0);
            count+=lenPos;
             res=max(res,count);
        }

        if(res==INT_MIN)return 0;
        return res;
    }
};

int main()
{
    
    return 0;
}