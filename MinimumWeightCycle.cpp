/* Minimum Weight Cycle

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
Your task is to find the minimum weight cycle in this graph.

Examples:

Input: V = 5, edges[][] = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]

Output: 6
Explanation:

Minimum-weighted cycle is  0 → 1 → 4 → 0 with a total weight of 6(2 + 1 + 3)
Input: V = 5, edges[][] = [[0, 1, 3], [1, 2, 2], [0, 4, 1], [1, 4, 2], [1, 3, 1], [3, 4, 2], [2, 3, 3]]

Output: 5
Explanation:

Minimum-weighted cycle is  1 → 3 → 4 → 1 with a total weight of 5(1 + 2 + 2)
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ 103
1 ≤ edges[i][j] ≤ 100 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(unordered_map<int, vector<pair<int, int>>> &graph, int V, int src, int dest)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(V, 1e8);
        pq.push({0, src});
        distance[src] = 0;
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for (const auto &pairs : graph[u])
            {
                int v = pairs.first;
                int w = pairs.second;
                if (distance[v] > dist + w && !((u == src && v == dest) || (u == dest && v == src)))
                {
                    distance[v] = dist + w;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance[dest];
    }
    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<pair<int, int>>> graph;
        int ans = INT_MAX;
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        for (const auto &edge : edges)
        {
            int dist = dijkstra(graph, V, edge[0], edge[1]);
            if (dist != 1e8)
            {
                ans = min(ans, dist + edge[2]);
            }
        }
        return ans;
    }
};
