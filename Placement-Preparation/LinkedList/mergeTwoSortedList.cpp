#include<iostream>
using namespace std;


// T(N)=O(N+M)
// S(N)=O(1)

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp1=list1;
        ListNode* temp2=list2;

        ListNode* dummy =new ListNode(-1);
        ListNode* res=dummy;

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                dummy->next=temp1;
                temp1=temp1->next;
            }
            else{
                dummy->next=temp2;
                temp2=temp2->next;
            }
            dummy=dummy->next;
        }
        while(temp1!=NULL)
        {
            dummy->next=temp1;
            temp1=temp1->next;
            dummy=dummy->next;
        }
        while(temp2!=NULL)
        {
            dummy->next=temp2;
            temp2=temp2->next;
            dummy=dummy->next;
        }
        return res->next;
    }
};

int main()
{
    
    return 0;
}