#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        vector<int>res;

        int minDiff=INT_MAX;
        int closestInd;

        for(int i=0;i<n;i++)
        {
            if(abs(arr[i]-x)<minDiff)
            {
                minDiff=abs(arr[i]-x);
                closestInd=i;
            }
        }

        // push all elements having the minimum difference
        
        int r=closestInd;

        while(k>0 && r<n && abs(arr[r]-x)==minDiff)
        {
            res.push_back(arr[r]);
            r++;
            k--;
        }

        int left=closestInd-1;
        int right=r;

        while(k>0 && left>=0 && right<n)
        {
            if(abs(x-arr[left])>abs(x-arr[right]))
            {
                res.push_back(arr[right]);
                right++;
                k--;
            }
            else{
                res.push_back(arr[left]);
                left--;
                k--;
            }
        }

        // if still k is not 0 , append left ot right index elements

        while(k>0 && left>=0)
        {
             res.push_back(arr[left]);
             left--;
             k--;
        }

         while(k>0 && right<n)
        {
             res.push_back(arr[right]);
             right++;
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

