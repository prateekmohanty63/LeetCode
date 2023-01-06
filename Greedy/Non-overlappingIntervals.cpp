#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   
  
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
       

        int n=intervals.size();

       // unordered_map<int,int>mp;

       sort(intervals.begin(),intervals.end());

       int res=0;
       int count=0;
    
       
    
        
        vector<int>interval=intervals[0];
        int flag=0;
        vector<vector<int>>vec;

        for(int i=1;i<n;i++)
        {
            
            if(interval[1]>intervals[i][0])
            {
               // we are taking minimum here , because we want to remove the interval which ends later , hence the interval which we will keep is the one which has a smaller ending point

               // (important point)
            interval[1]=min(interval[1],intervals[i][1]);
             count++;

            }
            else{
               
               vec.push_back(interval);
                interval=intervals[i];
            }
        }

        vec.push_back(interval);

    
       
        for(int i=0;i<vec.size();i++)
        cout<<vec[i][0]<<" "<<vec[i][1]<<endl;

        return count;
    }
}; 

int main()
{
    
    return 0;
}