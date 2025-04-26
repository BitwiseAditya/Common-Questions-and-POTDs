/* Is Binary Tree Heap

You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]

Output: true
Explanation: The tree is complete and satisfies the max-heap property.
Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4]

Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103 */

#include <bits/stdc++.h>
using namespace std;

// Structure of node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    bool isMaxHeap(vector<Node *> heap)
    {
        int n = heap.size();
        for (int i = 1; i < n; i++)
        {
            if (heap[i] != NULL && heap[i] != nullptr && (heap[i - 1] == NULL || heap[i - 1] == nullptr))
            {
                return false;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int parentIndex = floor((i - 1) / 2);
            if (heap[i] != NULL && heap[i] != nullptr && heap[parentIndex]->data < heap[i]->data)
            {
                return false;
            }
        }
        return true;
    }
    bool isHeap(Node *tree)
    {
        // code here
        queue<Node *> q;
        vector<Node *> heap;
        q.push(tree);
        while (!q.empty())
        {
            vector<Node *> temp;
            while (!q.empty())
            {
                temp.push_back(q.front());
                q.pop();
            }
            int n = temp.size();
            for (int i = 0; i < n; i++)
            {
                if (temp[i] != NULL && temp[i] != nullptr)
                {
                    q.push(temp[i]->left);
                    q.push(temp[i]->right);
                }
                heap.push_back(temp[i]);
            }
        }
        bool check = isMaxHeap(heap);
        if (check)
            return true;
        else
            return false;
    }
};
