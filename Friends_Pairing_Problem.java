/*Friends Pairing Problem

Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Examples :

Input: n = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
Input: n = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.
Input: n = 1
Output: 1

Constraints:

1 ≤ n ≤ 18 */

public class Friends_Pairing_Problem {
    // Returns count of ways n people
    // can remain single or paired up.
    static int countFriendsPairings(int n) {
        // creating a dp array to store results of subproblems
        int dp[] = new int[n + 1];

        // iterating from 0 to n
        for (int i = 0; i <= n; i++) {
            // base cases: when number of friends is 0, 1 or 2
            // number of ways is equal to i
            if (i <= 2)
                dp[i] = i;
            else
                // applying recurrence relation:
                // f(i) = f(i-1) + (i-1) * f(i-2)
                // case 1: ith friend stays single -> dp[i-1]
                // case 2: ith friend pairs with any of (i-1) friends -> (i-1) * dp[i-2]
                dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {
        int n = 18;
        System.out.println(countFriendsPairings(n));
    }
}
