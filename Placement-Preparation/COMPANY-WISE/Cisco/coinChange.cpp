#include<iostream>
#include<vector>
#include<climits>
using namespace std;



int main()
{   

     int n;
     cin>>n;
     vector<int>vec;

     for(int i=0;i<n;i++)
     {
        int a;
        cin>>a;
        vec.push_back(a);
     }

     int start=0;
     int end=100000000;
     int res=INT_MAX;

     while(start<=end)
     {
         int mid=start+(end-start)/2;

         int currMoney=mid;
         int flag=0;

         for(int i=0;i<n;i++)
         {
            currMoney+=vec[i];
            if(currMoney<0)
            {
               flag=1;
               break;
            }
         }

         if(flag==0)
         {
              res=mid;
              end=mid-1;
         }
         else{
               start=mid+1;
         }

     }

     cout<<res;
    
    return 0;
}