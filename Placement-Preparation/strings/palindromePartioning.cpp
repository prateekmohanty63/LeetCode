#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
   
   bool isPali(string a,int startIndex,int endIndex)
   {
        while(startIndex<=endIndex)
        {
          if(a[startIndex]!=a[endIndex])return false;

          startIndex++;
          endIndex--;
        }
        return true;
   }

   void palindromeFunc(int index,vector<string>&ds,vector<vector<string>>&output,string str)
   {
      // base case
      if(index==str.length())
      {
        output.push_back(ds);
        return ;
      }

      for(int i=index;i<str.length();i++)
      {
          if(isPali(str,index,i))
          {
            // if till this index i it is a palindrome , we check the remainging part of the string
            ds.push_back(str.substr(index,i-index+1));
            palindromeFunc(i+1,ds,output,str);
            ds.pop_back();
          }
      }
   }

    vector<vector<string>> partition(string s) {

        int n=s.length();
         vector<vector<string>>res;
        
        if(n==1)return {{s}};
        
        vector<string>ds;

        palindromeFunc(0,ds,res,s);
        
       
        return res;
    }
};

int main()
{
    
    return 0;
}