

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};




// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


void solve(Node *root,vector<int>&res,queue<Node*>&q)
{
    if(!root)return ;
    
    res.push_back(root->data);
    if(root->left)q.push(root->left);
    
    if(root->right)
    {
        solve(root->right,res,q);
        
    }
    else{
        if(!q.empty()){
        Node* nextDiag=q.front();
        q.pop();
        solve(nextDiag,res,q);
        }
    }
}

vector<int> diagonal(Node *root)
{
   // your code here
   
   vector<int>res;
   queue<Node*>q;
   
   solve(root,res,q);
   
   return res;
}

int main()
{
    
    return 0;
}