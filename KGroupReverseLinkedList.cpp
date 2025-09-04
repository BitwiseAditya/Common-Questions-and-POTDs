/* Linked List Group Reverse

You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

Examples:

Input: k = 2,

Output: 2 -> 1 -> 4 -> 3 -> 6 -> 5
Explanation: Linked List is reversed in a group of size k = 2.

Input: k = 4,

Output: 4 -> 3 -> 2 -> 1 -> 6 -> 5
Explanation: Linked List is reversed in a group of size k = 4.

Constraints:
1 ≤ size of linked list ≤ 105
0 ≤ node->data ≤ 106
1 ≤ k ≤ size of linked list
 */
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        vector<pair<Node *, Node *>> v;
        Node *temp = head;
        pair<Node *, Node *> p;
        p.first = head;
        int count = 0;
        while (temp != NULL)
        {
            while (count != k)
            {
                count++;
                if (count == k || temp->next == NULL)
                {
                    p.second = temp;
                    v.push_back(p);
                    p.first = temp->next;
                    p.second = NULL;
                    count = 0;
                    temp = temp->next;
                    break;
                }
                temp = temp->next;
            }
        }
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp0 = NULL;
            Node *temp1 = v[i].first;
            Node *temp2 = v[i].first->next;
            while (temp1 != v[i].second)
            {
                temp1->next = temp0;
                temp0 = temp1;
                temp1 = temp2;
                temp2 = temp2->next;
            }
            temp1->next = temp0;
        }
        for (int i = 1; i < n; i++)
        {
            v[i - 1].first->next = v[i].second;
        }
        v[n - 1].first->next = NULL;
        return v[0].second;
    }
};