/* Maximize Number of 1's

Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

Examples:

Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.
Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.
Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ arr.size()
0 ≤ arr[i] ≤ 1 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &arr, int k, int consecutiveOnes)
    {
        int n = arr.size();
        int countZeros = 0;
        for (int i = 0; i < consecutiveOnes; i++)
        {
            if (arr[i] == 0)
                countZeros++;
        }
        if (countZeros <= k)
            return true;
        int left = 1;
        if (arr[0] == 0)
            countZeros--;
        int right = consecutiveOnes;
        if (right < n && arr[right] == 0)
            countZeros++;
        while (left < n && right < n)
        {
            if (countZeros <= k)
                return true;
            if (arr[left] == 0)
                countZeros--;
            left++;
            if (right + 1 < n && arr[right + 1] == 0)
                countZeros++;
            right++;
        }
        return false;
    }
    int maxOnes(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        int left = 0;
        int right = n;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(arr, k, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
