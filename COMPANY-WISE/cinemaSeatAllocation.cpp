#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// GIVING TLE
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
          
          unordered_map<string,bool>mp;
          int res=0;

          int m=reservedSeats.size();

         for(int i=0;i<m;i++)
         {
             string a=to_string(reservedSeats[i][0])+"*"+to_string(reservedSeats[i][1]);
             mp[a]=true;
         }

         for(int i=1;i<=n;i++)
         {
             string left1=to_string(i)+"*"+to_string(2);
             string left2=to_string(i)+"*"+to_string(3);
             string left3=to_string(i)+"*"+to_string(4);
             string left4=to_string(i)+"*"+to_string(5);

             string mid1=to_string(i)+"*"+to_string(4);
             string mid2=to_string(i)+"*"+to_string(5);
             string mid3=to_string(i)+"*"+to_string(6);
             string mid4=to_string(i)+"*"+to_string(7);

             string right1=to_string(i)+"*"+to_string(6);
             string right2=to_string(i)+"*"+to_string(7);
             string right3=to_string(i)+"*"+to_string(8);
             string right4=to_string(i)+"*"+to_string(9);
             int flag=0;

             if(mp.find(left1)==mp.end() && mp.find(left2)==mp.end() && mp.find(left3)==mp.end() && mp.find(left4)==mp.end())
             {
                 cout<<left1<<" ";
                 res++;
                 flag=1;

             }
             if(mp.find(right1)==mp.end() && mp.find(right2)==mp.end() && mp.find(right3)==mp.end() && mp.find(right4)==mp.end())
             {
                 cout<<right1<<" ";
                 res++;
                 flag=1;
             }
             else if(flag==0 && mp.find(mid1)==mp.end() && mp.find(mid2)==mp.end() && mp.find(mid3)==mp.end() && mp.find(mid4)==mp.end())
             {
                 cout<<mid1<<" ";
                 res++;
             }

         }
         return res;
    }
};

int main()
{
    
    return 0;
}