#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

       sort(costs.begin(),costs.end());

       int n=costs.size();

       int count=0;

       int k=0;

       while(k<n && costs[k]<=coins)
       {
           coins-=costs[k];
           count++;
           k++;
       }

       return count;
    }
};

int main()
{
    
    return 0;
}