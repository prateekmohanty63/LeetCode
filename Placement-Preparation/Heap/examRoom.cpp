#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class ExamRoom {
public:
    int noSeats;
    int k;
    vector<int>vec;
    vector<int>maxDistance;

    ExamRoom(int n) {
        noSeats=n;
        vec.resize(n,0);
        maxDistance.resize(n,INT_MAX);
        k=0;

    }
    int seat() {
        
        if(k==0)
        {
            // we will make the first person seat at the 0th seat
            vec[0]=1;
            for(int i=1;i<noSeats;i++)
            {
                maxDistance[i]=i;
            }
            k=1;
            return 0;
        }
        else{
            // searching for the seat with maximum distance
            int index;
            int maxDist=INT_MIN;
            for(int i=0;i<noSeats;i++)
            {
                if(vec[i]==0 && maxDistance[i]>maxDist)
                {
                    maxDist=maxDistance[i];
                    index=i;
                }
            }
            vec[index]=1;

            // re-calculating the max-leftDistance and max-rightDistance
            vector<int>left(noSeats);
            vector<int>right(noSeats);

            // left-part

            left[0]=INT_MAX;
            
            int sum;
            if(vec[0]==1)sum=0;
            else sum=1;

            for(int i=1;i<noSeats;i++)
            {
                sum++;
                if(sum==i+1)
                left[i]=INT_MAX;

                else left[i]=sum;

                if(vec[i]==1)sum=0;
            }
            
            // right-part
            right[noSeats-1]=INT_MAX;

            if(vec[noSeats-1]==1)sum=0;
            else sum=1;
            
           
            for(int i=noSeats-2;i>=0;i--)
            {
                  sum++;
                  if(sum==(noSeats-i))
                  right[i]=INT_MAX;

                  else right[i]=sum;

                  if(vec[i]==1)sum=0;
            }

            // updating the max-distance
            for(int i=0;i<noSeats;i++)
            {
                maxDistance[i]=min(left[i],right[i]);
            }
            return index;
        }
       
    }
    
    void leave(int p) {
        // mark the place as 0
        vec[p]=0;

        // re-calculate the max-distance

         // re-calculating the max-leftDistance and max-rightDistance
            vector<int>left(noSeats);
            vector<int>right(noSeats);

            // left-part

            left[0]=INT_MAX;
            
            int sum;
            if(vec[0]==1)sum=0;
            else sum=1;

            for(int i=1;i<noSeats;i++)
            {
                sum++;
                if(sum==i+1)
                left[i]=INT_MAX;

                else left[i]=sum;

                if(vec[i]==1)sum=0;
            }
            
            // right-part
            right[noSeats-1]=INT_MAX;

            if(vec[noSeats-1]==1)sum=0;
            else sum=1;

            for(int i=noSeats-2;i>=0;i--)
            {
                  sum++;

                  if(sum==(noSeats-i))
                  right[i]=INT_MAX;

                  else right[i]=sum;

                  if(vec[i]==1)sum=0;
            }

            // updating the max-distance
            for(int i=0;i<noSeats;i++)
            {
                maxDistance[i]=min(left[i],right[i]);
            }

    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main()
{
    
    return 0;
}