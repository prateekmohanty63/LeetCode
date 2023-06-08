#include<iostream>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)return 1;

        if(n==1)return 10;

        int count=10;

        while(n>1)
        {
           if(n==2)
           count+=(9*9);

           else if(n==3)count+=(9*9*8);

           else if(n==4)count+=(9*9*8*7);

           else if(n==5)count+=(9*9*8*7*6);

           else if(n==6)count+=(9*9*8*7*6*5);

           else if(n==7)count+=(9*9*8*7*6*5*4);

           else if(n==8)count+=(9*9*8*7*6*5*4*3);

           n--;
        }
        return count;
    }
};

int main()
{
    
    return 0;
}