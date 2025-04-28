/* Maximum sum of Non-adjacent nodes

Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105 */

// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    int getSum(Node *root, unordered_map<Node *, int> &memo)
    {
        if (root == NULL || root == nullptr)
        {
            return 0;
        }
        if (memo.find(root) != memo.end())
        {
            return memo[root];
        }
        int pick = root->data;
        if (root->right)
        {
            pick += getSum(root->right->left, memo) + getSum(root->right->right, memo);
        }
        if (root->left)
        {
            pick += getSum(root->left->left, memo) + getSum(root->left->right, memo);
        }
        int notpick = 0;
        notpick += getSum(root->left, memo) + getSum(root->right, memo);
        return memo[root] = max(pick, notpick);
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        // code here
        unordered_map<Node *, int> memo;
        return getSum(root, memo);
    }
};
