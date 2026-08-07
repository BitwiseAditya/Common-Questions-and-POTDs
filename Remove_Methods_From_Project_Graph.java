/*

3310. Remove Methods From Project

You are maintaining a project that has n methods numbered from 0 to n - 1.

You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

A group of methods can only be removed if no method outside the group invokes any methods within it.

Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

 

Example 1:

Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

Output: [0,1,2,3]

Explanation:



Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

Example 2:

Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

Output: [3,4]

Explanation:



Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

Example 3:

Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

Output: []

Explanation:



All methods are suspicious. We can remove them.

 

Constraints:

1 <= n <= 105
0 <= k <= n - 1
0 <= invocations.length <= 2 * 105
invocations[i] == [ai, bi]
0 <= ai, bi <= n - 1
ai != bi
invocations[i] != invocations[j] */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class Remove_Methods_From_Project_Graph {
    public void dfs(List<List<Integer>> adjList, int n, int k, HashSet<Integer> set, boolean[] visited) {
        if (visited[k])
            return;

        visited[k] = true;
        set.add(k);
        int size = adjList.get(k).size();
        for (int i = 0; i < size; i++) {
            if (!visited[adjList.get(k).get(i)]) {
                dfs(adjList, n, adjList.get(k).get(i), set, visited);
            }
        }
        return;
    }

    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        List<List<Integer>> adjList = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] inv : invocations) {
            adjList.get(inv[0]).add(inv[1]);
        }
        HashSet<Integer> set = new HashSet<>();
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        dfs(adjList, n, k, set, visited);
        boolean counter = false;
        for (int i = 0; i < n; i++) {
            if (!set.contains(i)) {
                int size = adjList.get(i).size();
                for (int j = 0; j < size; j++) {
                    if (set.contains(adjList.get(i).get(j))) {
                        counter = true;
                        break;
                    }
                }
            }
        }
        if (counter == true) {
            for (int i = 0; i < n; i++) {
                ans.add(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!set.contains(i)) {
                    ans.add(i);
                }
            }
        }
        return ans;
    }
}

// BFS aur DFS done mein VISITED array / set ka use hota hai hamesha.
// Do not forget the use of VISITED set in Graph Traversals - BFS and DFS. Very
// Important!!!
