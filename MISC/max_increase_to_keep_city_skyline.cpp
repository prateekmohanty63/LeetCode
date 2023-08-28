

/// apppraoch-1
/// Runtime: 8 ms, faster than 75.97% of C++ online submissions for Max Increase to Keep City Skyline.
/// Memory Usage: 9.9 MB, less than 95.82% of C++ online submissions for Max Increase to Keep City Skyline.

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid.size();
        int sum=0;

        vector<int>vec1;
        vector<int>vec2;
        for(int i=0;i<n;i++){
            int a=grid[i][0];
            for(int j=0;j<m;j++){
                int b=grid[i][j];
                if(b>a){
                    a=b;
                }
            }
            vec1.push_back(a);
        }

        for(int i=0;i<n;i++){
            int a=grid[0][i];
            for(int j=0;j<m;j++){
                int b=grid[j][i];
                if(b>a)
                    a=b;
            }
            vec2.push_back(a);
        }

        // for(int i=0;i<vec1.size();i++)
        //     cout<<vec1[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<vec2.size();i++){
        //     cout<<vec2[i]<<" ";
        // }

        for(int i=0;i<n;i++){
            int vec1_num=vec1[i];
            for(int j=0;j<m;j++){
                int min=-1;
                int vec2_num=vec2[j];
                int a=grid[i][j];
                if(vec1_num<=vec2_num)
                    min=vec1_num;
                else
                    min=vec2_num;

                sum+=min-a;
            }
        }

        return sum;
    }
};

/// approach-2
/// Runtime: 7 ms, faster than 78.21% of C++ online submissions for Max Increase to Keep City Skyline.
/// Memory Usage: 10 MB, less than 73.22% of C++ online submissions for Max Increase to Keep City Skyline.

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> rows(n), cols(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min(rows[i], cols[j]) - grid[i][j];
            }
        }

        return res;
    }
};
