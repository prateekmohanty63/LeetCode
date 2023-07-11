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


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
 void solve(Node* root,int level,vector<int>&res)
 {
     // base case
     if(!root)return ;
     
     if(res.size()==level)res.push_back(root->data);
     
     solve(root->right,level+1,res);
     solve(root->left,level+1,res);
     
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>res;
   
   solve(root,0,res);
   
   return res;
}


int main()
{
    
    return 0;
}