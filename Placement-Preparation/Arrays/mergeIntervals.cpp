#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>res;
        int n=intervals.size();

        // sorting the intervals based on starting points
        sort(intervals.begin(),intervals.end());
        
        int currStartPoint=intervals[0][0];
        int currEndPoint=intervals[0][1];

        for(int i=0;i<n;i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(start<=currEndPoint)
            {   
                currStartPoint=min(currStartPoint,start);
                currEndPoint=max(currEndPoint,intervals[i][1]);
            }
            else{
                vector<int>vec;
                vec.push_back(currStartPoint);
                vec.push_back(currEndPoint);
                res.push_back(vec);
                currStartPoint=intervals[i][0];
                currEndPoint=intervals[i][1];
            }
        }
        vector<int>vec;
        vec.push_back(currStartPoint);
        vec.push_back(currEndPoint);
        res.push_back(vec);

    return res;
    }
};

int main()
{
    
    return 0;
}