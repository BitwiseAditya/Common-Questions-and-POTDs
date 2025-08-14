/* 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104. */

#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return DivideAndConquer(lists, 0, lists.size() - 1);
    }
    ListNode *DivideAndConquer(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            ListNode *l = DivideAndConquer(lists, left, mid);
            ListNode *r = DivideAndConquer(lists, mid + 1, right);
            return merge(l, r);
        }
        return NULL;
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL || left == nullptr)
            return right;
        if (right == NULL || right == nullptr)
            return left;
        if (left->val <= right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
};
