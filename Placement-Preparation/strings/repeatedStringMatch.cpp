#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool solve(string a,string b)
    {
        int n=a.length();
        int m=b.length();

        unordered_map<char,int>mp;

        for(int i=0;i<26;i++){

            char ele=char(97+i);
            mp[ele]=i+1;
        }

        int target=0;

        for(int i=0;i<m;i++)target+=mp[b[i]];

        int currCount=0;

        for(int i=0;i<m;i++)currCount+=mp[a[i]];

        int k=0;

        for(int i=0;i<=n-m;i++)
        {
            if(currCount==target)
            {
                string e=a.substr(i,m);

                if(e==b)return true;
            }

            // subtract the first element from window
            currCount-=mp[a[k++]];
           
           if(i+m<n)
            currCount+=mp[a[i+m]];
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        
        int n=a.length();
        int m=b.length();

        string temp=a;

        int ans=1;

        while(a.size()<b.size()){
            ans++;
            a+=temp;
        }

        if(solve(a,b))return ans;

        if(solve(a+temp,b))return ans+1;

        return -1;

    }
};

int main()
{
    
    return 0;
}