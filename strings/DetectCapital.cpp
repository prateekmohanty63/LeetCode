#include<iostream>
using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        
        // all letters are capital

        int n=word.length();
        int flag=0;

        for(int i=0;i<n;i++)
        {
           if(int(word[i])<65 || int(word[i])>90)flag=1;
        }



        if(flag==0)return true;

           cout<<"First test-case"<<" ";

        // all letters are not capital

        flag=0;

         for(int i=0;i<n;i++)
        {
           if(int(word[i])<97 || int(word[i])>122)flag=1;
        }

        if(flag==0)return true;

        cout<<"Second test-case"<<" ";

        flag=0;

        // only first letter capital and rest are lower-case

        if(int(word[0])>=65 && int(word[0])<=90)
        {
            for(int i=1;i<n;i++)
            {
               if(int(word[i])<97 || int(word[i])>122)flag=1;
            }

            if(flag==0)return true;

              cout<<"Third test-case"<<" ";
        }
              
              return false;
    }
};

int main()
{
    
    return 0;
}