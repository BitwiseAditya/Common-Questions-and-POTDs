/* Bridge edge in a graph

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.

Note:

An edge is called a bridge if removing it increases the number of connected components of the graph.
if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.
Examples :

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3]], c = 1, d = 2

Output: true
Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in disconnection of the graph.
Hence, it is a Bridge.
Input: V = 5, edges[][] = [[0, 1], [0, 3], [1, 2], [2, 0], [3, 4]], c = 0, d = 2

Output: false
Explanation:

Blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge Edges in the graph are marked with a green line in the above image.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ c, d ≤ V-1 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool dfs(unordered_map<int, unordered_set<int>> &graph, int V, int vertex, int k, vector<bool> &visited)
    {
        visited[vertex] = true;
        if (vertex == k)
            return true;
        for (const auto &num : graph[vertex])
        {
            if (visited[num] == false)
            {
                if (dfs(graph, V, num, k, visited))
                    return true;
            }
        }
        return false;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d)
    {
        // Code here
        unordered_map<int, unordered_set<int>> graph;
        for (auto &edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        graph[c].erase(d);
        graph[d].erase(c);
        vector<bool> visited(V, false);
        bool ans = dfs(graph, V, c, d, visited);
        if (ans == true)
            return false;
        else
            return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
