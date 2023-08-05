#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        if(row.size()<=2)return 0;

        vector<int>pos(row.size());

        for(size_t i=0;i<row.size();i++)
        {
            pos[row[i]]=i;
        }
        int count=0;

        for(int i=0;i<row.size();i+=2)
        {
            int me=row[i];
            int myCouple=(me&1)?me-1:me+1;

            if(row[i+1]!=myCouple){
                count++;
                int neighbor=row[i+1];

                // swap the current neighbour with my couple
                row[pos[myCouple]]=neighbor;

                // update neighbour's position
                pos[neighbor]=pos[myCouple];
            }
        }
        return count;
    }
};

int main()
{
    
    return 0;
}