#include<iostream>
using namespace std;

// T(N)=O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long nn=n;

        if(nn<0)nn=-1*nn;

        while(nn!=0)
        {
            if(nn%2==1)
            {
                ans=ans*x;
                nn--;
            }
            else{
               x=x*x;
               nn/=2;
            }
        }

        if(n<0)return 1/(double)ans;
        return ans;
    }
};


// TLE 
// O(N)
class Solution {
public:
    double myPow(double x, int n) {
        
        double res=1;

        if(x==1)return 1;
       
       double a=n;

       if(a<0)a=(double)-1*a;

       else a=n;

        while(a!=0)
        {
            res*=x;
            a--;
        }

        if(n>=0)return res;

        else{
            return 1/(double)res;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}