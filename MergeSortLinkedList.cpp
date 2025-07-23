/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode *L1 = sortList(head);
        ListNode *L2 = sortList(slow);
        return merge(L1, L2);
    }
    ListNode *merge(ListNode *L1, ListNode *L2)
    {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        ListNode *temp1 = L1;
        ListNode *temp2 = L2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = new ListNode(temp1->val);
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            temp->next = new ListNode(temp1->val);
            temp = temp->next;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            temp->next = new ListNode(temp2->val);
            temp = temp->next;
            temp2 = temp2->next;
        }
        return head->next;
    }
};
