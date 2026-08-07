/*Subarrays with Sum in Range

Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r] (inclusive).

A subarray is a contiguous sequence of elements within the array.

Examples:

Input: l = 3, r = 8, arr[] = [1, 4, 6]
Output: 3
Explanation: The subarrays are [1,4], [4] and [6]. Therefore answer for this test case is 3.
Input: l = 4, r = 13, arr[] = [2, 3, 5, 8]
Output: 6
Explanation: The subarrays are [2, 3], [2, 3, 5], [3, 5], [5], [5, 8] and [8]. 
Therefore answer for this test case is 6.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ l ≤ r ≤ 109 */

public class Subarrays_With_Sum_In_Range {
    public int countSubarr(int[] arr, int k) {
        int sum = arr[0];
        int left = 0, right = 0;
        int n = arr.length;
        int count = 0;
        while (right <= n && left < n) {
            while (sum <= k && right < n) {
                right++;
                if (right < n)
                    sum += arr[right];
            }
            count += (right - 1 - left + 1);
            sum -= arr[left];
            left++;
        }
        return count;
    }

    public int countSubarray(int[] arr, int l, int r) {
        // code here
        int a = countSubarr(arr, r);
        int b = countSubarr(arr, l - 1);
        return (a - b);
    }
}
