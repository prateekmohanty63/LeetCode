#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
 
    
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());

        int start=0;
        int end=people.size()-1;

        int numberOfBoats=0;

        while(start<end)
        {
            if(people[start]+people[end]<=limit)
            {
                numberOfBoats++;
                start++;
                end--;
            }
            else{
                numberOfBoats++;
                end--;
            }
        }

        if(start==end)numberOfBoats++;
        
        return numberOfBoats;
    }
};

int main()
{
    
    return 0;
}