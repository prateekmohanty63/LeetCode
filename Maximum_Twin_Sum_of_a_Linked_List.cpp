/// Approach-1

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
    int pairSum(ListNode* head) {

        vector<int>vec1;
        int n=0;
        ListNode *temp=head;

        while(temp!=NULL){
            n++;
            vec1.push_back(temp->val);
            temp=temp->next;
        }

      n=n/2;
        cout<<n<<" ";

        int max=-1;

        for(int i=0;i<n;i++){
            int sum=0;
            sum+=vec1[i]+vec1[n*2-1-i];
            if(sum>max)
                max=sum;
        }

        return max;
    }
};

/// Approach-2

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
   ListNode  *reverse(ListNode *head)
    {
        ListNode *prev=NULL,*curr=head,*next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {

        ListNode *slow=head,*prevSlow=NULL,*fast=head;
        while(fast&&fast->next)
        {
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prevSlow->next=NULL;
        ListNode *mid=slow;
        ListNode *head2=reverse(mid);

        int  ans=0;
        ListNode *curr1=head,*curr2=head2;
        while(curr1&&curr2)
        {
            ans=max(ans,curr1->val+curr2->val);
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return ans;

    }
};
