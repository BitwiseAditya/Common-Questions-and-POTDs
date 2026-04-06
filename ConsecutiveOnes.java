/*Consecutive 1's not allowed
Given a positive integer n, count all possible distinct binary strings of length n such that there are no consecutive 1’s.

Examples :

Input: n = 3
Output: 5
Explanation: 5 strings are ("000", "001", "010", "100", "101").
Input: n = 2
Output: 3
Explanation: 3 strings are ("00", "01", "10").
Input: n = 1
Output: 2
Constraints:
1 ≤ n ≤ 44*/ 

class ConsecutiveOnes {
    /*
     * int countStringsRec(int index, int n, int [] dp){
     * if(index >= n){
     * return 1;
     * }
     * if(dp[index] != -1){
     * return dp[index];
     * }
     * int zero = countStringsRec(index+1,n,dp);
     * int one = countStringsRec(index+2,n,dp);
     * return dp[index] = zero + one;
     * }
     */
    int countStrings(int n) {
        // code here
        int[] dp = new int[n + 2];
        Arrays.fill(dp, -1);
        dp[n] = 1;
        dp[n + 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];
    }
}




