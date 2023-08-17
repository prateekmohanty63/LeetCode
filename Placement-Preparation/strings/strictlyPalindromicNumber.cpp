#include<iostream>

using namespace std;


class Solution {
public:
   string baseRepresentation(int number,int base)
   {
        if (number== 0) {
        return "0";
      }
      string result="";

      while(number>0)
      {
          int rem=number%base;
          result+=to_string(rem);
          number/=base;
      }
      return result;
   }
    bool isStrictlyPalindromic(int n) {
        
        for(int base=2;base<=n-2;base++)
        {
           string res=baseRepresentation(n,base);
            int start=0;
            int end=res.length()-1;
            while(start<=end)
            {
                if(res[start]!=res[end])return false;

                start++;
                end--;
            }
            cout<<res<<" ";

        }
        return true;
    }
};

int main()
{
    
    return 0;
}