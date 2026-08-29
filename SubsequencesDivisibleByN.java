/*Count Subsequences Divisible by n

Given a numeric string s containing only digits and an integer n, 
count the number of non-empty subsequences of s whose numeric value 
is divisible by n. Return the answer modulo 1e9 + 7.

Examples:

Input: s = "1234", n = 4
Output: 4
Explanation: The subsequences 4, 12, 24 and 124 are divisible by 4.
Input: s = "330", n = 6
Output: 4
Explanation: The subsequences 30, 30, 330 and 0 are divisible by 6.
Constraints:
1 ≤ |s| * n ≤ 106
 */

class SubsequencesDivisibleByN {
    int countSubsequencesRecursion(int index, int remainder, int started, String s, int n, int[][][] dp) {
        if (dp[index][remainder][started] != -1) {
            return dp[index][remainder][started];
        }
        if (index == (s.length() - 1)) {
            if (remainder == 0 && started == 1) {
                int digit = s.charAt(index) - '0';
                if (digit % n == 0)
                    return 2;
                else
                    return 1;
            } else {
                int digit = s.charAt(index) - '0';
                if ((remainder * 10 + digit) % n == 0)
                    return 1;
                else
                    return 0;
            }
        }
        int ans = 0;
        ans = (ans + countSubsequencesRecursion(index + 1, remainder, started, s, n, dp)) % 1000000007;
        int digit = s.charAt(index) - '0';
        int rem = 0;
        if (started == 1) {
            rem = (remainder * 10 + digit) % n;
        } else {
            rem = digit % n;
        }
        ans = (ans + countSubsequencesRecursion(index + 1, rem, 1, s, n, dp)) % 1000000007;
        return dp[index][remainder][started] = ans;
    }

    public int countSubsequences(String s, int n) {
        // code here
        int m = s.length();
        int[][][] dp = new int[m][n + 1][2];
        // Memoization :-
        /*
         * for(int [][] arr : dp){
         * for(int [] brr : arr){
         * Arrays.fill(brr , -1);
         * }
         * }
         * return countSubsequencesRecursion(0,0,0,s,n,dp) % 1000000007 ;
         */

        // Tabulation :-
        for (int remainder = 0; remainder < n; remainder++) {
            for (int started = 0; started <= 1; started++) {
                if (remainder == 0 && started == 1) {
                    int digit = s.charAt(m - 1) - '0';
                    if (digit % n == 0)
                        dp[m - 1][remainder][started] = 2;
                    else
                        dp[m - 1][remainder][started] = 1;
                } else {
                    int digit = s.charAt(m - 1) - '0';
                    if ((remainder * 10 + digit) % n == 0)
                        dp[m - 1][remainder][started] = 1;
                    else
                        dp[m - 1][remainder][started] = 0;
                }
            }
        }
        for (int index = m - 2; index >= 0; index--) {
            for (int remainder = 0; remainder < n; remainder++) {
                for (int started = 0; started <= 1; started++) {
                    int ans = 0;
                    ans = (ans + dp[index + 1][remainder][started]) % 1000000007;
                    int digit = s.charAt(index) - '0';
                    int rem = 0;
                    if (started == 1) {
                        rem = (remainder * 10 + digit) % n;
                    } else {
                        rem = digit % n;
                    }
                    ans = (ans + dp[index + 1][rem][1]) % 1000000007;
                    dp[index][remainder][started] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
}
