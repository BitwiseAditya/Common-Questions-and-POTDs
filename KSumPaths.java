
/*
 * K Sum Paths

 * Given the root of a binary tree and an integer k, determine the number of
 * downward-only paths where the sum of the node values in the path equals k.
 * 
 * Note: A path can start and end at any node within the tree but must always
 * move downward (from parent to child).
 * 
 * Examples:
 * 
 * Input: root = [8, 4, 5, 3, 2, N, 2, 3, -2, N, 1], k = 7
 * 
 * Output: 3
 * Explanation: The following paths sum to k
 * 
 * Input: root = [1, 2, 3], k = 3
 * 
 * Output: 2
 * Explanation: The following paths sum to k
 * 
 * Constraints:
 * 1 ≤ number of nodes ≤ 104
 * -100 ≤ node value ≤ 100
 * -109 ≤ k ≤ 109
 * 
 */
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class KSumPaths {
    int ans = 0;

    public void dfs(Node root, int k, Map<Integer, Integer> mp, int curr_sum) {
        if (root == null)
            return;
        curr_sum += root.data;
        if (mp.containsKey(curr_sum - k)) {
            ans += mp.get(curr_sum - k);
        }
        if (mp.containsKey(curr_sum)) {
            int value = mp.get(curr_sum);
            mp.remove(curr_sum);
            mp.put(curr_sum, value + 1);
        } else {
            mp.put(curr_sum, 1);
        }
        dfs(root.left, k, mp, curr_sum);
        dfs(root.right, k, mp, curr_sum);
        int value = mp.get(curr_sum);
        mp.remove(curr_sum);
        mp.put(curr_sum, value - 1);
        curr_sum -= root.data;
        return;
    }

    public int countAllPaths(Node root, int k) {
        // code here
        Map<Integer, Integer> mp = new HashMap<>();
        int curr_sum = 0;
        mp.put(0, 1);
        dfs(root, k, mp, curr_sum);
        return ans;
    }
}
