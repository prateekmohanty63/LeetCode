#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// Time complexity: O(N^2)
// space complexity: O(1)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        ListNode *temp=head;
       

        while(temp!=NULL && temp->next!=NULL)
        {
          ListNode *temp1=temp->next;

          while(temp1!=NULL)
          {
              if(temp->val>temp1->val)
              {
                  int tp=temp->val;
                  temp->val=temp1->val;
                  temp1->val=tp;
              }
              temp1=temp1->next;
          }
          temp=temp->next;
        }
        return head;
    }
};


// Time complexity: O(nlogn)
// Space complexity: O(n)

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        vector<int>vec;

        ListNode *temp=head;

        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }

        sort(vec.begin(),vec.end());

        ListNode *temp1=head;
        int k=0;

        while(temp1!=NULL)
        {
            temp1->val=vec[k++];
            temp1=temp1->next;
        }
        return head;
    }
};

int main()
{
    
    return 0;
}