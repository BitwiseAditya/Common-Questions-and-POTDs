/*Anagram Palindrome

Given a string s, determine whether its characters can be rearranged to form a palindrome. Return true if it is possible to rearrange the string into a palindrome; otherwise, return false.

Examples

Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba" 
Input: s = "geeksogeeks"
Output: true
Explanation: The characters of the string can be rearranged to form the palindrome "geeksoskeeg".
Input: s = "geeksforgeeks"
Output: false
Explanation: The given string can't be converted into a palindrome.
Constraints:
1 ≤ s.length ≤ 106
s consists of only lowercase English letters. */

public class AnagramPalindrome {
    boolean canFormPalindrome(String s) {
        // code here
        int n = s.length();
        int xor = 0;
        for (int i = 0; i < n; i++) {
            int bit = s.charAt(i) - 'a';
            xor = xor ^ (1 << bit);
        }
        if ((n & 1) == 0) {
            if (xor == 0)
                return true;
            else
                return false;
        } else {
            if ((xor & (xor - 1)) == 0) {
                return true;
            } else {
                return false;
            }
        }
    }
}
