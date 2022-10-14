#include<iostream>
#include<cmath>

using namespace std;

// using slow and fast pointers

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        
        if(!head || !head->next)return NULL;
        
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        ListNode* nxt=slow;
        
        int k=0;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            // move slow by 1
            slow=slow->next;
            
            if(k==0){
                nxt=head;
                k=1;
            }
            else{
                nxt=nxt->next;
            }
           
            
            // move fast by 2
            fast=fast->next->next;
        }
        cout<<slow->val<<" "<<nxt->val;
        
        nxt->next=slow->next;
        
        return head;
    }
};


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        
        if(!head)return NULL;
        
        if(!head->next)return NULL;
        
        int length=0;
        
        ListNode* temp=head;
        ListNode *nxt=head;
        
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        
      //  cout<<length;
        
        int middle=floor(length/2);
        
        int k=middle;
        
        temp=head;
        nxt=temp->next;
        
        while(k!=1 && temp!=NULL)
        {
            temp=temp->next;
            nxt=nxt->next;
            k--;
        }
        
        temp->next=nxt->next;
        cout<<temp->val<<" "<<nxt->val;
        
        return head;
    }
};