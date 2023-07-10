#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

 

// T(N)=O(n)
// S(N)=O(h)
pair<bool,int> isSumTreeFast(Node* root)
    {
        // base case
        if(!root)return {true,0};
        
        if(!root->left && !root->right)return {true,root->data};
        
        pair<bool,int>left=isSumTreeFast(root->left);
        pair<bool,int>right=isSumTreeFast(root->right);
        
        // checking the condition in the current node
        bool isSame=(left.second+right.second==root->data);
        pair<bool,int>ans;
        ans.first=(isSame && left.first && right.first);
        ans.second=left.second+right.second+root->data;
        return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
        return isSumTreeFast(root).first;
    }



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