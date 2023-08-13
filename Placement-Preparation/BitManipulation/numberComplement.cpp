#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        
        int res=0;
        int temp=num;
        int k=0;

        while(temp>0)
        {
            int bit=temp&1;
            if(bit==0)res+=pow(2,k);
             
             temp>>=1;
            k++;
        }

        return res;
    }
};

int main()
{
    
    return 0;
}