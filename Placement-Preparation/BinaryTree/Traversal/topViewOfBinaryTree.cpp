#include<iostream>
using namespace std;

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution
{
    public:
    
    vector<int> solve(Node *root)
    {
        vector<int>ans;
        if(!root)return ans;
        
        // queue for vertical order traversal
        queue<pair<Node*,int>>q;
        
        // push the root to queue
        q.push({root,0});
        
        map<int,int>mp;
        
        while(!q.empty())
        {
            pair<Node*,int>tp=q.front();
            q.pop();
            Node *rt=tp.first;
            int line=tp.second;
            
            if(mp.find(line)==mp.end())mp[line]=rt->data;
            
            if(rt->left)
            {
                q.push({rt->left,line-1});
            }
            if(rt->right)
            {
                q.push({rt->right,line+1});
            }
            
        }
        
        for(auto it:mp)ans.push_back(it.second);
        
        return ans;
    }
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>res=solve(root);
        
        return res;
    }

};





int main()
{
    
    return 0;
}