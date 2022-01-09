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

/// First approach

///Runtime: 7 ms, faster than 30.35% of C++ online submissions for Remove Nth Node From End of List.
///Memory Usage: 10.8 MB, less than 31.72% of C++ online submissions for Remove Nth Node From End of List.


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int a=0;

        if(n==1 && head->next==NULL)
            return NULL;

        ListNode *temp=head;

        while(temp!=NULL){
            a++;
            temp=temp->next;
        }

        int b=a-n;

        if(b==0){
            head=head->next;
        }

        ListNode *temp1=head;
        ListNode *temp2=temp1;

        while(b--){
            temp2=temp1;
            temp1=temp1->next;
        }

        cout<<temp2->val<<" "<<temp1->val;
        temp2->next=temp1->next;

        return head;
    }
};

/// 2nd approach


