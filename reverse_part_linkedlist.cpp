
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        vector<int>vec1;
        struct ListNode *start=head;
        struct ListNode *end=head;

        int k=0;
        while(k!=left-1){
            start=start->next;
            end=end->next;
            k++;
        }
        while(k!=right-1){
            end=end->next;
            k++;
        }
       // cout<<start->val<<" "<<end->val;

        struct ListNode *temp=start;
        //vec1.push_back(temp->val);

        while(temp!=end->next){
            vec1.push_back(temp->val);
            temp=temp->next;
        }

        // for(int i=0;i<vec1.size();i++)
        //     cout<<vec1[i]<<" ";
         reverse(vec1.begin(), vec1.end());
        for(int i=0;i<vec1.size();i++)
            cout<<vec1[i]<<" ";

        temp=head;
        int i=0;
        int r=0;
        while(temp!=NULL){
            if(i>=left-1 && i<=right-1){
                temp->val=vec1[r++];
            }
            i++;
            temp=temp->next;
        }

        return head;
    }
};
