#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        
        if(n==0)return 0;
       
       // finding number of perfect squares between 1 and n
       // only the perfect squares will be open after n iterations
       return (floor(sqrt(n)) - ceil(sqrt(1)) + 1);
    }
};

int main()
{
    
    return 0;
}