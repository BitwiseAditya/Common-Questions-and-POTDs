/* Clone an Undirected Graph

Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

class Node {
    val: integer
    neighbors: List[Node]
}
Your task is to complete the function cloneGraph( ) which takes a starting node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

Note: If you return a correct copy of the given graph, then the driver code will print true; and if an incorrect copy is generated or when you return the original node, the driver code will print false.

Examples :

Input: n = 4, adjList[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
Output: true
Explanation:

As the cloned graph is identical to the original one the driver code will print true.
Input: n = 3, adjList[][] = [[1, 2], [0], [0]]
Output: true
Explanation:

As the cloned graph is identical to the original one the driver code will print true.
Constraints:
1 ≤ n ≤ 104
0 ≤ no. of edges ≤ 105
0 ≤ adjList[i][j] < n */

#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

struct Node
{
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    void dfs(vector<struct Node *> &vec, struct Node *node, struct Node *head, int index)
    {
        struct Node *temp = head->neighbors[index];
        int n = temp->neighbors.size();
        for (int i = 0; i < n; i++)
        {
            if (vec[temp->neighbors[i]->val] == NULL)
            {
                struct Node *toInsert = new struct Node(temp->neighbors[i]->val);
                node->neighbors.push_back(toInsert);
                vec[temp->neighbors[i]->val] = toInsert;
                dfs(vec, toInsert, temp, i);
            }
            else
            {
                node->neighbors.push_back(vec[temp->neighbors[i]->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        // code here
        vector<struct Node *> vec(1e4 + 3, NULL);
        struct Node *head = new struct Node(node->val);
        vec[node->val] = head;
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++)
        {
            struct Node *temp = node->neighbors[i];

            if (vec[temp->val] == NULL)
            {
                struct Node *toInsert = new struct Node(temp->val);
                head->neighbors.push_back(toInsert);
                vec[temp->val] = toInsert;
                dfs(vec, toInsert, node, i);
            }
            else
            {
                head->neighbors.push_back(vec[temp->val]);
            }
        }
        return head;
    }
};
