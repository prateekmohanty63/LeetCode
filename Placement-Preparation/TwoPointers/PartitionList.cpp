#include<iostream>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// 1 pass

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *small=new ListNode(-1);
        ListNode *big=new ListNode(-1);
        ListNode *small_head=small;
        ListNode *big_head=big;

        ListNode *temp=head;

        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                  small->next=temp;
                  small=small->next;
                   temp=temp->next;
                  small->next=NULL;
            }
            else{
                 big->next=temp;
                 big=big->next;
                  temp=temp->next;
                 big->next=NULL;
            }
           

        }
      
       small->next=big_head->next;

        return small_head->next;
    }
};



//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *temp=head;

        if(!head)return head;

         ListNode *head1=new ListNode();
         ListNode *res=head1;

         while(temp!=NULL)
         {
             if(temp->val<x)
             {
                 head1->val=temp->val;
                 head1->next=new ListNode();
                 head1=head1->next;
             }
             temp=temp->next;
         }
         temp=head;

         while(temp!=NULL)
         {
             if(temp->val>=x)
             {
                 head1->val=temp->val;
                 head1->next=new ListNode();
                 head1=head1->next;
             }
             temp=temp->next;
         }
        temp=res;
        while(temp->next->next!=NULL)temp=temp->next;
        temp->next=NULL;
        
        //  while(res!=NULL)
        //  {
        //      cout<<res->val<<" ";
        //      res=res->next;
        //  }
         return res;
    }
};

int main()
{
    
    return 0;
}