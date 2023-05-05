#include<iostream>
#include<vector>
#include<algorithm>
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
   
   void bst(TreeNode *root,vector<int>&vec)
   {
       // base case
       if(!root)return ;

       vec.push_back(root->val);

       bst(root->left,vec);
       bst(root->right,vec);
   }

   int binarySearch(vector<int>&vec,int target,int start,int end)
   {
       if(end>=start)
       {
           int mid=start+(end-start)/2;

           if(vec[mid]==target)
           {
               return mid;
           }
           else if(target>vec[mid])
           {
               return binarySearch(vec,target,mid+1,end);
           }
           else return binarySearch(vec,target,start,mid-1);
       }
       return -1;
   }

   void sumTree(TreeNode *root,vector<int>&vec,vector<int>&suffixSum)
   {
       // base case

       if(!root)return ;

       int index=binarySearch(vec,root->val,0,vec.size()-1);

       if(root->val!=vec[vec.size()-1] && suffixSum.size()-(index+2)>=0){
       cout<<index<<" "<<suffixSum[suffixSum.size()-(index+2)]<<endl;
       root->val+=suffixSum[suffixSum.size()-(index+2)];
       }

      // else cout<<suffixSum.size()-(index+2)<<endl;
       
      // if((suffixSum.size()-(index+2))>=0)
       //root->val+=suffixSum[suffixSum.size()-(index+2)];

       sumTree(root->left,vec,suffixSum);
       sumTree(root->right,vec,suffixSum);
   }

    TreeNode* bstToGst(TreeNode* root) {
        
        vector<int>vec;

        bst(root,vec);

        sort(vec.begin(),vec.end());

        vector<int>suffixSum;

        int sum=vec[vec.size()-1];
         suffixSum.push_back(sum);

        for(int i=1;i<vec.size();i++)
        {
            sum+=vec[vec.size()-1-i];
            suffixSum.push_back(sum);
        }
        
         for(auto it:vec)cout<<it<<" ";
         //cout<<endl;
        //for(auto it:suffixSum)cout<<it<<" ";
        cout<<endl;
        sumTree(root,vec,suffixSum);
      
        return root;
    }
};

int main()
{
    
    return 0;
}