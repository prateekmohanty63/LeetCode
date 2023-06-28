#include<iostream>
#include<vector>
using namespace std;


// T(N)=O(N)
// S(N)=O(1)
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)return NULL;

        if(head->next==NULL)return head;

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
};


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 // T(N)=O(N)
 // S(N)=O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        vector<int>vec;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int k=vec.size()-1;

      temp=head;

      while(temp!=NULL)
      {
          temp->val=vec[k--];
          temp=temp->next;
      }
      return head;
    }
};

int main()
{
    
    return 0;
}