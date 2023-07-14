#include<iostream>
using namespace std;



 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

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
    ListNode* findMid(ListNode* head)
    {
        // finding the Mid of the linked list
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* makeList(ListNode* head,ListNode* mid)
    {
        ListNode* res=head;
        ListNode* temp=head;


        while(temp!=NULL && temp->next!=mid)temp=temp->next;
        
       // if(temp!=NULL)
        temp->next=NULL;

        return res;
    }

    TreeNode* buildTree(ListNode* head)
    {
        // base case
        if(head==NULL )return NULL;
        if(head->next==NULL)
        {
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* temp=head;
       
        ListNode* mid=findMid(head);
        TreeNode* root=new TreeNode(mid->val);

        ListNode* leftPart=makeList(head,mid);
        ListNode* rightPart=mid->next;
      
        root->left=buildTree(leftPart);
        root->right=buildTree(rightPart);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        TreeNode* res=buildTree(head);

        return res;
    }
};

int main()
{
    
    return 0;
}