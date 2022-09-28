#include<iostream>
using namespace std;



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        if(head->next==NULL || !head)return NULL;
        
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *nxt=head->next;
        
        ListNode *temp=head;
        
        int length=0;
        
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        
        int target=length-n;
        
        if(target==0)return head->next;
        
        
        while(target>0)
        {
            prev=curr;
            curr=curr->next;
            
        
            nxt=nxt->next;
            
            target--;
        }
        
        
        
        
        //cout<<prev->val<<" "<<curr->val<<" "<<nxt->val;
        
        
       prev->next=nxt;
        
        return head;
    }
};

int main()
{
    
    return 0;
}