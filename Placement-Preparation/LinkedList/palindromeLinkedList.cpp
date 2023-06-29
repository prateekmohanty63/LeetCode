#include<iostream>
#include<vector>
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
// S(N)=O(1)

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head)
    {
        if(head==NULL)return NULL;
        if(head && head->next==NULL)return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head->next;

        while(nxt!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        curr->next=prev;

        return curr;
    }
    bool isPalindrome(ListNode* head) {

        if(head==NULL)return true;

        if(head!=NULL && head->next==NULL)return true;
        
        ListNode* head1=head;
        ListNode* slow=head;
        ListNode* fast=head;
       

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* head2=reverseLinkedList(slow);

        ListNode* temp2=head2;
        ListNode* temp1=head1;

        // while(temp2!=NULL)
        // {
        //     cout<<temp2->val<<" ";
        //     temp2=temp2->next;
        // }

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val!=temp2->val)return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return true;
    }
};


 

 // T(N)=O(N)
 // S(N)=O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int>vec;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int start=0;
        int end=vec.size()-1;

        while(start<=end)
        {
            if(vec[start]!=vec[end])return false;

            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}