#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// All testcases passed
// two pointer approach
// Time Complexity: O(n*26) == O(n)
// space complexity: O(26)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        // sorting p 

       // sort(p.begin(),p.end());

        vector<int>chars(26,-1);
        vector<int>chars1(26,-1); 
        vector<int>res;

       

         int m=p.length();
         int n=s.length();

          int start=0;
          int end=m-1;

         if(n<m)return res;

         for(int i=0;i<m;i++)
         {
             chars[p[i]-'a']++;
         }
         
         for(int i=0;i<m;i++)
         {
             chars1[s[i]-'a']++;
         }
        
           if(chars==chars1)
            {
                res.push_back(start);
            }

       

        while(end+1<s.length())
        {
           
            
            chars1[s[start]-'a']--;
            chars1[s[end+1]-'a']++;
 
             start++;
            end++;

            if(chars==chars1)
            {
                res.push_back(start);
            }


            
        }

        return res;
    }
};

// Logic correct (TLE)
// 34/64 passed

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        // sorting p 

        sort(p.begin(),p.end());
        vector<int>res;

        int ptr1=0;
        

        int m=p.length();

        while(ptr1+m<=s.length())
        {
            string a=s.substr(ptr1,m);

            sort(a.begin(),a.end());

            if(a==p)res.push_back(ptr1);

            ptr1++;

        }

        return res;
    }
};

int main()
{
    
    return 0;
}