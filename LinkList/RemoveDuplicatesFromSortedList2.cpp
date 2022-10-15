#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;


// Runtime: 44 ms, faster than 6.10% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 11.8 MB, less than 12.89% of C++ online submissions for Remove Duplicates from Sorted List II.

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // if no head return NULL
        
        if(!head)return NULL;
        
        // if only head return head
        
        if(!head->next)return head;
        
        // dummy node
        ListNode *dum=new ListNode(0);
        
          
        ListNode *first=dum;
        ListNode *second=head;
        ListNode *third=head;
        
        while(second!=NULL)
        {
            
                while(third!=NULL && second->val==third->val)
                {
                    third=third->next;
                }
           
            if(second->next==third)
            {
                first->next=second;
                first=first->next;
            }
            second=third;
        }
       
        first->next=NULL;
    return dum->next;
    }
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // if no head return NULL
        if(!head)return NULL;
        
        // if only 1 element return head
        if(!head->next)return head;
        
        
        
        
        ListNode *temp=head;
        
        map<int,int>freq;
        
        while(temp!=NULL)
        {
            freq[temp->val]++;
            temp=temp->next;
        }
        
        int flag=0;
        // if there are no unique values
        for(auto it:freq)
        {
            if(it.second==1)flag=1;
        }
        if(flag==0)return NULL;
        
        
        ListNode *res=head;
        
        temp=head;
        ListNode *prev=NULL;
        int k=0;
        
        for(auto it:freq)
        {
            cout<<it.first<<" "<<it.second<<endl;
            
            if(it.second==1)
            {
                temp->val=it.first;
                temp=temp->next;
                
                if(k==0)
                prev=head;
                else prev=prev->next;
                k=1;
            }
        }
        prev->next=NULL;
        
        return res;
    }
};

int main()
{
    
    return 0;
}