/* Left View of Binary Tree

You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.

Examples :

Input: root[] = [1, 2, 3, 4, 5, N, N]

Output: [1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

Input: root[] = [N]
Output: []
Constraints:
0 <= number of nodes <= 106
0 <= node -> data <= 105 */

#include <bits/stdc++.h>
using namespace std;

// A binary tree node

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        // code here
        queue<Node *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty())
        {
            vector<Node *> level;
            while (!q.empty())
            {
                level.push_back(q.front());
                q.pop();
            }
            int n = level.size();
            int counter = 0;
            for (int i = 0; i < n; i++)
            {
                if (counter == 0 && level[i] != NULL)
                {
                    ans.push_back(level[i]->data);
                    counter = 1;
                }
                if (level[i] != NULL)
                {
                    q.push(level[i]->left);
                    q.push(level[i]->right);
                }
            }
        }
        return ans;
    }
};
