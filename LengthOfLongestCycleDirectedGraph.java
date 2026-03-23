/*Length of Longest Cycle in a Graph

Given an directed graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], 
where each entry edges[i] = [u, v] denotes an edge between vertices u and v. Each node has at most one outgoing edge.

Your task is to find the length of the longest cycle present in the graph. If no cycle exists, return -1.

Note: A cycle is a path that starts and ends at the same vertex.

Examples :

Input: V = 7, edges[][] = [[0, 5], [1, 0], [2, 4], [3, 1], [4, 6], [5, 6], [6, 3]]

Output: 5
Explanation: longest Cycle is 0->5->6->3->1->0
Input: V = 8, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 0], [4, 1], [5, 4], [6, 2], [7, 6]]

Output: 4
Explanation: longest Cycle is 0->1->2->3->0
Constraints:
1 ≤ V, E ≤ 104
0 ≤ edges[i][0], edges[i][1] < V

 */

import java.util.*;

public class LengthOfLongestCycleDirectedGraph {
    public int dfs(int vertex, Map<Integer, Integer> mp, boolean[] visited, int[] distance) {
        visited[vertex] = true;
        int tempans = -1;
        if (mp.containsKey(vertex)) {
            int to = mp.get(vertex);
            if (!visited[to]) {
                distance[to] = distance[vertex] + 1;
                tempans = Math.max(tempans, dfs(to, mp, visited, distance));
            } else if (distance[to] != -1) {
                tempans = Math.max(tempans, distance[vertex] + 1 - distance[to]);
            }
        }
        distance[vertex] = -1;
        return tempans;
    }

    public int longestCycle(int V, int[][] edges) {
        // code here
        boolean[] visited = new boolean[V];
        int[] distance = new int[V];
        Arrays.fill(distance, -1);
        Map<Integer, Integer> mp = new HashMap<>();
        for (int[] edge : edges) {
            mp.put(edge[0], edge[1]);
        }
        int ans = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                distance[i] = 0;
                visited[i] = true;
                ans = Math.max(ans, dfs(i, mp, visited, distance));
            }
        }
        return ans;
    }
}
