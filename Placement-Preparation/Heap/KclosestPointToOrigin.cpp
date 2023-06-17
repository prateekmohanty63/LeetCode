#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
   double dist(int x1,int y1,int x2,int y2)
   {
       double d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

       double dst=(double)pow(d,0.5);

       return dst;
   }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>res;
        int n=points.size();
        
        // creating a max heap of distance and points
        priority_queue<pair<double,int>>q;

        //cout<<dist(1,3,0,0)<<" "<<dist(-2,2,0,0);

        for(int i=0;i<n;i++)
        {
            pair<double,int>fr;
            fr.first=dist(points[i][0],points[i][1],0,0);
            fr.second=i;
            q.push(fr);

            if(q.size()>k)q.pop();
        }

        while(!q.empty())
        {
             pair<double,int>fr=q.top();
             q.pop();
             int ind=fr.second;
             res.push_back(points[ind]);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}