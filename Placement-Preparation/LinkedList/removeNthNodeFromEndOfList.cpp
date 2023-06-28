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
 

 // T(N)=O(n)
 // S(n)=O(1)
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head)return NULL;
        if(head && !head->next)return NULL;

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* fast=dummy;
        ListNode* slow=dummy;

        while(fast!=NULL && n!=0)
        {
            fast=fast->next;
            n--;
        }

        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;

        return dummy->next;
    }
};

int main()
{
    
    return 0;
}