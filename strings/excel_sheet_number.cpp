#include<iostream>
#include<math.h>

using namespace std;

// 1st approach
/// Faster than 100%

class Solution {
public:
    int titleToNumber(string columnTitle) {
     
        int count=0;
        int n=columnTitle.size();
        
        for(int i=0;i<n;i++){
            char a=columnTitle[i];
            count+=(a-'0'-16)*pow(26,n-1-i);
        }
        cout<<count<<endl;
        return count;
    }
};


int main(){

}