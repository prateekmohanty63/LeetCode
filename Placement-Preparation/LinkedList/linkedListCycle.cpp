#include<iostream>
#include<unordered_map>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* ,bool>mp;

        ListNode* temp1=head;

        while(temp1!=NULL)
        {
            if(mp.find(temp1)!=mp.end())return true;

            mp[temp1]=true;
            temp1=temp1->next;
        }

        return false;
    }
};

int main()
{
    
    return 0;
}