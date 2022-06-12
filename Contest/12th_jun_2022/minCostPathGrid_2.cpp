#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int PathCost=0;
        
        int n=grid.size();
        int m=grid[0].size();
        int step=0;
        int movedIndex=0;
        
       
        
        for(int i=0;i<n-1;i++)
        {
             int minCost=INT_MAX;
             int resValue;
             
            // break if go out of grid (last grid cost excluded)
            if(step==n-1)break;

            for(int j=movedIndex;j<m;j++)
            {
                int tempminCost=INT_MAX;
                int tempMoveIndex;
                if(step==n-1)break;
                int value=grid[i][j];
                cout<<"value"<<" "<<value<<endl;
                for(int k=0;k<m;k++)
                {
                    int cost=moveCost[value][k];
                    
                    if(cost<tempminCost)
                    {
                        tempminCost=cost;
                        tempMoveIndex=k;
                       
                    }
                }
                
                if(tempminCost<minCost)
                {
                    minCost=tempminCost;
                    resValue=value;
                    movedIndex=tempMoveIndex;
                   // cout<<"MOVEDINDEX"<<" "<<movedIndex<<endl;
                }
            }
            cout<<"minCost"<<" "<<minCost<<endl; 
            PathCost+=(minCost+resValue);
            step++;
            
            //cout<<step<<" ";
        }
        
        cout<<movedIndex;
        return PathCost+grid[n-1][movedIndex];
    }
};

int main()
{
    
    return 0;
}