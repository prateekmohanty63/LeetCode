//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
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

// T(N)=O(N)
// S(N)=O(H)

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       
       // base case
       if(!root)return NULL;
       
       if(root->data==n1 || root->data==n2)return root;
       
       Node* leftAns=lca(root->left,n1,n2);
       Node* rightAns=lca(root->right,n1,n2);
       
       if(leftAns!=NULL && rightAns!=NULL)return root;
       
       if(leftAns!=NULL)return leftAns;
       
       if(rightAns!=NULL)return rightAns;
       
       return leftAns;
       
    }
};


// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends