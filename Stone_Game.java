/*877. Stone Game

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
Example 2:

Input: piles = [3,7,2,3]
Output: true
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd. */

public class Stone_Game {
    public boolean stoneGame(int[] piles) {
        int N = piles.length;

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]].
        int[][] dp = new int[N + 2][N + 2];
        for (int size = 1; size <= N; ++size)
            for (int i = 0; i + size <= N; ++i) {
                int j = i + size - 1;
                int parity = (j + i + N) % 2; // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i + 1][j + 1] = Math.max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                else
                    dp[i + 1][j + 1] = Math.min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
            }

        return dp[1][N] > 0;
    }
}

/*
 * Intuition
 * 
 * Let's change the game so that whenever Bob scores points, it deducts from
 * Alice's score instead.
 * 
 * Let dp(i, j) be the largest score Alice can achieve where the piles remaining
 * are piles[i], piles[i+1], ..., piles[j]. This is natural in games with
 * scoring: we want to know what the value of each position of the game is.
 * 
 * We can formulate a recursion for dp(i, j) in terms of dp(i+1, j) and dp(i,
 * j-1), and we can use dynamic programming to not repeat work in this
 * recursion. (This approach can output the correct answer, because the states
 * form a DAG (directed acyclic graph).)
 * 
 * Algorithm
 * 
 * When the piles remaining are piles[i], piles[i+1], ..., piles[j], the player
 * who's turn it is has at most 2 moves.
 * 
 * The person who's turn it is can be found by comparing j-i to N modulo 2.
 * 
 * If the player is Alice, then she either takes piles[i] or piles[j],
 * increasing her score by that amount. Afterwards, the total score is either
 * piles[i] + dp(i+1, j), or piles[j] + dp(i, j-1); and we want the maximum
 * possible score.
 * 
 * If the player is Bob, then he either takes piles[i] or piles[j], decreasing
 * Alice's score by that amount. Afterwards, the total score is either -piles[i]
 * + dp(i+1, j), or -piles[j] + dp(i, j-1); and we want the minimum possible
 * score.
 * 
 */
