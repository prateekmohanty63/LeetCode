#include<iostream>
using namespace std;


class Solution {
public:
    int countOdds(int low, int high) {
        
        int res=0; 

        res=(high+1)/2-(low)/2;

        return res;
    }
};


class Solution {
public:
    int countOdds(int low, int high) {
        
        int res=0; 

        for(int i=low;i<=high;i++)
        {
            if(i%2!=0)res++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}