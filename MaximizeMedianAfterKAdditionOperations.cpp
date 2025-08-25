/* Maximize median after doing k addition operation

Given an array arr[] consisting of positive integers and an integer k. You are allowed to perform at most k operations, where in each operation, you can increment any one element of the array by 1. Determine the maximum possible median of the array that can be achieved after performing at most k such operations.

Note: The median of an array is defined as the middle element when the array (after sorting) has an odd size, or the average of the two middle elements when the array (after sorting) has an even size.

Examples:

Input: arr[] = [1, 3, 4, 5], k = 3
Output: 5
Explanation: We can add +2 to the second element and +1 to the third element to get the array [1, 5, 5, 5]. After sorting, the array remains [1, 5, 5, 5]. Since the length is even, the median is (5 + 5) / 2 = 5.
Input: arr[] = [1, 3, 6, 4, 2], k = 10
Output: 7
Explanation: After applying operations optimally, we can transform the array to [1, 3, 7, 7, 7] (one possible way). Sorted array becomes [1, 3, 7, 7, 7]. Since the length is odd, the median is the middle element 7.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i], k ≤ 109 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // check if we can make median at least 'target'
    // with <= k operations
    bool isPossible(vector<int> &arr, int target, int k)
    {
        int n = arr.size();

        if (n % 2 == 1)
        {
            // for odd-sized array, consider elements from
            // middle to end
            for (int i = n / 2; i < n; ++i)
            {
                if (arr[i] < target)
                    k -= (target - arr[i]);
                if (k < 0)
                    break;
            }
        }
        else
        {
            // for even-sized array, handle two middle
            // elements separately
            if (arr[n / 2] <= target)
            {
                k -= (target - arr[n / 2]);
                k -= (target - arr[n / 2 - 1]);
            }
            else
            {
                k -= (2 * target -
                      (arr[n / 2] + arr[n / 2 - 1]));
            }
            // process remaining elements to the right
            for (int i = n / 2 + 1; i < n; ++i)
            {
                if (arr[i] < target)
                    k -= (target - arr[i]);

                if (k < 0)
                    break;
            }
        }

        return k >= 0;
    }

    int maximizeMedian(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // compute initial median floor if even length
        int iniMedian = arr[n / 2];
        if (n % 2 == 0)
        {
            iniMedian += arr[n / 2 - 1];
            iniMedian /= 2;
        }

        int low = iniMedian, high = iniMedian + k;
        int bestMedian = iniMedian;

        // binary search to find maximum
        // achievable median
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isPossible(arr, mid, k))
            {
                bestMedian = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return bestMedian;
    }
};
