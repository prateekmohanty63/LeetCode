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

class Solution
{
public:
    Node *connect(Node *root)
    {

        Node *current = root;
        Node *nxt;

        if (root == NULL)
            return root;

        if (root->left)
            nxt = root->left;

        else
            nxt = NULL;

        // traverse till current is not null and next is not null

        while (current && nxt)
        {
            current->left->next = current->right;

            // connect right node to its right node only if current next not equal to NULL

            if (current->next)
            {
                current->right->next = current->next->left;
            }
            else
            {
                current->right->next = NULL;
            }

            if (current->next)
            {
                current = current->next;
            }
            else
            {
                current = nxt;
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