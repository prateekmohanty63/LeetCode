//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        
        vector<int>res;
        
        int currMaxim=INT_MIN;
        int maxIndex;
        
        for(int i=0;i<k;i++){
         if(arr[i]>=currMaxim)
         {
             currMaxim=arr[i];
             maxIndex=i;
         }
        }
        
        res.push_back(currMaxim);
        
        int start=1;
        int end=k;
        
        while(end<n)
        {
            if(arr[end]>=currMaxim)
            {
                currMaxim=arr[end];
                maxIndex=end;
            }
            
            if(maxIndex>=start && maxIndex<=end)
            {
                res.push_back(currMaxim);
            }
            else{
                int maxim=INT_MIN;
                int maxIndex1;
                for(int i=start;i<=end;i++)
                {
                    if(arr[i]>=maxim)
                    {
                        maxim=arr[i];
                        maxIndex1=i;
                    }
                }
                res.push_back(maxim);
                currMaxim=maxim;
                maxIndex=maxIndex1;
            }
            start++;
            end++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends