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

   ListNode* rotateR(ListNode *head,int k)
   {
       
       ListNode *temp=head;
       vector<int>vec,vec1;

       while(temp!=NULL)
       {
           vec.push_back(temp->val);
           temp=temp->next;
           
       }

       int n=vec.size();
       
       for(int i=n-k;i<n;i++)
       {
           vec1.push_back(vec[i]);
       }

       for(int i=0;i<n-k;i++)
       {
           vec1.push_back(vec[i]);
       }
     

       ListNode *temp1=head;

       int l=0;

       while(temp1!=NULL)
       {
           temp1->val=vec1[l++];
           temp1=temp1->next;
       }

       return head;
   } 
  
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL)return head;
        int len=0;

        ListNode *temp=head;

        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
          k=k%len;
      
        ListNode *res=rotateR(head,k);

        return res;
    }
}; 



class Solution {
public:

   vector<int> rotateR(ListNode *head)
   {
       ListNode *temp=head;
       
       vector<int>vec;

       while(temp!=NULL)
       {
           vec.push_back(temp->val);
           temp=temp->next;
       }
       int val=vec[vec.size()-1];
       vec.insert(vec.begin()+0,val);

       vec.pop_back();

       return vec;
   } 
  
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL)return head;
        int len=0;

        ListNode *temp=head;

        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
        k=k%len;
       while(k!=0)
       {
           vector<int>vec=rotateR(head);
           ListNode *temp=head;
            int l=0;
           while(temp!=NULL)
           {
               temp->val=vec[l++];
               temp=temp->next;
           }
           k--;
       }

        return head;
    }
};

int main()
{
    
    return 0;
}