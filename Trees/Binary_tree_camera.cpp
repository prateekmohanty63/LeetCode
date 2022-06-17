#include<iostream>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

//  Runtime: 8 ms, faster than 90.78% of C++ online submissions for Binary Tree Cameras.
// Memory Usage: 21.2 MB, less than 87.57% of C++ online submissions for Binary Tree Cameras.

class Solution {
public:
    #define HAS_CAMERA 2
    #define NO_CAMERA 0
    #define NOT_NEEDED 1
    
    int dfs(TreeNode *root,int &res)
    {
        
        if(!root)return NOT_NEEDED;
        
        int l=dfs(root->left,res);
        int r=dfs(root->right,res);
        
        // if any of the child is not covered , the parent needs to put 1 camera
        if(l==0 || r==0){
            
            res++;
            return HAS_CAMERA;
            
        }
        
        // if any 1 of the child has camera, then parent is already convered and doesnt need camera
       if(l==HAS_CAMERA || r==HAS_CAMERA)
       {
           return NOT_NEEDED;
       }
        
        // children dont have camera but thet are covered by their children
        else{
            return NO_CAMERA;
        }
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        
        
        // case when only there is 1 node including root
        if(root->left && !root->right && !root->left->left && !root->left->right)return 1;
        
        if(root->right && !root->left && !root->right->left && !root->right->right)return 1;
        
        int res=0;
        
       if(dfs(root,res) == NO_CAMERA) res++;
        
        return res;
    }
};

int main()
{
    
    return 0;
}