#include<iostream>
using namespace std;


// T(N)=O(n+m)
// S(n)=O(n+m)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy=new ListNode(-1);
        ListNode* res=dummy;
        int carry=0;

        while(l1!=NULL && l2!=NULL)
        {
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            dummy->next=new ListNode(sum%10);
            dummy=dummy->next;

            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL)
        {
            int sum=l1->val+carry;
            carry=sum/10;
            dummy->next=new ListNode(sum%10);
            dummy=dummy->next;

            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=l2->val+carry;
            carry=sum/10;
            dummy->next=new ListNode(sum%10);
            dummy=dummy->next;

            l2=l2->next;
        }
      
      if(carry!=0)dummy->next=new ListNode(carry);
        return res->next;
    }
};

int main()
{
    
    return 0;
}