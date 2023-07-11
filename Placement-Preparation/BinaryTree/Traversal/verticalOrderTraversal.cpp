#include<iostream>
using namespace std;



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node

// T(N)=O(N)
// S(N)=O(N)

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int>solve(Node *root)
    {
        vector<int>ans;
        if(!root)return ans;
        
        queue<pair<Node*,int>>q;
        
        // insert root into queue
        q.push({root,0});
        
        map<int,vector<int>>mp;
        
        while(!q.empty())
        {
            pair<Node*,int>fr=q.front();
            q.pop();
            
            mp[fr.second].push_back(fr.first->data);
            
            if(fr.first->left)
            {
                q.push({fr.first->left,fr.second-1});
            }
            if(fr.first->right)
            {
                q.push({fr.first->right,fr.second+1});
            }
        }
        for(auto it:mp)
        {
            vector<int>vec=it.second;
            for(auto itr:vec)ans.push_back(itr);
        }
        return ans;
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        return solve(root);
    }
};






// } Driver Code Ends

int main()
{
    
    return 0;
}