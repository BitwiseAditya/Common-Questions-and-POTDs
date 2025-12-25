/* Find the Peak Element in a 2D Matrix

Given a 2D matrix mat[][], identify any peak element within the matrix.

An element is considered a peak if it is greater than or equal to its four immediate neighbors: top, bottom, left, and right. For corner and edge elements, any missing neighbors are treated as having a value of negative infinity.

Note: A peak element is not necessarily the global maximum, it only needs to satisfy the condition relative to its adjacent elements. Multiple peak elements may exist, return any one of them.
Note that the driver code will print true if you return the correct position of peak element, else it will print false.

Examples:

Input: mat[][] = [[10, 20, 15],           
                [21, 30, 14],
                 [7, 16, 32]]
Output: true
Explanation: One of the peak element is 30 at index (1, 1), which is greater than or equal to all its valid neighbors: Left = 21, Right = 14, Top = 20, Bottom = 16. So, it satisfies the peak condition. Alternatively, (2, 2) with value 32 also qualifies as a peak.
Input: mat[][] = [[17, 7],
                [11, 10]]
Output: true
Explanation: 17 is the only peak element at index (0, 0). Its neighbors are: Right= 7, Bottom = 11. Since 17 is greater than or equal to both (and top/left are out of bounds), it qualifies as a peak element.
Constraint:
1 ≤ n × m ≤ 106
-106 ≤ mat[i][j] ≤ 106 */

import java.util.*;

class Solution {
    public ArrayList<Integer> findPeakGrid(int[][] mat) {
        // code here
        int m = mat[0].length;
        int low = 0, high = m - 1;
        ArrayList<Integer> arr = new ArrayList<>();
        // ✅ Handle single column case
        if (m == 1) {
            int maxRow = 0;
            for (int i = 1; i < mat.length; i++) {
                if (mat[i][0] > mat[maxRow][0]) {
                    maxRow = i;
                }
            }
            ArrayList<Integer> ans = new ArrayList<>();
            ans.add(maxRow);
            ans.add(0);
            return ans;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxi = Integer.MIN_VALUE;
            int index = -1;
            for (int i = 0; i < mat.length; i++) {
                if (mat[i][mid] > maxi) {
                    maxi = mat[i][mid];
                    index = i;
                }
            }
            if (mid + 1 < m && mid - 1 >= 0) {
                if (mat[index][mid] >= mat[index][mid + 1] &&
                        mat[index][mid] >= mat[index][mid - 1]) {
                    arr.add(index);
                    arr.add(mid);
                    return arr;
                } else if (mat[index][mid] >= mat[index][mid + 1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (mid + 1 < m) {
                    if (mat[index][mid] >= mat[index][mid + 1]) {
                        arr.add(index);
                        arr.add(mid);
                        return arr;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    if (mat[index][mid] >= mat[index][mid - 1]) {
                        arr.add(index);
                        arr.add(mid);
                        return arr;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }
        arr.add(-1);
        arr.add(-1);
        return arr;
    }
}
