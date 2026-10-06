/*Longest Path in a Directed Acyclic Graph

Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by edges[][], 
where edges[i] = [u, v, w] denotes a directed edge from u to v with weight w, and a source vertex src.

Return the distance array, where the value at index i represents the longest distance from src to vertex i.
If a vertex is unreachable from s, store INT_MIN for that vertex. The driver code will automatically display INT_MIN as INF.
Examples :

Input: V = 4, src = 0, edges[][] = [[0, 1, 1], [0, 2, 1], [1, 2, 5], [3, 1, 2], [3, 2, -1]]
Output: [0, 1, 6, INF]
Explanation: The longest distance of vertex 1 from 0 is 1, vertex 2 is 6 and vertex 3 is unreachable so INF.

Input: V = 5, src = 1, edges[][] = [[0, 1, 1], [0, 2, 2], [1, 4, 4], [3, 2, -1], [4, 2, 3], [4, 3, 6]]
Output: [INF, 0, 9, 10, 4]
Explanation: The vertex 0 is not reachable from vertex 1 so its distance is INF, for 2 it is 9, for 3 it is 10, and for 4 it is 4.
*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class LongestPathInDAG {
    public int[] maxDistance(int V, int src, ArrayList<ArrayList<Integer>> edges) {
        // code here
        ArrayList<ArrayList<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }
        int[] indegree = new int[V];
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            int u = edges.get(i).get(0);
            int v = edges.get(i).get(1);
            int w = edges.get(i).get(2);
            indegree[v] += 1;
            graph.get(u).add(new int[] { v, w });
        }
        ArrayList<Integer> topoSort = new ArrayList<Integer>();
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int node = q.poll();
            topoSort.add(node);
            for (int[] edge : graph.get(node)) {
                int v = edge[0];
                indegree[v] -= 1;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MIN_VALUE);
        dist[src] = 0;
        for (Integer v : topoSort) {
            if (dist[v] == Integer.MIN_VALUE)
                continue;
            for (int[] edge : graph.get(v)) {
                int e = edge[0];
                int w = edge[1];
                dist[e] = Math.max(dist[e], dist[v] + w);
            }
        }
        return dist;
    }
}