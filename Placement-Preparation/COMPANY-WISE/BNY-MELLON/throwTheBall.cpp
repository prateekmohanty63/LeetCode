#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    int n;
    cin>>n;
   
   vector<int>reciever;
   for(int i=0;i<n;i++)
   {
       int a;
       cin>>a;
       reciever.push_back(a);
   }

   int k;
   cin>>k;

   // building the adjacenecy matrix
   unordered_map<int,int>adj;

   for(int i=0;i<n;i++)
   {
        adj[i+1]=reciever[i];
   }

   // finding the length of the cycle
   // finding the starting node of the cycle

   int currPosition=1;
   int startOfList;

   unordered_map<int,bool>vis;
   vis[currPosition]=1;

   while(true)
   {
      int nextPos=adj[currPosition];
      if(vis.find(nextPos)!=vis.end())
      {
          startOfList=nextPos;
          break;
      }
      vis[nextPos]=true;
      currPosition=nextPos;
   }

   cout<<"Start of the list: "<<startOfList<<endl;

   // checking if before the cycle , the time gets over
   currPosition=1;

   int timeElapsed=0;
   while(currPosition!=startOfList)
   {
       if(timeElapsed==k)break;
         timeElapsed++;
        int nextPos=adj[currPosition];
        currPosition=nextPos;
   }

   if(timeElapsed==k)
   {
      cout<<"The ball is with "<<currPosition<<" friend";
      return 0;
   }

   int timeRem=k-timeElapsed;

   // finding the length of the cycle
   int len=0;
   currPosition=adj[startOfList];

   while(currPosition!=startOfList)
   {
      len++;
      int nextPos=adj[currPosition];
      currPosition=nextPos;
   }
   len++;

   cout<<"The length of the cycle is: "<<len;
   cout<<endl;

  int rounds=timeRem/len;
  int steps=timeRem-rounds*len;

  currPosition=startOfList;

  while(steps!=0)
  {
     int nextPos=adj[currPosition];
     currPosition=nextPos;
     steps--;
  }

  cout<<"The ball is with "<<currPosition<<" friend";

    
    return 0;
}