#include<iostream>
using namespace std;

int main()
{
    
    return 0;
}

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6.3 MB, less than 35.78% of C++ online submissions for Backspace String Compare.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        string str1,str2;
         int index=-1;
      // int k=-1;
        
        for(int i=0;i<n;i++)
        {
          
            if(s[i]!='#'){
                str1+=s[i];
                index++;
            }
            if(s[i]=='#')
            {
               if(index!=-1){
                str1.erase(index,1);
                index--;
               }
            }
        }
        index=-1;
         //k=-1;
        
         for(int i=0;i<m;i++)
        {
             
          
            if(t[i]!='#'){
                str2+=t[i];
                index++;
                }
            if(t[i]=='#')
            {
              if(index!=-1){
                str2.erase(index,1);
                index--;
               }
            }
        }
        cout<<str1<<" "<<str2;
       
        if(str1==str2)return true;
        
        return false;
    }
};