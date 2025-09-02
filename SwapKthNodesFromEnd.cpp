/* Swap Kth nodes from ends

Given the head of a singly linked list and an integer k. Swap the kth node (1-based index) from the beginning and the kth node from the end of the linked list. Return the head of the final formed list and if it's not possible to swap the nodes return the original list.

Examples:

Input: k = 1,

Output: 5 -> 2 -> 3 -> 4 -> 1
Explanation: Here k = 1, hence after swapping the 1st node from the beginning and end the new list will be 5 -> 2 -> 3 -> 4 -> 1.

Input: k = 2,

Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
Explanation: Here k = 2, hence after swapping the 2nd node from the beginning and end the new list will be 5 -> 9 -> 8 -> 5 -> 10 -> 3.

Constraints:
1 ≤ list size ≤ 104
1 ≤ node->data ≤ 106
1 ≤ k ≤ 104

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
    Node *swapKth(Node *head, int k)
    {
        // code here
        Node *last = head;
        int length = 0;
        while (last != NULL)
        {
            length++;
            last = last->next;
        }
        if (k > length)
            return head;
        Node *temp1 = head;
        Node *temp2 = new Node(0);
        int count = 1;
        while (count != k)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            count++;
        }
        Node *temp3 = head;
        Node *temp4 = new Node(0);
        count = 1;
        while (count != length - k + 1)
        {
            temp4 = temp3;
            temp3 = temp3->next;
            count++;
        }
        // performing swapping :-
        temp2->next = temp3;
        temp4->next = temp1;
        Node *temp5 = temp1->next;
        temp1->next = temp3->next;
        temp3->next = temp5;
        if (k == 1)
            return temp2->next;
        if (k == length)
            return temp4->next;
        return head;
    }
};
