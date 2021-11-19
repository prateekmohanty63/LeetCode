
#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
char data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, char val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%c\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%c\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%c\n",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}


node* search(node ** tree, char val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void findpresuc(node *tree,node *pre,node *succ){
     node *temp1=tree,*temp2=tree;

     /// inorder predessor
     if(tree->left==NULL)
        pre=NULL;
     else if(tree->left!=NULL){
        node *temp1=tree->left;
        while(temp1->right!=NULL){
            temp1=temp1->right;
        }
        pre=temp1;
     }
     /// inorder successor
     if(tree->right==NULL)
        succ=NULL;
     else if(tree->right!=NULL){
        node *temp2=tree->right;
        while(temp2->left!=NULL){
            temp2=temp2->left;
        }
        succ=temp2;
     }

}

//void delete(node *tree,int key){
  //  node *tmp=search(node,key);
    //if(tmp==NULL)
      //  printf("No such node found\n");
    //else{
      //  if(tree){
        //  if(tree->data==key && tree->left==NULL && tree->right==NULL){
          //      free(tree);
            //    return ;
            //}
            //else if(tree->data)
        //}
    //}
//}

int count=0;
int k=0;
char arr[100];

void postorder(node *p){

  if(p){
    postorder(p->left);
    postorder(p->right);
    if((p->data=='a' || p->data=='e'|| p->data=='i' || p->data=='o' || p->data=='u') &&(p->left!=NULL && p->right!=NULL))
    printf("%c ",p->data);
  }
}



void main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 'a');
    insert(&root, 'b');
    insert(&root, 'c');
    insert(&root, 'd');
    insert(&root, 'e');
    insert(&root, 'f');
    insert(&root, 'g');

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

    /* Deleting all nodes of tree */
    //deltree(root);
    //vowels(root);
    //for(int i=0;i<1;i++)
      //  printf("%c",arr[i]);

      postorder(root);
     // int a=sizeof(arr)/sizeof(arr[0]);
      //for(int i=0;i<a;i++)
        //printf("%c",arr[i]);
        node *pre,*succ;
        findpresuc(root,pre,succ);

        if(pre==NULL)
            printf("No inorder predessor\n");
        else{
            printf("Inorder of predessor is:");
            printf(" %c\n",pre->data);
        }
        if(succ==NULL)
            printf("No inorder successor\n");
        else{
            printf("Inorder of successor is:");
            printf("%c\n",succ->data);
        }
}
