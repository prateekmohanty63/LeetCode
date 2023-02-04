#include<iostream>
#include<algorithm>
using namespace std;


// passed all test cases

class Solution {
public:

//   void generateSubstr(string s1,unordered_map<string,bool>&mp)
//   {
//       int n=s1.length();

//       for(int i)
//   }

    bool checkInclusion(string s1, string s2) {
        
        if(s1==s2)return true;
        int n=s2.length();
        int m=s1.length();

        sort(s1.begin(),s1.end());

        for(int i=0;i<=n-m;i++)
        {
            string substr=s2.substr(i,m);

            sort(substr.begin(),substr.end());
            

            if(substr==s1)return true;
        }

        return false;
    }
};


// Solution correct (TLE)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1==s2)return true;
        int n=s2.length();
        int m=s1.length();

        sort(s1.begin(),s1.end());

        for(int i=0;i<n;i++)
        {
            string substr=s2.substr(i,m);

            sort(substr.begin(),substr.end());
            

            if(substr==s1)return true;
        }

        return false;
    }
};

int main()
{
    
    return 0;
}