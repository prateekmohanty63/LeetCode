#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

// T(N)=O(N^2)
// S(N)=O(H)

class Solution
{
    public:
    
    int subTreeSum(Node* root)
    {
        // base case
        if(!root)return 0;
        
        return root->data+subTreeSum(root->left)+subTreeSum(root->right);
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(!root)return true;
         
         if(!root->left && !root->right)return true;
         
         bool left=isSumTree(root->left);
         bool right=isSumTree(root->right);
         
         bool isEqual=(subTreeSum(root->left)+subTreeSum(root->right)==root->data);
         
         return left && right && isEqual;
    }
};

int main()
{
    
    return 0;
}