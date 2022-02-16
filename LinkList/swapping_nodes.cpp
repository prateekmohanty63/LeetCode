#include <iostream>
using namespace std;

/// 1st approach
/// Most optimized
/// One pass solution

// Runtime: 774 ms, faster than 63.43% of C++ online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 180.2 MB, less than 60.56% of C++ online submissions for Swapping Nodes in a Linked List.

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        ListNode *kth = NULL;

        while (--k)
        {
            ptr1 = ptr1->next;
        }

        kth = ptr1;
        cout << kth->val;

        ptr1 = ptr1->next;

        while (ptr1)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        swap(ptr2->val, kth->val);

        return head;
    }
};

// 1st approach
// Runtime: 923 ms, faster than 48.55% of C++ online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 180.1 MB, less than 90.81% of C++ online submissions for Swapping Nodes in a Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *temp = head;

        int n = 0;

        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        int first = 0, second = 0;
        int a = k - 1;
        temp = head;
        while (a--)
        {
            temp = temp->next;
        }
        first = temp->val;

        cout << first;

        int b = n - k;
        temp = head;
        while (b--)
        {
            temp = temp->next;
        }
        second = temp->val;
        temp->val = first;
        cout << second;

        temp = head;

        a = k - 1;
        while (a--)
        {
            temp = temp->next;
        }
        temp->val = second;
        return head;
    }
};

// 2nd approach
// some glitch here

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *temp = head;

        int n = 0;
        int first = -1, second = -1;
        int m = 0;

        while (temp != NULL)
        {
            if (n == k - 1)
            {
                first = temp->val;
            }
            n++;
            temp = temp->next;
        }
        cout << first;
        if (k == n)
        {
            temp = head;
            first = temp->val;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            second = temp->val;
            temp->val = first;
            // cout<<second;
            temp = head;
            temp->val = second;

            return head;
        }

        temp = head;
        int i = n - k;

        while (i--)
        {
            temp = temp->next;
        }

        second = temp->val;
        cout << second;

        m = n - k;

        temp = head;
        i = 0;

        while (m != 0)
        {
            if (i == k - 1)
            {
                temp->val = second;
            }
            i++;
            temp = temp->next;
            m--;
        }
        temp->val = first;

        return head;
    }
};

int main()
{

    return 0;
}