#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(string a,string b)
{
     int n=a.length();
     int m=b.length();

     int res=0;
     
     for(int i=0;i<n;i++){
        int ptr1=i;
        int ptr2=0;
        int count=0;
      while(ptr1<n && ptr2<m)
     {
         if(a[ptr1]==b[ptr2])
         count++;

         else break;

         ptr1++;
         ptr2++;
      }
      res=max(res,count);
     }
     return res;
}

int main()
{
    int n;
    cin>>n;
    vector<string>command={"000","1110","01","001","110","11"};

    // for(int i=0;i<n;i++)
    // {
    //     string a;
    //     cin>>a;
    //     command.push_back(a);
    // }
    vector<int>res;
    res.push_back(0);
    vector<string>str;
    str.push_back(command[0]);

    for(int i=1;i<n;i++)
    {
        int maxCount=INT_MIN;
        int ind;
        for(int j=0;j<str.size();j++)
        {
            int a=solve(str[j],command[i]);

            if(a>=maxCount)
            {
                maxCount=a;
                ind=j;
            }
        }
        if(maxCount==0)res.push_back(i);

        else res.push_back(ind);

        str.push_back(command[i]);
    }
    for(auto it:res)cout<<it<<" ";
    return 0;
}