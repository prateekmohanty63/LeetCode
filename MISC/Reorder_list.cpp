
/// 1st Approach

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

 /// Runtime: 49 ms, faster than 20.83% of C++ online submissions for Reorder List.
 ///  Memory Usage: 18.3 MB, less than 39.51% of C++ online submissions for Reorder List.



 /// NOTE THE QUESTION HAS TOLD NOT TO CHANGE THE VALUE OF THE NODE RATHER WE SHOULD CHANGE THE NODE
 /// STILL THIS IS CAN BE ONE APPROACH

class Solution {
public:
    void reorderList(ListNode* head) {

        if(head->next==NULL)
            return ;

        vector<int>vec1;

        ListNode *temp=head;

        while(temp!=NULL){
            vec1.push_back(temp->val);
            temp=temp->next;
        }

       ListNode *temp1=head;
       int n=vec1.size();
        if(n&1){
            for(int i=0;i<n/2;i++){
                int a=vec1[i];
                int b=vec1[n-i-1];

                temp1->val=a;
                temp1=temp1->next;
                temp1-> val=b;
                temp1=temp1->next;
            }

          ListNode *temp1=head;

        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
            temp1->val=vec1[n/2];
        }
        else{
            for(int i=0;i<n/2;i++){
                int a=vec1[i];
                int b=vec1[n-i-1];

                temp1->val=a;
                temp1=temp1->next;
                temp1-> val=b;
                temp1=temp1->next;
            }


        }
    }
};


/// 2ND APPROACH



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

 /// First we will break the list into two parts
 /// then reverse the second part
 /// then merge the first part and the reversed second part


 /// Runtime: 28 ms, faster than 99.23% of C++ online submissions for Reorder List.
 /// Memory Usage: 17.8 MB, less than 75.25% of C++ online submissions for Reorder List.

class Solution {

    ListNode * reverse(ListNode *head){

        ListNode *prev=NULL;
        ListNode *temp=head;

        while(temp!=NULL){
            ListNode *temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        return prev;
    }

    void mergeList(ListNode *head1,ListNode *head2)
    {
         ListNode *temp1=head1;
        ListNode *temp2=head2;
        if(head1){
        while(temp1!=NULL || temp2!=NULL){
            ListNode *temp3=temp1->next;
            ListNode *temp4=temp2->next;

            temp1->next=temp2;

            if(temp1->next==NULL)
                break;

            temp2->next=temp3;
            temp2=temp4;
            temp1=temp3;
            temp1=temp1->next;
            temp2=temp2->next;

        }

        }

        if(temp2!=NULL){
            temp1->next=temp2;
        }


    }
public:
    void reorderList(ListNode* head) {

        if(head->next==NULL)
            return ;

        ListNode *first_head=head;   /// head of first part of the list
        ListNode *slow=head;         /// head of second part of list
        ListNode *fast=head;
        ListNode *prev=NULL;

        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        /// prev last node of 2nd node
        prev->next=NULL;

        ListNode *prev1=NULL;
        ListNode *temp=slow;
        ListNode *temp1=slow->next;

        ListNode *head2= reverse(slow);
        mergeList(first_head,head2);

    }
};
