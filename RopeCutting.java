/*Cut rope to maximise product

Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.

Examples:

Input: n = 2
Output: 1
Explanation: Since 1 cut is mandatory. Maximum obtainable product is 1 * 1 = 1.
Input: n = 5
Output: 6
Explanation: Maximum obtainable product is 2 * 3 = 6.
Constraints:
2 ≤ n ≤ 58 */

import java.util.Arrays;

public class RopeCutting {
    public int rodCutting(int n, int[] dp) {
        // recursive base case: If rod is of length 0 or 1,
        // no cutting possible. Hence, return 0 as maximum obtainable product.
        if (n == 0 || n == 1)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int maxVal = 0;
        for (int i = 1; i < n; i++) {
            int temp1 = i * (n - i);
            int temp2 = i * rodCutting(n - i, dp);
            maxVal = Math.max(maxVal, Math.max(temp1, temp2));
        }

        return dp[n] = maxVal;
    }

    public int maxProduct(int n) {
        // code here
        int[] dp = new int[n + 2];
        Arrays.fill(dp, -1);
        return rodCutting(n, dp);
    }
}
