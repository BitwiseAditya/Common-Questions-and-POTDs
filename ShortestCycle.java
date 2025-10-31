
/*Shortest Cycle

You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertex u and v.
Find the length of the shortest cycle in the graph. If the graph does not contain any cycle, return -1.


Note: A cycle is a path that starts and ends at the same vertex without repeating any edge or vertex (except the start/end vertex). The shortest cycle is the one with the minimum number of edges.

Examples

Input: V = 7, E = 8, edges[][] = [[0, 5], [0, 6], [5, 1], [6, 1], [6, 2], [2, 3], [3, 4], [1, 4]]

Output: 4
Explanation: Possible cycles are: 
0 → 5 → 1 → 6 → 0 (length = 4)
1 → 4 → 3 → 2 → 6 → 1 (length = 5)
The smallest one is 0 → 5 → 1 → 6 → 0, with length 4. 
Input: V = 7, E = 9, edges[][] = [[0, 5], [0, 6], [1, 2], [1, 4], [1, 5], [1, 6], [2, 6], [2, 3], [3, 4]]

Output: 3
Explanation: Possible cycles include:
1 → 2 → 6 → 1 (length = 3)
1 → 2 → 3 → 4 → 1 (length = 4)
0 → 5 → 1 → 6 → 0 (length = 4)
The smallest one is 1 → 2 → 6 → 1, with length 3.
Constraints:
1 ≤ V ≤ 103
0 ≤ E ≤ 103
0 ≤ edges[i][0], edges[i][1] < V */

package GFG_POTD;

import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;

public class ShortestCycle {

    // Function to find the shortest cycle in an undirected graph
    public static int shortCycle(ArrayList<ArrayList<Integer>> adj) {

        int V = adj.size();
        int ans = Integer.MAX_VALUE;

        // Collect all unique edges (u < v to avoid duplicates)
        ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
        for (int u = 0; u < V; u++) {
            for (int v : adj.get(u)) {
                if (u < v) {
                    ArrayList<Integer> edge = new ArrayList<>();
                    edge.add(u);
                    edge.add(v);
                    edges.add(edge);
                }
            }
        }

        // For each edge (u, v), perform BFS ignoring that edge
        for (ArrayList<Integer> e : edges) {
            int u = e.get(0), v = e.get(1);

            int[] dist = new int[V];
            Arrays.fill(dist, -1);
            Queue<Integer> q = new LinkedList<>();

            // Start BFS from node u
            dist[u] = 0;
            q.add(u);

            while (!q.isEmpty()) {
                int node = q.poll();

                for (int nei : adj.get(node)) {
                    // Skip the removed edge (u, v)
                    if ((node == u && nei == v) || (node == v && nei == u))
                        continue;

                    // If not visited, update distance and push to queue
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        q.add(nei);
                    }
                }
            }

            // If v is reachable from u, we found a cycle
            if (dist[v] != -1)
                ans = Math.min(ans, dist[v] + 1);
        }

        // If no cycle is found, return -1
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }

    // Helper function to add an undirected edge
    public static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    public static void main(String[] args) {

        int V = 7;

        // Create adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Add edges
        addEdge(adj, 0, 5);
        addEdge(adj, 0, 6);
        addEdge(adj, 1, 4);
        addEdge(adj, 1, 5);
        addEdge(adj, 1, 6);
        addEdge(adj, 2, 3);
        addEdge(adj, 2, 6);
        addEdge(adj, 3, 4);
        addEdge(adj, 4, 1);
        addEdge(adj, 5, 0);
        addEdge(adj, 6, 2);
        addEdge(adj, 6, 1);
        addEdge(adj, 6, 0);

        // Call the function
        int result = shortCycle(adj);

        System.out.println(result);
    }
}
