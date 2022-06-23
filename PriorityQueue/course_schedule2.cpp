#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Runtime: 423 ms, faster than 33.28% of C++ online submissions for Course Schedule III.
// Memory Usage: 63.6 MB, less than 21.80% of C++ online submissions for Course Schedule III.

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        if(courses.size()<=0)return 0;
        
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int>q;
        
        int sum=0;
        
        for(auto i:courses)
        {
            sum+=i[0];
            q.push(i[0]);
            if(sum>i[1])
            {
                sum-=q.top();
                
                q.pop();
            }
        }
        return q.size();
    }
};

int main()
{
    
    return 0;
}