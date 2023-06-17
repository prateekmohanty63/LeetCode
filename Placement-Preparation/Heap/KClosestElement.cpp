#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>res;

        int n=arr.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pr;

        // pushing all the elements along with difference in the heap

        for(int i=0;i<n;i++)     // O(NLOGN)
        {
            pair<int,int>p;
            int diff=abs(x-arr[i]);
            int ele=arr[i];
            p.first=diff;
            p.second=ele;

            pr.push(p);
        }

        while(!pr.empty() && k!=0)        //  O(NLOGN)
        {
            pair<int,int>fr=pr.top();
            res.push_back(fr.second);
            pr.pop();
            k--;
        }
        sort(res.begin(),res.end());

        return res;
    }
};

int main()
{
    
    return 0;
}