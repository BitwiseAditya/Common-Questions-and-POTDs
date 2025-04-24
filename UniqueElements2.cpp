/* Unique Number II

Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

Examples:

Input: arr[] = [1, 2, 3, 2, 1, 4]
Output: [3, 4]
Explanation: 3 and 4 occur exactly once.
Input: arr[] = [2, 1, 3, 2]
Output: [1, 3]
Explanation: 1 and 3 occur exactly once.
Input: arr[] = [2, 1, 3, 3]
Output: [1, 2]
Explanation: 1 and 2 occur exactly once.
Constraints:
2 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 5 * 106
arr.size() is even */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        // Code here.
        int xorr = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ arr[i];
        }
        int firstSetBit = xorr & (-xorr);
        vector<int> ans(2, 0);
        for (int i = 0; i < n; i++)
        {
            if ((firstSetBit & arr[i]) == 0)
            {
                ans[0] = ans[0] ^ arr[i];
            }
            else if ((firstSetBit & arr[i]) != 0)
            {
                ans[1] = ans[1] ^ arr[i];
            }
        }
        if (ans[1] < ans[0])
        {
            swap(ans[0], ans[1]);
            // ans[0] = ans[0] ^ ans[1];
            // ans[1] = ans[0] ^ ans[1];
            // ans[0] = ans[0] ^ ans[1];
        }
        return ans;
    }
};
