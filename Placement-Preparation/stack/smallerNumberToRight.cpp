#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int>res;
        
        res.push_back(-1);
        
        // stack
        stack<int>stk;
        stk.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            
            if(stk.top()<arr[i])
            {
                res.push_back(stk.top());
            }
            else{
                while(!stk.empty() && stk.top()>=arr[i])stk.pop();
                
                if(stk.empty())res.push_back(-1);
                
                else res.push_back(stk.top());
            }
            stk.push(arr[i]);
          
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends

int main()
{
    
    return 0;
}