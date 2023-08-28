
/**
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

    void Inorder(struct TreeNode *p)
    {
        if(p){
        Inorder(p->left);
        vec1.push_back(p->val);
        Inorder(p->right);
        }
    }
public:
    bool isSymmetric(TreeNode* root) {

        Inorder(root);
       /* for(int i=0;i<vec1.size();i++)
            cout<<vec1[i]<<" ";*/
        int vecs=vec1.size();
        vector<int>fvec;
        vector<int>lvec;

        for(int i=0;i<vecs/2;i++)
            fvec.push_back(vec1[i]);
        for(int i=vec1.size()-1;i>vecs/2;i--)
           lvec.push_back(vec1[i]);
       // cout<<endl;

        for(int i=0;i<vec1.size();i++)
            cout<<vec1[i]<<" ";
        cout<<endl;

        for(int i=0;i<fvec.size();i++)
            cout<<fvec[i]<<" ";
        cout<<endl;
        for(int i=0;i<lvec.size();i++)
            cout<<lvec[i]<<" ";

        if(fvec==lvec)
        return true;
        return false;
    }
};
