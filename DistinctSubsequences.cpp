/*Number of distinct subsequences

Given a string str consisting of lowercase english alphabets, the task is to find the number of distinct subsequences of the string
Note: Answer can be very large, so, ouput will be answer modulo 109+7.
      Solve it in O(n) linear time.
Examples:

Input: str = "gfg"
Output: 7
Explanation:
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
Input: str = "ggg"
Output: 4
Explanation:
The four distinct subsequences are "", "g", "gg", "ggg".
Constraints:
1 ≤ |str| ≤ 105
str contains lower case English alphabets*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int distinctSubseq(string &str)
{
    int n = str.size();
    int mod = 1000000007;

    // to store the results up to
    // each index i, from 0 to n
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    // to store the last occurrence
    // of each character in the string
    vector<int> last(26, -1);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;

        // if the character is seen before
        // subtract the count of subsequences
        if (last[str[i - 1] - 'a'] != -1)
        {
            dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + mod) % mod;
        }

        // update the last occurrence of the character
        last[str[i - 1] - 'a'] = i - 1;
    }
    return dp[n];
}
