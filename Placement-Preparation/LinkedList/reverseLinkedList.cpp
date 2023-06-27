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