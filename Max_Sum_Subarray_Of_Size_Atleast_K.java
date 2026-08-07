/*Max Sum Subarray of Size at least K

Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length greater than or equal to k.

Examples:

Input: arr[] = [1, -2, 2, -3], k = 3
Output: 1
Explanation: The sub-array of length at least 3 that produces greatest sum is [1, -2, 2]
Input: arr[] = [1, 1, 1, 1, 1, 1], k = 2
Output: 6
Explanation: The sub-array of length at least 2 that produces greatest sum is [1, 1, 1, 1, 1, 1]
Input: arr[] = [-4, -2, 1, -3], k = 2
Output: -1
Explanation: The sub-array of length at least 2 that produces greatest sum is [-2, 1]

Constraints:

1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
1 ≤ k ≤ arr.size() */

public class Max_Sum_Subarray_Of_Size_Atleast_K {
    public int maxSumWithK(int[] arr, int k) {
        // code here
        int n = arr.length;
        int[] maxi = new int[n];
        int curr = arr[0];
        maxi[0] = arr[0];
        for (int i = 1; i < n; i++) {
            curr = Math.max(arr[i], curr + arr[i]);
            maxi[i] = curr;
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int res = sum;
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i - k];
            res = Math.max(res, sum);
            res = Math.max(res, sum + maxi[i - k]);
        }
        return res;
    }
}
