/* Longest Substring with K Uniques

Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: "cbebebe" is the longest substring with 3 distinct characters.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: "aabaaab" is the longest substring with 2 distinct characters.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
All characters are lowercase letters

 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        // your code here
        unordered_set<char> st;
        unordered_map<char, int> mp;
        unordered_set<char> check(s.begin(), s.end());
        if (check.size() < k)
            return -1;
        check.clear();
        int ans = 0;
        int left = 0, right = 0;
        int n = s.length();
        int uniqinwindow = 0;
        while (right < n)
        {
            st.insert(s[right]);
            mp[s[right]] += 1;
            while (st.size() > k)
            {
                mp[s[left]] -= 1;
                if (mp[s[left]] == 0)
                    st.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
