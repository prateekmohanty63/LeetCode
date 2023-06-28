#include<iostream>
using namespace std;


// T(N)=O(n+m)
// S(n)=O(1)

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
        
        ListNode* l1=NULL;
        ListNode* l2=NULL;
        ListNode* nxt=NULL;
        ListNode* res=NULL;
        
        if(!list1)return list2;

        if(!list2)return list1;

        if(list1->val<=list2->val)
        {
            l1=list1;
            l2=list2;
            nxt=l1->next;
            
        }
        else{
            l1=list2;
            l2=list1;
            nxt=l1->next;
        }
        res=l1;
     //  cout<<l1->val<<" "<<nxt->val<<endl;
        while(nxt!=NULL)
        {
            
            if(nxt->val<=l2->val)
            {
                l1=l1->next;
                nxt=nxt->next;
            }
            else{
                l1->next=l2;
                l1=l2;
                l2=nxt;
                nxt=l1->next;
            }
        }
        l1->next=l2;

        return res;
    }
};


// T(N)=O(n+m)
// S(N)=O(n+m)

 
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