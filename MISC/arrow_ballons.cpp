class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
{
    return b[1] > a[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {

        int n=points.size();
        if(n==1)
            return 1;

        int count=0;

        sort(points.begin(),points.end(),cmp);
        int arrow=1;
        int pointer=points[0][1];

        int end=points[0][1];

        for(int i=1;i<n;i++){

            if(points[i][0]<=end)
                continue;
            else{
                arrow++;
                end=points[i][1];
            }
        }

        return arrow;

    }
};
