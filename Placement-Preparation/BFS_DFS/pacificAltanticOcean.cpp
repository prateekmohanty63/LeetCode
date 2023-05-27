#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &ocean, int x, int y, int m, int n){
        ocean[x][y] = 1;

        if(x+1 < m and heights[x+1][y] >= heights[x][y] and ocean[x+1][y] == 0){
            dfs(heights, ocean, x+1, y, m, n);
        }
        if(x-1 >=0 and heights[x-1][y] >= heights[x][y] and ocean[x-1][y] == 0){
            dfs(heights, ocean, x-1, y, m, n);
        }
        if(y+1 < n and heights[x][y+1] >= heights[x][y] and ocean[x][y+1] == 0){
            dfs(heights, ocean, x, y+1, m, n);
        }
        if(y-1 >=0 and heights[x][y-1] >= heights[x][y] and ocean[x][y-1] == 0){
            dfs(heights, ocean, x, y-1, m, n);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // for pacific traversal
        for(int i=0; i<n; i++){
            dfs(heights, pacific, 0, i, m, n);
        }
        for(int i=0; i<m; i++){
            dfs(heights, pacific, i, 0, m, n);
        }

        //for atlantic trversal
        for(int i=0; i<m; i++){
            dfs(heights, atlantic, i, n-1, m, n);
        }
        for(int i=0; i<n; i++){
            dfs(heights, atlantic, m-1, i, m, n);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] == 1 and atlantic[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}