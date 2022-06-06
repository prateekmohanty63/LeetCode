#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        
        int m=n.length();
        int count=0;
        
        // for all single digit numbers
        if(m==1)
        {
            return stoi(n); 
        }
        
        int max=INT_MIN;
        
        for(int i=0;i<m;i++)
        {
            int x = (int)n[i] - 48;
            
            if(x>max)max=x;
        }
        return max;
    }
};

int main()
{
    
    return 0;
}