#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    
    int solve(vector<vector<int>>&books,int i,int widthLeft,int maxHeight,int shelfWidth,vector<vector<int>>&dp)
    {
        // base case
        int n=books.size();
        if(i==n)return maxHeight;

        if(dp[i][widthLeft]!=-1)return dp[i][widthLeft];

        int currShelf=INT_MAX;
        int nextShelf=INT_MAX;

        int bookWidth=books[i][0];
        int bookHeight=books[i][1];

        if(bookWidth<=widthLeft){
            // option of keeping here or going to next cell

            currShelf=solve(books,i+1,widthLeft-bookWidth,max(maxHeight,bookHeight),shelfWidth,dp);
        }

        nextShelf=maxHeight+solve(books,i+1,shelfWidth-bookWidth,bookHeight,shelfWidth,dp);

        return dp[i][widthLeft]=min(currShelf,nextShelf);
    }
  
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
           
           int n=books.size();
         vector<vector<int>> dp(1001, vector<int> (shelfWidth + 1, -1));
        
        int res=solve(books,0,shelfWidth,0,shelfWidth,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}