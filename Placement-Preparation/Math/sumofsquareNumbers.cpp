#include<iostream>
#include<cmath>
using namespace std;


class Solution {
public:
    bool judgeSquareSum(int c) {
          if(ceil(sqrt(c))==floor(sqrt(c)))return true;
        int maxim=floor(sqrt(c));

        // perfect square
        if(ceil(sqrt(c))==floor(sqrt(c)))return true;

        for(int i=1;i<=maxim;i++)
        {
            int num1=i*i;
            int tar=c-num1;
              if(ceil(sqrt(tar))==floor(sqrt(tar)))return true;
            
        }
        return false;
    }
};

int main()
{
    
    return 0;
}