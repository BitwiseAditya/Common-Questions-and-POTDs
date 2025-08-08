/* Longest Prefix Suffix

Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: s = "abab"
Output: 2
Explanation: The string "ab" is the longest prefix and suffix.
Input: s = "aabcdaabc"
Output: 4
Explanation: The string "aabc" is the longest prefix and suffix.
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest prefix and suffix.
Constraints:
1 ≤ s.size() ≤ 106
s contains only lowercase English alphabets. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buildLPS(string &s)
    {
        int n = s.length();
        vector<int> lps(n);
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < n)
        {
            if (s[len] == s[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int getLPSLength(string &s)
    {
        // code here
        // This question is a subpart of the KMP algorithm .
        vector<int> lps = buildLPS(s);
        return lps[s.length() - 1];
    }
};