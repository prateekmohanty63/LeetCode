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
    bool isPalindrome(ListNode* head) {
        
        vector<int>vec;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int start=0;
        int end=vec.size()-1;

        while(start<=end)
        {
            if(vec[start]!=vec[end])return false;

            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}