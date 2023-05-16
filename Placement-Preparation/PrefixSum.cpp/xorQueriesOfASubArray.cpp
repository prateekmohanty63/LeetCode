#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>res(n,0);

        for(int i=0;i<n;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];

            if(start==end)
            {
                res[i]=arr[queries[i][0]];
            }
            else{
                int a=arr[start];
                for(int i=start+1;i<=end;i++)
                {
                     a=a^arr[i];
                }
                res[i]=a;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}