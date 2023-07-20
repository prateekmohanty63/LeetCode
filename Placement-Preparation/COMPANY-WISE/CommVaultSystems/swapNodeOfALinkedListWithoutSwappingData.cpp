#include<iostream>
using namespace std;

class Node{

    public:
    int data;
     Node *next;

    Node(int val)
    {
        data=val;
    }
};

Node *head=NULL;

void addNodeEnd(int data)
{
    // new node

    Node *newNode=new Node(data);

    if(head==NULL)
    {
        head=newNode;
        newNode->next=NULL;

        return ;
    }

     Node *temp=head;

     while(temp->next!=NULL)
     {
         temp=temp->next;
     }

     temp->next=newNode;
     newNode->next=NULL;
}

void insertAtPos(int data,int pos)
{
    Node *temp=head;
    Node *newNode=new Node(data);


    while(temp->next!=NULL && pos!=1)
    {
       temp=temp->next;
       pos--;
    }


    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteNode(int pos)
{
    Node *temp=head;
    Node *nxt=temp->next;

    while(pos!=1)
    {
        temp=temp->next;
        nxt=nxt->next;
        pos--;
    }

    temp->next=nxt->next;
}

void printList(Node *head)
{
    Node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node *swapNode(Node* head,int data1,int data2)
{
    Node* res=head;

    Node* ptr1=head;
    Node* prev1=head;
    Node* next1=head->next;

    Node* ptr2=head;
    Node* prev2=head;
    Node* next2=head->next;

    int k=0;

    while(ptr1!=NULL && ptr1->data!=data1)
    {
        ptr1=ptr1->next;

        if(k!=0)
        prev1=prev1->next;

        if(next1!=NULL)next1=next1->next;

        k=1;
    }
    k=0;
    while(ptr2!=NULL && ptr2->data!=data2)
    {
        

        ptr2=ptr2->next;

        if(k!=0)
        prev2=prev2->next;

        if(next2!=NULL)next2=next2->next;

        k=1;
    }

    cout<<prev1->data<<" "<<ptr1->data<<" "<<next1->data;
    cout<<endl;

    cout<<prev2->data<<" "<<ptr2->data<<" "<<next2->data;

    // move node1 to next of node2
    ptr1->next=next2;

    prev2->next=NULL;
    ptr2->next=next1;

    prev2->next=ptr1;

    prev1->next=ptr2;

    return res;
}

int main()
{
    addNodeEnd(10);
    addNodeEnd(15);
    addNodeEnd(12);
    addNodeEnd(13);
    addNodeEnd(20);
    addNodeEnd(14);
   

    printList(head);
    cout<<endl;

     Node* res=swapNode(head,12,20);
    cout<<endl;
    // cout<<res->data;

    while(res!=NULL)
    {
        cout<<res->data<<" ";
        res=res->next;
    }

   
    
    return 0;
}