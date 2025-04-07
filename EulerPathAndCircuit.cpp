/* Euler circuit and Path

An Eulerian Path is a path in graph that visits every edge exactly once. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected connected graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

Example 1:

Input:

Output: 2
Explanation:
Following is an eulerian circuit in the mentioned graph
1 -> 2 -> 0 -> 1
Example 2:

Input:

Output: 1
Explanation:
Following is an eulerian path in the mentioned graph
1 -> 0 -> 2
Your Task:
You don't need to read or print anything. Your task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoted as V and an adjacency list of graph denoted as adj and returns 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, it returns 1, otherwise, it will return 0.

Expected Time Complexity: O(V+E) where E is the number of edges in graph.
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 104
1 ≤ adj[i][j] ≤ V-1 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int vertex, int V, vector<int> adj[], vector<int> &visited)
    {
        visited[vertex] = true;
        int n = adj[vertex].size();
        for (int i = 0; i < n; i++)
        {
            if (visited[adj[vertex][i]] == false)
            {
                visited[adj[vertex][i]] = true;
                dfs(adj[vertex][i], V, adj, visited);
            }
        }
        return;
    }
    int isEulerCircuit(int V, vector<int> adj[])
    {
        // Code here
        int start = -1;
        int oddCount = 0;
        vector<int> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() > 0)
            {
                start = i;
                break;
            }
        }
        if (start == -1)
            return 2;
        dfs(start, V, adj, visited);
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() > 0 && visited[i] == false)
                return 0;
        }
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() % 2 != 0)
            {
                oddCount++;
            }
        }
        if (oddCount == 0)
            return 2;
        if (oddCount == 2)
            return 1;
        if (oddCount > 2)
            return 0;
    }
};
