/* Smallest distinct window

Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 8
Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks".
Constraints:
1 ≤ str.size() ≤ 105
str contains only lower-case english alphabets. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSubString(string &str)
    {
        // code here
        unordered_set<char> st;
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            st.insert(str[i]);
        }
        int required = st.size(); // number of unique characters in the string
        unordered_map<char, int> mp;
        int left = 0, right = 0, ans = INT_MAX;
        int uniqinmap = 0; // number of unique characters in the current window
        while (right < n)
        {
            mp[str[right]] += 1;
            if (mp[str[right]] == 1)
            {
                uniqinmap += 1;
            }
            while (uniqinmap == required)
            {
                ans = min(ans, right - left + 1);
                mp[str[left]] -= 1;
                if (mp[str[left]] == 0)
                {
                    uniqinmap--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};
