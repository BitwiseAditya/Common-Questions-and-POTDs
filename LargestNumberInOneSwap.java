/*Largest number in one swap

Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.

Examples:

Input: s = "768"
Output: "867"
Explanation: Swapping the 1st and 3rd characters(7 and 8 respectively), gives the lexicographically largest string.
Input: s = "333"
Output: "333"
Explanation: Performing any swaps gives the same result i.e "333".
Constraints:
1 ≤ |s| ≤ 105
'0' ≤ s[i] ≤ '9'
 */

class Solution {
    public String largestSwap(String s) {
        // code here
        int maxi = Integer.valueOf(s.charAt(s.length() - 1));
        int maxiIndex = s.length() - 1;
        int lefti = -1;
        int leftiIndex = -1;
        int n = s.length();
        for (int i = n - 2; i >= 0; i--) {
            if (Integer.valueOf(s.charAt(i)) > maxi) {
                maxi = Integer.valueOf(s.charAt(i));
                maxiIndex = i;
            } else if (Integer.valueOf(s.charAt(i)) < maxi) {
                lefti = Integer.valueOf(s.charAt(i));
                leftiIndex = i;
            }
        }
        if (lefti == -1) {
            return s;
        }
        int toSwapWithLeftiIndex = leftiIndex;
        for (int i = leftiIndex + 1; i < n; i++) {
            if (Integer.valueOf(s.charAt(toSwapWithLeftiIndex)) <= Integer.valueOf(s.charAt(i))) {
                toSwapWithLeftiIndex = i;
            }
        }
        // String ans = "";
        char[] ans = new char[n];
        for (int i = 0; i < n; i++) {
            if (i == leftiIndex) {
                ans[i] = s.charAt(toSwapWithLeftiIndex);
            } else if (i == toSwapWithLeftiIndex) {
                ans[i] = s.charAt(leftiIndex);
            } else {
                ans[i] = s.charAt(i);
            }
        }
        return new String(ans);
    }
}
