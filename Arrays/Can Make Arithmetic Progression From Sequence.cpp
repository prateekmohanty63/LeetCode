#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        int n=arr.size();

        if(n==1)return true;
        
        sort(arr.begin(),arr.end());

        int currDiff=arr[1]-arr[0];

          for(int i=1;i<n-1;i++)
          {
              if(arr[i+1]-arr[i]!=currDiff)return false;
          }
          return true;
    }
};

int main()
{
    
    return 0;
}