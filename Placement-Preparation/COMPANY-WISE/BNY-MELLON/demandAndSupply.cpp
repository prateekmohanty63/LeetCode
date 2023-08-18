#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

int solve(vector<vector<int>>&customers,vector<vector<int>>&shops)
{
   
     int n=shops.size();
     int m=shops[0].size();
     vector<int>itemAvailable;

     for(int i=0;i<n;i++)
     { 
        int itemsAvailable=0;
        for(int k=0;k<shops[i].size();k++)
        {
            itemsAvailable|=(1<<shops[i][k]);
        } 
         for(int j=i+1;j<n;j++)
         {
               int a=itemsAvailable;
               for(int k=0;k<shops[j].size();k++)
               {
                  a|=(1<<shops[j][k]);
               }
               itemAvailable.push_back(a);
         }   
   
     }
  //   for(auto it:itemAvailable)cout<<it<<" ";
  int res=INT_MIN;
   
   vector<int>custNeeded;
    int count=0;
    for(int j=0;j<customers.size();j++)
    {
         int count=0;
         for(int k=0;k<customers[j].size();k++)
         {
            count|=(1<<customers[j][k]);
         }
         custNeeded.push_back(count);
    }

    for(int i=0;i<itemAvailable.size();i++)
    {
        int mask=itemAvailable[i];
        int count=0;

        for(auto it:custNeeded)
        {
            int a=mask&it;
            if(a==it)count++;
        }
        res=max(res,count);
    }
  
    cout<<res<<" ";
     return 0;
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>>customer={{1,2},{1,5}};
    vector<vector<int>>shop={{1,2,3,4},{2,3,4,5},{1,2,4,5}};

    int a=solve(customer,shop);


    return 0;
}