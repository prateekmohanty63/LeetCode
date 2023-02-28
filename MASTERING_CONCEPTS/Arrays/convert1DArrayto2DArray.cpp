#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>>res;
        
        int k=0;

        if(n*m<original.size() || n*m>original.size())return res;

        for(int i=0;i<m;i++)
        {
            vector<int>vec;

            for(int j=0;j<n;j++)
            {
                vec.push_back(original[k+j]);
            }
            k+=n;
            res.push_back(vec);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}