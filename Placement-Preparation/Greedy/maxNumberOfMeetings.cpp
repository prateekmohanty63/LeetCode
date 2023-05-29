#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code 
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            pair<int,int>pr;
            pr.first=end[i];
            pr.second=start[i];
            vec.push_back(pr);
            
        }
        sort(vec.begin(),vec.end());
      
        
        int maxMeetingCompleted=1;
        
        int currEndTime=vec[0].first;
        
        for(int i=1;i<n;i++)
        {
            if(vec[i].second>currEndTime)
            {
                maxMeetingCompleted++;
                currEndTime=vec[i].first;
            }
        }
        
        return maxMeetingCompleted;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}