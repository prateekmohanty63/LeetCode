**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int>vec1;
    void Postorder(struct TreeNode *p)
    {
        if(p){
        Postorder(p->left);
        Postorder(p->right);

        vec1.push_back(p->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {

        Postorder(root);
      return vec1;
    }
};
