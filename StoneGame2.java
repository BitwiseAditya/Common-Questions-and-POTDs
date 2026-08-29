/*1140. Stone Game II

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. 
The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104

 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104 */

import java.util.HashMap;
import java.util.Map;

public class StoneGame2 {
    public int stoneGameRec(int[] piles, int index, int M, int[] suffix, Map<String, Integer> memo) {
        String temp = Integer.toString(index) + ',' + Integer.toString(M);
        if (memo.containsKey(temp)) {
            return memo.get(temp);
        }
        if (index + 2 * M >= piles.length)
            return suffix[index];
        int res = Integer.MAX_VALUE;
        for (int i = 1; i <= (2 * M); i++) {
            res = Math.min(res, stoneGameRec(piles, index + i, Math.max(M, i), suffix, memo));
        }
        memo.put(temp, suffix[index] - res);
        return (suffix[index] - res);
    }

    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[] suffix = new int[n];
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }
        Map<String, Integer> memo = new HashMap<>();
        return stoneGameRec(piles, 0, 1, suffix, memo);
    }
}
