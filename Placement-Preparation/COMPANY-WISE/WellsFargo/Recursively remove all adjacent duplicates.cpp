#include<iostream>
#include<queue>

using namespace std;

class Solution{
public:
    bool isValid(string s)
    {
        int n=s.length();
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])return false;
        }
        return true;
    }
    string res;
    
    string solve(string s)
    {
        // base case
        int n=s.length();
        
        queue<string>q;
        q.push(s);
        
        while(!q.empty())
        {
            string tp=q.front();
            q.pop();
            
            if(tp.size()==0)break;
           // cout<<tp<<" ";
            
            if(isValid(tp))return tp;
            
            // removing adjacent characters
            string a;
            int i=0;
            int n=tp.size();
            
            for(int i=0;i<tp.size()-1;i++)
            {
                if(tp[i]==tp[i+1])
                {
                    char ele=tp[i];
                   
                    while(i<n && tp[i]==ele)i++;
                    
                    i--;
                }
                else{
                    a+=tp[i];
                }
            }
            if(tp[n-1]!=tp[n-2])a+=tp[n-1];
           // cout<<a<<" ";
            q.push(a);
            
        }
        
        return "";
    }
    string rremove(string s){
        // code here
        
        int n=s.length();
        
        if(n==0)return s;
        if(n==1)return s;
        
        string res=solve(s);
        if(res.size()==0)return "";
       // cout<<res.size();
        
        return res;
    }
};

int main()
{
    
    return 0;
}