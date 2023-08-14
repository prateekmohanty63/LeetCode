#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;


bool isPalindrome(string a)
{
    int n=a.length();
    int start=0;
    int end=n-1;

    while(start<=end)
    {
        if(a[start]!=a[end])return false;

        start++;
        end--;
    }
    return true;
}

bool containsS2(string s1,string s2)
{
    int n=s1.length();
    int start=0;
    int end=s2.length()-1;

    while(end<n)
    {
        string s=s1.substr(start,end-start+1);
        if(s==s2)return true;

        start++;
        end++;
    }
    return false;
}

int solve(string s1,string s2)
{
    queue<pair<int,string>>q;
    q.push({0,s1});
    unordered_map<string,bool>vis;
    vis[s1]=true;
    int n=s1.length();

    while(!q.empty())
    {
        //cout<<"IN";
        string curr=q.front().second;
        int moves=q.front().first;
        q.pop();

        if(isPalindrome(curr) && containsS2(curr,s2)){
            cout<<curr<<" ";
            cout<<endl;
        return moves;
        }

        for(int i=0;i<n;i++)
        {
            string tmp=curr;
            for(char c='a';c<='z';c++)
            {
                 tmp[i]=c;

                 if(vis.find(tmp)==vis.end())
                 {
                    vis[tmp]=true;
                    q.push({moves+1,tmp});
                 }
            }

        }
    }
    return -1;
}

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;

    cout<<solve(s1,s2);
    return 0;
}