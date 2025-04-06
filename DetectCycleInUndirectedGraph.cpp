/* Undirected Graph Cycle

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation:

1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation:

No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool dfs(int parentVertex, int vertex, int V, unordered_map<int, vector<int>> &graph, vector<bool> &visited)
    {
        int n = graph[vertex].size();
        for (int i = 0; i < n; i++)
        {
            if (visited[graph[vertex][i]] == true && graph[vertex][i] != parentVertex)
            {
                return true;
            }
            else if (graph[vertex][i] != parentVertex)
            {
                visited[graph[vertex][i]] = true;
                if (dfs(vertex, graph[vertex][i], V, graph, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<bool> visited(V, false);
        unordered_map<int, vector<int>> graph;
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                if (dfs(-1, i, V, graph, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
