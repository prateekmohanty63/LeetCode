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



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.

vector<int> solve(Node* root)
{
    vector<int>res;
    vector<vector<int>>vec;
    
    if(!root)return res;
    queue<Node*>q;
    
    q.push(root);
    bool leftToRight=false;
    
    while(!q.empty())
    {
        int size=q.size();
        vector<int>v(size);
        
        for(int i=0;i<size;i++)
        {
            Node* tp=q.front();
            q.pop();
            
            int index=(leftToRight)?i:(size-i-1);
            v[index]=tp->data;
            
            if(tp->left)q.push(tp->left);
            
            if(tp->right)q.push(tp->right);
            
          
        }
        vec.push_back(v);
        leftToRight=!leftToRight;
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        res.push_back(vec[i][j]);
    }
    return res;
}

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>res=solve(root);
    
    return res;
}


int main()
{
    
    return 0;
}