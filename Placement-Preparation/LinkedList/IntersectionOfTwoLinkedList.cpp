#include<iostream>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;

       if(headA==NULL || headB==NULL)return NULL;

       while(temp1!=temp2)
       {
           temp1=temp1==NULL? headB:temp1->next;
           temp2=temp2==NULL ? headA:temp2->next;
       }

     return temp1;
    }
};

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        int len1=0;
        int len2=0;

        while(temp1!=NULL)
        {
            len1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            len2++;
            temp2=temp2->next;
        }
        int diff=abs(len1-len2);
        
        temp1=headA;
        temp2=headB;

        if(len1>len2){
            while(diff!=0)
            {
                temp1=temp1->next;
                diff--;
            }
        }
        else{
            while(diff!=0)
            {
                temp2=temp2->next;
                diff--;
            }
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2)return temp1;

            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};

int main()
{
    
    return 0;
}