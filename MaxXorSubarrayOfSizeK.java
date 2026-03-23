/*
 * Max Xor Subarray of size K
 * 
 * Given an array of integers arr[] and a number k. Return the maximum xor of a
 * subarray of size k.
 * 
 * Note: A subarray is a contiguous part of any given array.
 * 
 * Examples:
 * 
 * Input: arr[] = [2, 5, 8, 1, 1, 3], k = 3
 * Output: 15
 * Explanation: arr[0] ^ arr[1] ^ arr[2] = 15, which is maximum.
 * Input: arr[] = [1, 2, 4, 5, 6] , k = 2
 * Output: 6
 * Explanation: arr[1] ^ arr[2] = 6, which is maximum.
 * Constraints:
 * 1 ≤ arr.size() ≤ 106
 * 0 ≤ arr[i] ≤ 106
 * 1 ≤ k ≤ arr.size()
 */

import java.util.*;

class MaxXorSubarrayOfSizeK {
    public int maxSubarrayXOR(int[] arr, int k) {
        // code here
        int n = arr.length;
        int[] prefix_xor = new int[n + 1];
        Arrays.fill(prefix_xor, 0);
        int running_xor = 0;
        for (int i = 0; i < n; i++) {
            running_xor = running_xor ^ arr[i];
            prefix_xor[i + 1] = running_xor;
        }
        int i = 0, j = k - 1;
        int ans = Integer.MIN_VALUE;
        while (i < n && j < n) {
            int temp = prefix_xor[j + 1] ^ prefix_xor[i];
            ans = Integer.max(ans, temp);
            i++;
            j++;
        }
        return ans;
    }
}
