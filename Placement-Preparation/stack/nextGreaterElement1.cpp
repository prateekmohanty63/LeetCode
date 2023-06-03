#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;




// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>res;
        stack<long long>stk;
        
        res.push_back(-1);
        stk.push(arr[n-1]);
        
        
        for(int i=n-2;i>=0;i--)
        {
            long long currEle=arr[i];
            
            if(stk.top()>currEle)
            {
                res.push_back(stk.top());
                stk.push(currEle);
            }
            else{
                while(!stk.empty() && stk.top()<=currEle)stk.pop();
                
                if(stk.empty())
                {
                    res.push_back(-1);
                    stk.push(currEle);
                }
                else{
                    res.push_back(stk.top());
                    stk.push(currEle);
                }
            }
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();

        vector<int>res;

        for(int i=0;i<n;i++)
        {
            int flag=0;
            int flag1=0;

            for(int j=0;j<m;j++)
            {
                  if(nums2[j]==nums1[i])flag=1;

                  if(nums2[j]>nums1[i] && flag==1)
                  {
                      flag1=1;
                      res.push_back(nums2[j]);
                      break;
                  }
            }
            if(flag1==0)res.push_back(-1);
        }
      //  res.push_back(-1);
        return res;
    }
};

int main()
{
    
    return 0;
}