/* Form the Largest Number

Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

Examples:

Input: arr[] = [3, 30, 34, 5, 9]
Output: 9534330
Explanation: Given numbers are [3, 30, 34, 5, 9], the arrangement [9, 5, 34, 3, 30] gives the largest value.
Input: arr[] = [54, 546, 548, 60]
Output: 6054854654
Explanation: Given numbers are [54, 546, 548, 60], the arrangement [60, 548, 546, 54] gives the largest value.
Input: arr[] = [3, 4, 6, 5, 9]
Output: 96543
Explanation: Given numbers are [3, 4, 6, 5, 9], the arrangement [9, 6, 5, 4, 3] gives the largest value.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLargest(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<string> s;
        for (int i = 0; i < n; i++)
        {
            s.push_back(to_string(arr[i]));
        }
        sort(s.begin(), s.end(), [](string &a, string &b)
             { return a + b > b + a; });
        string ans;
        for (int i = 0; i < n; i++)
        {
            ans += s[i];
        }
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};
