#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Passing all test cases 
class Solution {
public:
    int n ;
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
        visited[index] = true;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i] &&
               ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);
        
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(visited[i])
                continue;
            dfs(stones, i, visited);
            count++;
        }
        
        return n - count;
    }
};

// TLE

class Solution {
public:
     
    void dfs(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&vis)
    {
        // base case
        int n=mat.size();
        int m=mat[0].size();

        if(i<0 || i>=n)return ;

        if(j<0 || j>=m)return ;

        vis[i][j]=1;

        // moving in the same row
        for(int k=0;k<m;k++)
        {
            if(mat[i][k]==1 && vis[i][k]==0)
            dfs(mat,i,k,vis);
        }

        // moving in the same column
        for(int k=0;k<n;k++)
        {
            if(mat[k][j]==1 && vis[k][j]==0)
            dfs(mat,k,j,vis);
        }
        
        
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n=INT_MIN;
        int m=INT_MIN;

        for(int i=0;i<stones.size();i++){
          m=max(m,stones[i][1]);
          n=max(n,stones[i][0]);
        }
        n++;
        m++;
        
        int totalNumberOfStones=stones.size();

        // matrix
        vector<vector<int>>mat(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
      
      // marking the stone pos as 1
        for(int i=0;i<stones.size();i++)
        {
            int a=stones[i][0];
            int b=stones[i][1];
            mat[a][b]=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
        
        int noGroups=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(mat[i][j]==1 && vis[i][j]==0)
                {
                    noGroups++;
                    dfs(mat,i,j,vis);
                }
            }
            
        }
       cout<<endl;
       cout<<totalNumberOfStones<<" "<<noGroups;    

        return totalNumberOfStones-noGroups;
       
    }
};

int main()
{
    
    return 0;
}