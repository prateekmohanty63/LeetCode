#include<iostream>
#include<set>
using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        
        set<long>set;
        long nthnumber=1;
        set.insert(nthnumber);

        for(int i=0;i<n;i++)
        {
            nthnumber=*set.begin();
            set.erase(nthnumber);
            set.insert(nthnumber*2);
             set.insert(nthnumber*3);
              set.insert(nthnumber*5);
        }
        return nthnumber;
    }
};

int main()
{
    
    return 0;
}