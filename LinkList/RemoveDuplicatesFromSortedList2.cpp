#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;




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