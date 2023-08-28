
#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Display_recur_rev(struct Node *p)
{
    /// FIRST CALLING TAKES PLACE THEN PRINTING TAKES PLACE
    /// HENCE ARRAY IS PRINTED IN REVERSE ORDER;
    if(p!=NULL)
    {
        Display_recur(p->next);
        printf("%d ",p->data);
    }
    printf("\n");
}

void Display_recur(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Display_recur(p->next);
    }
    printf("\n");
}


/// Length of linked list
int length(struct Node *p)
{
    int count=0;
    while(p!=0)
    {
        count++;
        p=p->next;
    }
    return count;
}

int recr_length(struct Node *p)
{
    int count=0;
    if(p!=0)
    {
        count=recr_length(p->next);
        return count+1;
    }
    return count;
}

int sum(struct Node *p)
{
    int count=0;

    while(p!=0)
    {
        count+=p->data;
        p=p->next;
    }
    return count;
}

int count=0;
int recur_sum(struct Node *p)
{

    if(p!=0)
    {
        count+=p->data;
        recur_sum(p->next);
        /*count=recur_sum(p->next)+p->data;*/
    }
    return count;
}

int max(struct Node *p)
{
    int min=-1;
    while(p!=0)
    {
        if(p->data>min)
            min=p->data;
        p=p->next;
    }
    return min;
}

int max_ter(struct Node *p)
{
    int x=0;
    if(p==0)
    return -1;
    x=max(p->next);
    return x>p->data?x:p->data;
}


///Searching in linked list
/// We cannot directly access any index in linked list
/// Hence binary search is not posssible

int search(struct Node *p,int a)
{
    int r=length(first);


     for(int i=0;i<r;i++)
     {

        if(p->data==a)
        {
            return i;
        }

         p=p->next;
    }
    return -1;
}

struct Node * search_imv(struct Node *p,int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
    return q;
}

/// Inserting into a linked list

void insert(struct Node *p,int pos,int value)
{
    struct Node *t;
     if(pos<0 || pos>length(p))
        return ;

     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=value;

     if(pos==1)
     {
         t->next=first;
         first=t;
     }

     else if(pos>1)
     {
         t->next=first;
         for(int i=0;i<pos-1;i++)
         {
             p=p->next;
         }
         t->next=p->next;
         p->next=t;
     }
}


/// deleting

/// deleting the first element in linked list

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1;

    if(index<1 || index>5)
        return -1;

    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}

int check_sort(struct Node *p)
{
    int min=-32786;

    while(p!=NULL)
    {
        if(p->data<min)
            return -1;

            min=p->data;
            p=p->next;
    }
    return 1;

}

void remove_duplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void rev_ele(struct Node *p)
{
    int a=length(first);
    struct Node *q;
    q=p;
    int *arr=(int *)malloc(sizeof(int)*a);
    int i=0;

    while(p!=NULL)
    {
        arr[i]=p->data;
        p=p->next;
        i++;
    }

    i--;
    while(q!=NULL)
    {
        q->data=arr[i];
        i--;
        q=q->next;
    }


}

static void reverse(struct Node **head){
  struct Node *prev=NULL;
  struct Node *current=*head;
  struct Node *next=NULL;

  while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;

    current=next;

  }
  *head = prev;
}

int res_index[100];
int ele[100];
int k=0;
int m=0;
//void even(struct Node *p){
  // struct Node *temp=p;

   //while(temp!=NULL){

     //if(temp->data%2!=0){
       // while(temp->next->data%2==0)
        //{
          //  temp=temp->next;
            //ele[m++]=temp->data;
        //}
     //}
     //else if(temp->data%2==0){
       // res_index[k-1];
        //ele[m++]=temp->data;
     //}
     //temp=temp->next;
   //}
   //printf("(");
  //for(int i=0;i<sizeof(res_index)/sizeof(res_index[0])-1;i++){
    //if(res_index[i+1]-res_index[i+1]==1){
      //  printf("%d,",ele[i]);
    //}
    //else{
      //      printf(")");
        //i++;
    //}
  //}
//}

//void reverse(struct Node *p)
//{

  //  struct Node *temp=p;
    //struct Node *current=p;
    //struct Node *prev=NULL;

    //while(current!=NULL){

    //}
//}


int index[100];
void sublist(struct Node *p,int start,int end)
{
    struct Node *temp=p;
   struct Node *prev=NULL;
   struct Node *current=p;
   struct Node *next=NULL;
    int k=0;
    int m=0;
    while(k!=start+1){
        prev=current;
        current=current->next;
        next=current->next;
        k++;
        }
         m=k;
        while(m!=end+1){
        current->next=prev;
        prev=current;
        current=next;
        m++;
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

}

int main()
{
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
   // int C[]={1,1,1,2,2,3,4,5};
   int c[100];

   for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
   }
    create(c,n);
    //Display(first);
   // Display(first);

    struct Node *temp=first;

    int res[n][n];
    int k=0;
    int i=0;
   // while(temp!=NULL){
     //   if(temp->data%2==0){
       //    printf("%d ",temp->data);
         //  res[i][k++]=temp->data;
        //}
        //else if(temp->data%2!=0)
        //{
           // i++;
            //while(temp->next->data%2!=0)
              //  temp=temp->next;
        //}
        //printf("\n");
        //temp=temp->next;

    //}

    //reverse(&first);
    //printf("\n");

    //printf("Displaying the list after reversing the linked list we get: \n");
    //Display(first);

    //even(first);

   // for(int j=0;j<i;j++){
     //   for(int l=0;l<sizeof(res[j])/sizeof(int);l++)
       //     printf("%d ",res[j][l]);
    //}


sublist(first,1,2);
//Display(first);


    return 0;
}
