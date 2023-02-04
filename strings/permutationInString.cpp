#include<iostream>
#include<algorithm>
using namespace std;


// optimized solution
// Time complexity: O(N)
// Space complexity : O(26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.length();
        int m=s2.length();

        if(s1==s2)return true;

        if(m<n)return false;

       // if(n==m && s1!=s2)return false;

        vector<int>chars(26,-1);
        vector<int>chars1(26,-1);

        for(int i=0;i<n;i++)
        {
            chars[s1[i]-'a']+=1;
        }
        
        int ptr1=0;
        int ptr2=n;

        for(int i=0;i<ptr2;i++)
        {
            chars1[s2[i]-'a']+=1;
        }

       if(chars==chars1)return true;

        while(ptr2<m)
        {
             

            char left=s2[ptr1];
            char right=s2[ptr2];
            cout<<left<<" "<<right<<endl;

            chars1[left-'a']--;
            chars1[right-'a']++;

            ptr2++;
            ptr1++;

          if(chars==chars1)return true;
            
        }

       return false;
    }
};


// passed all test cases  
// Time complexity: O(N*N*logN)

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