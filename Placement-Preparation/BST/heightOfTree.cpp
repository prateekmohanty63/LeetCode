#include<iostream>
using namespace std;

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

class Solution{
    public:
    //Function to find the height of a binary tree.
    
    int heightOfTree(struct Node *node)
    {
        if(node==NULL)return 0;
        
        int leftDist=heightOfTree(node->left);
        int rightDist=heightOfTree(node->right);
        
        if(leftDist>rightDist)return 1+leftDist;
        
        else
        return 1+rightDist;
    }
    
    int height(struct Node* node){
        // code here 
        
        int res=heightOfTree(node);
        
        return res;
    }
};

int main()
{
    
    return 0;
}