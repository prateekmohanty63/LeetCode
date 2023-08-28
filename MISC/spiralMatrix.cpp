#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res ;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0 ,down = m-1;
        int left = 0, right = n -1;
        int dir = 0;
        
        while(top <= down and left <= right){
            
            if(dir == 0){
                for(int i = left ; i <= right; i++)
                    res.push_back(matrix[top][i]);
                top++;
            }
            
            else if(dir == 1){
                for(int i = top; i <= down; i++)
                    res.push_back(matrix[i][right]);
                right --;
            }
            
            else if(dir == 2){
                for(int i = right; i>= left; i--)
                    res.push_back(matrix[down][i]);
                down--;
            }
            
            else{
                for(int i = down; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
         
            dir+=1;
            dir%=4;
        }        
        
        return res;
    }
};