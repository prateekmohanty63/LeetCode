#include<iostream>
#include<cmath>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 // causing integer overflow problems

class Solution {
public:
 
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        
        // length of list-1
        int length1=0;
        long number1=0;
        
        ListNode *temp=l1;
        
        ListNode *p=new ListNode(0);
        ListNode *head=p;
        
        while(temp!=NULL)
        {
            length1++;
            temp=temp->next;
        }
        
        temp=l1;
        int i=0;
        
        while(temp!=NULL)
        {
            int digit=temp->val;
            number1+=digit*pow(10,length1-i-1);
            i++;
            temp=temp->next;
        }
        //cout<<number1;
        
        int length2=0;
        long number2=0;
        
        temp=l2;
        
        while(temp!=NULL)
        {
            length2++;
            temp=temp->next;
        }
        
        temp=l2;
        i=0;
        
        while(temp!=NULL)
        {
            int digit=temp->val;
            number2+=digit*pow(10,length2-i-1);
            i++;
            temp=temp->next;
        }
        
        //cout<<" "<<number2;
        
        int res=number1+number2;
        
     cout<<res<<" ";
        
        int length3=0;
        
        int temp1=res;
        
        while(temp1>0)
        {
            length3++;
            temp1/=10;
        }
        if(length3==0)length3=1;
        
        temp=l1;
       
      
        
        string a=to_string(res);
        cout<<a;
        
       // temp1=rev;
        
        
        // building a linked list of length length3
        temp=p;
        length3--;
        while(length3--)
        {
            ListNode* node=new ListNode(0);
            temp->next=node;
            temp=temp->next;
        }
        
        
        p=head;
        cout<<" ";
        
        for(int i=0;i<a.length();i++)
        {
            
            int digit=a[i]-'0';
            cout<<digit<<" ";
            // p->val=digit;
            // p=p->next;
        }
        
        // while(temp1!=0)
        // {
        //     int digit=temp1%10;
        //     p->val=digit;
        //     temp1/=10;
        //     p=p->next;
        //     length3--;
        // }
        
       // cout<<length3;
        
       
      
       
        
        return head;
    }
};

int main()
{
    
    return 0;
}