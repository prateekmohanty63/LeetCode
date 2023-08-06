#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


void solution(vector<int>nums,long long time)
{
     unordered_map<int,bool>isSeen;
     int startOfList;
     isSeen[1]=true;
     int currPosition=1;
     int timeElapsed=0;


     // 1. Finding the start of the cycle

     while(true)
     {
          int nextPosition=nums[currPosition-1];

          if(isSeen.find(nextPosition)!=isSeen.end())
          {
            startOfList=nextPosition;
            break;
          }

          isSeen[nextPosition]=true;
          currPosition=nextPosition;
        
     }

     currPosition=1;

   // 2. checking if before we enter the cycle the time is elapsed
     while(true)
     {
         if(currPosition==startOfList)break;

         currPosition=nums[currPosition-1];
         timeElapsed++;

         if(timeElapsed==time)
         {
            cout<<"Ball will be with: "<<currPosition<<endl;
            break;
         }
     }

     // f3. inding the length of the cycle 
     time-=timeElapsed;

     currPosition=startOfList;
     int nextPosition=nums[currPosition-1];
     int len=0;

     while(nextPosition!=startOfList)
     {
          nextPosition=nums[nextPosition-1];
          len++;
     }
     len++;

     cout<<"Length of the cycle is: "<<len<<endl;


  //   cout<<startOfList<<" "<<timeElapsed;

 // 4. moving the remaining number of steps 
   int res;
   time=time%len;
   currPosition=startOfList;

   while(time!=0)
   {
      currPosition=nums[currPosition-1];
      time--;
   }
   res=currPosition;

   cout<<"The ball will be with friend: "<<res<<endl;
}


int main()
{
    vector<int>vec;
    int n;
    cin>>n;

    unordered_map<int,int>reciever;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
      
    }

    for(int i=0;i<vec.size();i++)
    {
        reciever[i+1]=vec[i];
    }
    int seconds;
    cin>>seconds;
    
    solution(vec,seconds);
   
  

//    for(auto it:reciever)
//    cout<<it.first<<" "<<it.second<<endl;
    return 0;
}