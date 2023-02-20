#include<iostream>
#include<vector>
using namespace std;


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
   
   int sum(TreeNode *root,int num)
   {
      // base case

      if(!root)return 0;
       
       num=num*10+root->val;

      if(!root->left && !root->right)
      {
         
          return  num;
      }
    
      return sum(root->left,num)+sum(root->right,num);

      
   }
    
    int sumNumbers(TreeNode* root) {
        
       
        int res=0;

        

       res=sum(root,0);


        return res;
    }
};


class Solution {
public:
   
   void sum(TreeNode *root,vector<string>&nums,string str)
   {
      // base case

      if(!root)return ;

      if(!root->left && !root->right)
      {
          str+=to_string(root->val);
          nums.push_back(str);
      }
     
      sum(root->left,nums,str+to_string(root->val));
      sum(root->right,nums,str+to_string(root->val));
   }
    
    int sumNumbers(TreeNode* root) {
        
        vector<string>nums;
        int res=0;

        string str="";

        sum(root,nums,str);

        for(auto it:nums)
        {
            cout<<it<<" ";
            res+=stoi(it);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}