#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int n=coordinates.size();

        sort(coordinates.begin(),coordinates.end());

        if(n==1)return true;

        if(coordinates[1][0]==coordinates[0][0])
        {
            for(int i=1;i<n-1;i++)
            {
                if(coordinates[i][0]!=coordinates[i+1][0])return false;
            }
            return true;
        }
        
        double slope=abs(coordinates[1][1]-coordinates[0][1])/(double)(coordinates[1][0]-coordinates[0][0]);

        for(int i=1;i<n-1;i++)
        {
            double currslope=abs(coordinates[i+1][1]-coordinates[i][1])/(double)(coordinates[i+1][0]-coordinates[i][0]);

            if(currslope!=slope)return false;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}