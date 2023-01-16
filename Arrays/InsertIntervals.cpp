#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// T(N)=O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>res;

        if(intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }
        

       int flag=0;
        for(int i=0;i<intervals.size();i++)
        {
            if(newInterval[0]>=intervals[i][0])continue;

            else{
                intervals.insert(intervals.begin()+i,newInterval);
                flag=1;
                break;
            }
        }

        if(flag==0)intervals.push_back(newInterval);

        for(int i=0;i<newInterval.size();i++)
        {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }

        vector<int>vec=intervals[0];
        
        int n=intervals.size();

        for(int i=1;i<n;i++)
        {
            if(vec[1]>=intervals[i][0])
            {
                vec[1]=max(intervals[i][1],vec[1]);
            }
            else{
                res.push_back(vec);
                vec=intervals[i];
            }
        }

        res.push_back(vec);

        return res;
    }
};


// T(N)=O(nlogn)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>res;
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++)
        {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }

        vector<int>vec=intervals[0];
        
        int n=intervals.size();

        for(int i=1;i<n;i++)
        {
            if(vec[1]>=intervals[i][0])
            {
                vec[1]=max(intervals[i][1],vec[1]);
            }
            else{
                res.push_back(vec);
                vec=intervals[i];
            }
        }

        res.push_back(vec);

        return res;
    }
};

int main()
{
    
    return 0;
}