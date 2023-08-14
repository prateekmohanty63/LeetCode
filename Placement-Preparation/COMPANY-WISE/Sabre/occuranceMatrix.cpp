#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    int m;
    int k;
    cin>>n>>m>>k;

    vector<vector<int>>mat;

    for(int i=0;i<n;i++)
    {
        vector<int>vec;
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
        }
        mat.push_back(vec);
    }

    // making square matrix
    if(n<m)
    {
       vector<int>temp;
       for(int i=0;i<m;i++)temp.push_back(1);
       int diff=m-n;
       while(diff!=0)
       {
        mat.push_back(temp);
        diff--;
       }
    }
    else if(n>m)
    {
        int diff=n-m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<diff;j++)
            mat[i].push_back(1);
        }
    }

    unordered_map<int,int>leftDiag;

    n=mat.size();

    for(int i=n-1;i>=0;i--)
    leftDiag[mat[i][i]]++;

    unordered_map<int,int>total;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            total[mat[i][j]]++;
        }
    }
    int flag=0;
    for(auto it:leftDiag)
    {
        int freq=it.second;
        int totalFreq=total[it.first];
        if(totalFreq-freq<=k)
        {
           cout<<"Not Present";
           flag=1;
           break;
        }
    }
    if(flag==0)cout<<"Present";
    return 0;
}