/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<climits>
#include<queue>

using namespace std;

pair<int,int> findSubString(string a)
{
    int n=a.length();
    int start=-1;
    int end=-1;
    int maxim=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        int l=i;
        int r=i;
        
        while(l>=0 && r<n && a[l]==a[r])
        {
            l--;
            r++;
        }
        
        if(r-l-1>=maxim)
        {
            maxim=end-start-1;
            start=l+1;
            end=r-1;
        }
        
        l=i;
        r=i+1;
        
        while(l>=0 && r<n && a[l]==a[r])
        {
            l--;
            r++;
        }
        if(r-l-1>=maxim)
        {
            maxim=r-l-1;
            start=l+1;
            end=r-1;
        }
    }
    
    return {start,end};
}

string solve(string a)
{
    queue<string>q;
    q.push(a);
    
    while(!q.empty())
    {
        string tp=q.front();
       // cout<<tp<<" ";
        q.pop();
        pair<int,int>pr=findSubString(tp);
        int start=pr.first;
        int end=pr.second;
        
        if(start>=end)return tp;
        
        else{
            string temp=tp.substr(0,start)+tp.substr(end+1);
            q.push(temp);
        }
    }
    return "";
}

int main()
{
    string a;
    cin>>a;
    
    pair<int,int>pr=findSubString(a);
    cout<<pr.first<<" "<<pr.second<<endl;
    cout<<endl;
    
    string res=solve(a);
    cout<<res;

    return 0;
}
