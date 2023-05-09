#include<iostream>
#include<vector>
#include<unordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        

      unordered_map<int,TreeNode*>mp;
      unordered_map<int,bool>chil;

        int n=descriptions.size();

        for(int i=0;i<n;i++)
        {
            int leftChild=descriptions[i][2];
            
            if(mp.find(descriptions[i][0])==mp.end())
            {
                TreeNode *parent=new TreeNode(descriptions[i][0]);
                // check if child is not found
                if(mp.find(descriptions[i][1])==mp.end())
                {
                    TreeNode *child=new TreeNode(descriptions[i][1]);
                    
                    if(leftChild==1)
                    {
                        parent->left=child;
                    }
                    else{
                          parent->right=child;
                    }
                    mp[descriptions[i][1]]=child;
                
                }
                else{
                    TreeNode *child=mp[descriptions[i][1]];

                      if(leftChild==1)
                    {
                        parent->left=child;
                    }
                    else{
                          parent->right=child;
                    }
                    mp[descriptions[i][1]]=child;
                }
                // update the parent and child 
                mp[descriptions[i][0]]=parent;
                
            }
            else{
                  TreeNode *parent=mp[descriptions[i][0]];

                   // check if child is not found
                if(mp.find(descriptions[i][1])==mp.end())
                {
                    TreeNode *child=new TreeNode(descriptions[i][1]);
                    
                    if(leftChild==1)
                    {
                        parent->left=child;
                    }
                    else{
                          parent->right=child;
                    }
                 mp[descriptions[i][1]]=child;
                }
                else{
                    TreeNode *child=mp[descriptions[i][1]];

                      if(leftChild==1)
                    {
                        parent->left=child;
                    }
                    else{
                          parent->right=child;
                    }
                     mp[descriptions[i][1]]=child;
                }
                mp[descriptions[i][0]]=parent;
            }
           
        }

        for(int i=0;i<descriptions.size();i++)
        { 
            chil[descriptions[i][1]]=true;
        }
        for(int i=0;i<descriptions.size();i++)
        { 
            if(chil.find(descriptions[i][0])==chil.end())return mp[descriptions[i][0]];
        }
        return NULL;
       
    }
     
};

int main()
{
    
    return 0;
}
