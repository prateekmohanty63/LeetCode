#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// T(N): O(N*4^N)

class Solution {
public:
   
   vector<string>res;
    
   void generateStrings(string &digits,unordered_map<char,string>&mp,int i,string currString)
   {
       // base case
      
      if(currString.length()==digits.length())
      {
          res.push_back(currString);

          return ;
      }

      string a=mp[digits[i]];

      for(int j=0;j<a.length();j++)
      {
         generateStrings(digits,mp,i+1,currString+a[j]);
      }



   }
  
              

    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string>mp;

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

       // vector<string>res;

        if(digits=="")return res;

        // if(digits.length()==1)
        // {
        //     string a=mp[digits[0]];

        //     for(int i=0;i<a.length();i++)
        //     {
        //         string r=string(1,a[i]);
        //         res.push_back(r);
        //     }
        // }

       generateStrings(digits,mp,0,"");
        return res;
    }
};


// T(N):O(N^4) FASTER THAN 100%

class Solution {
public:
   
   vector<string>res;

   void generateCombinations(string a,unordered_map<char,string>&mp)
   {
      vector<string>vec;

      for(int i=0;i<a.length();i++)
      {
          vec.push_back(mp[a[i]]);
      }          

      int n=vec.size();
       
       if(n==2)
       {
           int n=vec[0].length();
           int m=vec[1].length();
           for(int i=0;i<n;i++)
           {
               string a=vec[0];

               for(int j=0;j<m;j++)
               {
                   string b=vec[1];
                   string r;
                   r+=a[i];
                   r+=b[j];
                   res.push_back(r);
               }
           }
       }

       if(n==3)
       {
            int n=vec[0].length();
           int m=vec[1].length();
           int o=vec[2].length();

             string a=vec[0];
             string b=vec[1];
               string c=vec[2];
           for(int i=0;i<n;i++)
           {
             

               for(int j=0;j<m;j++)
               {
                   

                   for(int k=0;k<o;k++)
                   {
                       string r;
                       r+=a[i];
                       r+=b[j];
                       r+=c[k];
                       res.push_back(r);
                   }
               }
           }
       }
       if(n==4)
       {

           int n=vec[0].length();
           int m=vec[1].length();
           int o=vec[2].length();
           int g=vec[3].length();

            string a=vec[0];
            string b=vec[1];
             string c=vec[2];
              string d=vec[3];

           for(int i=0;i<n;i++)
           {
              

               for(int j=0;j<m;j++)
               {
                   

                   for(int k=0;k<o;k++)
                   {
                      
                       for(int l=0;l<g;l++){
                         string r;
                        
                         r+=a[i];
                         r+=b[j];
                         r+=c[k];
                         r+=d[l];
                         res.push_back(r);
                       }
                   }
               }
           }
       }
      // return res;
   }

    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string>mp;

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

       // vector<string>res;

        if(digits=="")return res;

        if(digits.length()==1)
        {
            string a=mp[digits[0]];

            for(int i=0;i<a.length();i++)
            {
                string r=string(1,a[i]);
                res.push_back(r);
            }
        }

       generateCombinations(digits,mp);
        return res;
    }
};

int main()
{
    
    return 0;
}