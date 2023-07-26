#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int binSearch(vector<int>&position,int target)
    {
        int start=0;
        int end=position.size()-1;
        int res=INT_MAX;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(position[mid]==target)
            return mid;

            else if(target>position[mid])
            {
                 start=mid+1;
            }

            else
            {
                res=min(res,mid);
                end=mid-1;
            }
        }
        return res;
    }
    int maxDistance(vector<int>& position, int m) {
        
        int start=1;
        int end=1000000000;
        int res=INT_MIN;
        sort(position.begin(),position.end());

        while(start<=end)
        {
            int mid=start+(end-start)/2;

             bool isPossible=false;
             int prevPos=position[0];
             int tempM=m-1;
             int flag=0;

             while(tempM!=0)
             {
                 int nextPos=prevPos+mid;
                 int pos=binSearch(position,nextPos);

                 if(pos==INT_MAX)
                 {
                     flag=1;
                     break;
                 }
                 prevPos=position[pos];
                 tempM--;

             }
             if(tempM==0)isPossible=true;

             if(isPossible)
             {
                  res=max(res,mid);
                  start=mid+1;
             }
             else{
                 end=mid-1;
             }

        }

        return res;
    }
};

int main()
{
    
    return 0;
}