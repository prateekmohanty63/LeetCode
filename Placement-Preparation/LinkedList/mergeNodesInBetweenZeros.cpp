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

// T(N)=O(N)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* res=new ListNode();
        ListNode* head1=res;

        ListNode* temp=head;
        int sum=0;

        while(temp!=NULL)
        {
            if(temp->next!=NULL && temp->next->val==0)
            {
                sum+=temp->val;
                ListNode* currNode=new ListNode(sum);
                res->next=currNode;
                res=res->next;
                sum=0;
            }
            else
            sum+=temp->val;

            temp=temp->next;
        }
        return head1->next;
    }
};

int main()
{
    
    return 0;
}