/* Number of Ways to Arrive at Destination

You are given an undirected weighted graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where edges[i] = [ui, vi, timei] means that there is an undirected edge between nodes ui and vi that takes timei minutes to reach.
Your task is to return in how many ways you can travel from node 0 to node V - 1 in the shortest amount of time.

Examples:

Input: V = 4, edges[][] = [[0, 1, 2], [1, 2, 3], [0, 3, 5], [1, 3, 3], [2, 3, 4]]
    
Output: 2
Explanation: The shortest path from 0 to 3 is 5.
Two ways to reach 3 in 5 minutes are:
0 -> 3
0 -> 1 -> 3
Input: V = 6, edges[][] = [[0, 2, 3], [0, 4, 2], [0, 5, 7], [2, 3, 1], [2, 5, 5], [5, 3, 3], [5, 1, 4], [1, 4, 1], [4, 5, 5]]
    
Output: 4
Explanation: The shortest path from 0 to 5 is 7.
Four ways to reach 5 in 7 minutes are:
0 -> 5
0 -> 4 -> 5
0 -> 4 -> 1 -> 5
0 -> 2 -> 3 -> 5
Constraints:
1 ≤ V ≤ 200
V - 1 ≤ edges.size() ≤ V * (V - 1) / 2
0 ≤ ui, vi ≤ V - 1
1 ≤ timei ≤ 105
ui != vi

 */

import java.util.*;

class Pair implements Comparable<Pair> {
    int key;
    int value;

    Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }

    public int compareTo(Pair p) {
        if (this.key == p.key) {
            return Integer.compare(this.value, p.value);
        }
        return Integer.compare(this.key, p.key);
    }

    public boolean equals(Object p) {
        if (!(p instanceof Pair))
            return false;
        Pair temp = (Pair) p;
        return this.key == temp.key && this.value == temp.value;
    }

    public int hashCode() {
        return Objects.hash(key, value);
    }
}

class NumberOfWaysToArriveAtDestination {
    public void dijkstra(int V, int source, HashMap<Integer, ArrayList<Pair>> graph, int[] distance, int[] paths) {
        distance[source] = 0;
        paths[source] = 1;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        pq.offer(new Pair(0, source));
        while (!pq.isEmpty()) {
            Pair temp = pq.poll();
            if (temp.key > distance[temp.value]) {
                continue;
            } else {
                for (Pair p : graph.get(temp.value)) {
                    if (distance[p.value] > p.key + distance[temp.value]) {
                        distance[p.value] = p.key + distance[temp.value];
                        paths[p.value] = paths[temp.value];
                        pq.offer(new Pair(distance[p.value], p.value));
                    } else if (distance[p.value] == p.key + distance[temp.value]) {
                        paths[p.value] = paths[p.value] + paths[temp.value];
                    }
                }
            }
        }
        return;
    }

    public int countPaths(int V, int[][] edges) {
        // code here
        HashMap<Integer, ArrayList<Pair>> graph = new HashMap<>();
        for (int[] edge : edges) {
            if (graph.containsKey(edge[0])) {
                graph.get(edge[0]).add(new Pair(edge[2], edge[1]));
            } else {
                ArrayList<Pair> arr = new ArrayList<>();
                arr.add(new Pair(edge[2], edge[1]));
                graph.put(edge[0], arr);
            }
            if (graph.containsKey(edge[1])) {
                graph.get(edge[1]).add(new Pair(edge[2], edge[0]));
            } else {
                ArrayList<Pair> arr = new ArrayList<>();
                arr.add(new Pair(edge[2], edge[0]));
                graph.put(edge[1], arr);
            }
        }
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[0] = 0;
        int[] paths = new int[V];
        Arrays.fill(paths, Integer.MAX_VALUE);
        paths[0] = 1;
        dijkstra(V, 0, graph, distance, paths);
        return paths[V - 1];
    }
}
