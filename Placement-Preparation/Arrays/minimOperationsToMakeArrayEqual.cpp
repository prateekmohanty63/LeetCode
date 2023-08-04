#include<iostream>

using namespace std;


class Solution {
public:
    int diffFromMedian(int median,int n)
    {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=abs(median-(2*i+1));
            }
            return sum;
    }
    int minOperations(int n) {
        
        // calculating the media value

        if(n%2==0)
        { 
            int mid=n/2;
            int median1=(2*(mid))+1;
            int median2=(2*(mid-1))+1;

            return min(diffFromMedian(median1,n)/2,diffFromMedian(median2,n)/2);
        }
        else{
              int mid=n/2;
              int median=2*(mid)+1;
              
              return diffFromMedian(median,n)/2;
        }
    }
};

int main()
{
    
    return 0;
}