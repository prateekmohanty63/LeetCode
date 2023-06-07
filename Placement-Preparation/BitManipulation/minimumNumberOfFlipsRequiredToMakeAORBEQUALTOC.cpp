#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flipsRequired=0;
        
        int tempa=a;
        int tempb=b;
        int tempc=c;

        vector<int>num1(32,0),num2(32,0),num3(32,0);

       int k=31;
        while(tempa>0)
        {
            int a1=(tempa&1);
            num1[k--]=a1;
            tempa=tempa>>1;

        }
         
       k=31;
        while(tempb>0)
        {
            int b1=(tempb&1);
            num2[k--]=b1;
            tempb=tempb>>1;
        }
        k=31;
        while(tempc>0)
        {
            int c1=(tempc&1);
            num3[k--]=c1;
            tempc=tempc>>1;
        }
        for(int i=0;i<32;i++)
        cout<<num1[i]<<" ";

        cout<<endl;

        for(int i=0;i<32;i++)
        cout<<num2[i]<<" ";

        cout<<endl;

        for(int i=0;i<32;i++)
        cout<<num3[i]<<" ";

        for(int i=0;i<32;i++)
        {
            int a1=num1[i];
            int b1=num2[i];
            int c1=num3[i];

            if(c1==0)
            {
                if(a1==1)flipsRequired++;
                if(b1==1)flipsRequired++;
            }
            else{
                if(a1==0 && b1==0)flipsRequired++;
            }
        }

        return flipsRequired;
    }
};

int main()
{
    
    return 0;
}