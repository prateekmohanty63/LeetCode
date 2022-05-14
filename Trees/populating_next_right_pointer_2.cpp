#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 1st approach

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return root;

        Node *current = root;
        Node *nxt;

        if (root->left)
        {
            nxt = root->left;
        }
        if (root->left == NULL && root->right)
            nxt = root->right;
        else
            nxt = NULL;

        while (current && nxt)
        {

            // populating current of left node (LIKE FULL BINARY TREE)
            if (current->right && current->left)
            {
                current->left->next = current->right;
            }

            if (current->left && current->right == NULL)
            {
                current->left->next = NULL;
            }

            if (current->next)
            {
                if (current->right == NULL && current->next->left == NULL && current->next->right)
                {
                    current->left->next = current->next->right;
                }
                if (current->left)
                {
                    current->left->next = current->right;
                }
                if (current->right && current->next->left == NULL && current->next->right)
                {
                    current->right->next = current->next->right;
                }
                if (current->right && current->next->left == NULL && current->next->right == NULL)
                {
                    current->right->next = NULL;
                }
                else if (current->right && current->next->left)
                {
                    current->right->next = current->next->left;
                }
            }
            else
            {
                if (current->right)
                    current->right->next = NULL;
            }

            if (current->next)
            {
                current = current->next;
            }
            else
            {
                current = nxt;
                if (current->left)
                    nxt = current->left;

                else
                    nxt = current->right;
            }
        }

        return root;
    }
};

// checkpoint 2

// kind of hard coding
// failing some text cases as the pointer is only going to the left of the current node and is not traversing right of the current node

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return root;

        Node *current = root;
        Node *nxt;

        if (root->left)
        {
            nxt = root->left;
        }

        else
            nxt = NULL;

        while (current && nxt)
        {

            // populating current of left node (LIKE FULL BINARY TREE)
            if (current->right && current->left)
            {
                current->left->next = current->right;
            }

            // if(current->left && current->right==NULL)
            // {
            //     current->left->next=NULL;
            // }

            if (current->next)
            {
                if (current->left)
                {
                    current->left->next = current->right;
                }
                if (current->right == NULL && current->next->left == NULL && current->next->right)
                {
                    current->left->next = current->next->right;
                }
                // if(current->left)
                // {
                //     current->left->next=current->right;
                // }
                if (current->right && current->next->left == NULL && current->next->right)
                {
                    current->right->next = current->next->right;
                }
                if (current->right && current->next->left == NULL && current->next->right == NULL)
                {
                    current->right->next = NULL;
                }
                else if (current->right && current->next->left)
                {
                    current->right->next = current->next->left;
                }
            }
            else
            {

                if (current->left && current->right)
                {
                    current->left->next = current->right;
                }

                if (current->right)
                    current->right->next = NULL;
            }

            if (current->next)
            {
                current = current->next;
            }
            else
            {
                current = nxt;
                if (current->left)
                    nxt = current->left;

                else
                    nxt = current->right;
            }
        }

        return root;
    }
};

// method 3 (wrong)

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return root;

        Node *current = root;
        Node *nxt;

        if (root->left)
        {
            nxt = root->left;
        }

        else
            nxt = NULL;

        while (current && nxt)
        {

            // populating current of left node (LIKE FULL BINARY TREE)
            if (current->right && current->left)
            {
                current->left->next = current->right;
            }

            // if(current->left && current->right==NULL)
            // {
            //     current->left->next=NULL;
            // }

            if (current->next)
            {
                if (current->left)
                {
                    current->left->next = current->right;
                }
                if (current->right == NULL && current->next->left == NULL && current->next->right)
                {
                    current->left->next = current->next->right;
                }
                // if(current->left)
                // {
                //     current->left->next=current->right;
                // }
                if (current->right && current->next->left == NULL && current->next->right)
                {
                    current->right->next = current->next->right;
                }
                if (current->right && current->next->left == NULL && current->next->right == NULL)
                {
                    current->right->next = NULL;
                }
                else if (current->right && current->next->left)
                {
                    current->right->next = current->next->left;
                }
            }
            else
            {

                if (current->left && current->right)
                {
                    current->left->next = current->right;
                }

                if (current->right)
                    current->right->next = NULL;
            }

            if (current->next)
            {
                current = current->next;
            }
            else
            {
                current = nxt;
                if (current->left)
                    nxt = current->left;

                else
                    nxt = current->right;
            }
        }

        current = root;
        nxt;

        if (root->right)
        {
            nxt = root->right;
        }

        else
            nxt = NULL;

        while (current && nxt)
        {

            // populating current of left node (LIKE FULL BINARY TREE)
            if (current->right && current->left)
            {
                current->left->next = current->right;
            }

            // if(current->left && current->right==NULL)
            // {
            //     current->left->next=NULL;
            // }

            if (current->next)
            {
                if (current->left)
                {
                    current->left->next = current->right;
                }
                if (current->right == NULL && current->next->left == NULL && current->next->right)
                {
                    current->left->next = current->next->right;
                }
                // if(current->left)
                // {
                //     current->left->next=current->right;
                // }
                if (current->right && current->next->left == NULL && current->next->right)
                {
                    current->right->next = current->next->right;
                }
                if (current->right && current->next->left == NULL && current->next->right == NULL)
                {
                    current->right->next = NULL;
                }
                else if (current->right && current->next->left)
                {
                    current->right->next = current->next->left;
                }
            }
            else
            {

                if (current->left && current->right)
                {
                    current->left->next = current->right;
                }

                if (current->right)
                    current->right->next = NULL;
            }

            if (current->next)
            {
                current = current->next;
            }
            else
            {
                current = nxt;
                if (current->right)
                    nxt = current->right;

                else
                    nxt = current->left;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}