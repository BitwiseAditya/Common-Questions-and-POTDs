/* Longest Increasing Path in Matrix

Given a matrix with n rows and m columns. Your task is to find the length of the longest path in with the following constraints

The values in path strictly increasing.  For example if a path of length k has values a1, a2, a3, .... ak  , then for every i from [2, k] this condition must hold ai > ai-1. 
No cell should be revisited in the path.
From each cell,  you can move in any of of the four directions: left, right, up, or down.
You are not allowed to move diagonally or move outside the boundary.
Examples:

Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -> 2 -> 3 -> 6 -> 9, where each number is strictly greater than the previous.

Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -> 4 -> 5 -> 6.

Constraints:

1 ≤ n, m ≤ 1000
0 ≤ matrix[i][j] ≤ 230 */

// Java program to find
// longest increasing path in matrix

class LongestIncreasingPath {

    // Function which checks if the cell is valid
    // and its value is greater than previous cell.
    static boolean validCell(int i, int j, int[][] matrix,
            int prev) {
        return (i >= 0 && i < matrix.length && j >= 0
                && j < matrix[0].length
                && matrix[i][j] > prev);
    }

    static int pathRecur(int i, int j, int[][] matrix,
            int[][] memo) {

        // If answer exists in memo table.
        if (memo[i][j] != -1)
            return memo[i][j];

        // include current cell in answer
        int ans = 1;

        // direction vector to move in 4 directions
        int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        for (int[] d : dir) {
            int x = i + d[0], y = j + d[1];

            // Check if the cell is valid
            if (validCell(x, y, matrix, matrix[i][j])) {
                ans = Math.max(
                        ans, 1 + pathRecur(x, y, matrix, memo));
            }
        }

        // Memoize the answer and return it.
        memo[i][j] = ans;
        return ans;
    }

    static int longIncPath(int[][] matrix, int n,
            int m) {
        int ans = 0;

        // Initialize dp table
        int[][] memo = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                memo[i][j] = -1;
            }
        }

        // Check longest increasing path
        // for each cell.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = Math.max(
                        ans, pathRecur(i, j, matrix, memo));
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int n = 3, m = 3;
        int[][] matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

        System.out.println(longIncPath(matrix, n, m));
    }
}
