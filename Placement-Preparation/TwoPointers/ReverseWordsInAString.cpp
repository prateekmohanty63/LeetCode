#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>vec;
        string res;
       
       // removing the front spaces
       int start=0;
       int end=s.size()-1;
       
        while(s[start]==' ')start++;

        while(s[end]==' ')end--;

       string wrd;
        for(int i=start;i<=end;i++)
        {
            if(s[i]!=' ')wrd+=s[i];

            else {
                vec.push_back(wrd);
                wrd="";
                while(s[i+1]==' ')i++;
            }
        }
        vec.push_back(wrd);

        for(auto it:vec)cout<<it<<" ";

        for(int i=vec.size()-1;i>0;i--)
        {
            res+=vec[i];
            res+=" ";
        }
        res+=vec[0];

        return res;

    }
};

int main()
{
    
    return 0;
}