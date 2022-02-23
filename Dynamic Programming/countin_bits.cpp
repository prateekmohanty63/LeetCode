#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


// 1st approach

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>vec1;
        
        
        vec1.push_back(0);
        
        if(n==0)return vec1;
        
        vec1.push_back(1);
        
        for(int i=2;i<=n;i++){
            
            if(ceil(log2(i))==floor(log2(i)))vec1.push_back(1);
            
            else{
                int a=i&(i-1);
              if(i%2==0) vec1.push_back(vec1[a]+vec1[i-a]);
            
            else vec1.push_back(vec1[i-1]+vec1[1]);
            }
        }
               return vec1;
    }
};