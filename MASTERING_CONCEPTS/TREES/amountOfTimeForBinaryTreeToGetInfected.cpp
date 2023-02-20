#include<iostream>
using namespace std;





 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
     
     int distance(TreeNode *root,int x)
     {
         // base case

        // Base case
    if (root == NULL)
      return -1;
 
    // Initialize distance
    int dist = -1;
 
    // Check if x is present at root or in left
    // subtree or right subtree.
    if ((root->val == x) ||
        (dist = distance(root->left, x)) >= 0 ||
        (dist = distance(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;
     }

     int rootMaxDepth(TreeNode *root)
     {
         if(!root)return 0;

         return max(1+rootMaxDepth(root->left),1+rootMaxDepth(root->right));
     }

     int heightOfTree(TreeNode *root)
     {
         if(!root)return 0;

         int left=heightOfTree(root->left);
         int right=heightOfTree(root->right);

         if(left>right)return 1+left;

         else return 1+right;
     }
    
    bool isPresent(TreeNode *root,int target)
    {
        if(!root)return false;

        if(root->val==target)return true;

        return isPresent(root->left,target) || isPresent(root->right,target);
    }
    

    int amountOfTime(TreeNode* root, int start) {
        
        if(!root->right && !root->left)return 0;

        // distance of root from infected node
      int rootDistance=distance(root,start);
    
     // cout<<rootDistance<<" "<<endl;

      if(isPresent(root->left,start))
      {
          cout<<"Present at the left position"<<endl;

          int maxRightDepth;
          int maxLeftDepth;

         if(root->right){
          maxRightDepth=rootMaxDepth(root->right);
          maxLeftDepth=rootMaxDepth(root->left);
          return max(maxRightDepth+rootDistance,maxLeftDepth-(rootDistance));
         }

          else {
              maxRightDepth=rootMaxDepth(root->left);
              cout<<rootDistance<<" "<<maxRightDepth;
             
             return max(rootDistance,maxRightDepth-(rootDistance));
              
          }

          //cout<<maxRightDepth;

          
      }
      else if(isPresent(root->right,start))
      {
          cout<<"Present at right position"<<endl;

          int maxLeftDepth;
          int maxRightDepth;

          if(root->left){
          maxLeftDepth=rootMaxDepth(root->left);
          maxRightDepth=rootMaxDepth(root->right);
            return max(maxLeftDepth+rootDistance,maxRightDepth-rootDistance);
          }
          
          else{

          maxLeftDepth=rootMaxDepth(root->right);
              cout<<rootDistance<<" "<<maxLeftDepth;
             
             return max(rootDistance,maxLeftDepth-(rootDistance));
              
          }
      }
      else{
          cout<<rootDistance;
          return heightOfTree(root)-1;
      }
      
        
    }
};

int main()
{
    
    return 0;
}