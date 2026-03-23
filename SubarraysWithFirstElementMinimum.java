/*Subarrays with First Element Minimum

You are given an integer array arr[ ]. Your task is to count the number of subarrays where the first element is the minimum element of that subarray.

Note: A subarray is valid if its first element is not greater than any other element in that subarray.

Examples:

Input: arr[] = [1, 2, 1]
Output: 5
Explanation:
All possible subarrays are:
[1], [1, 2], [1, 2, 1], [2], [2, 1], [1]
Valid subarrays are:
[1], [1, 2], [1, 2, 1], [2], [1] -> total 5
Input: arr[] = [1, 3, 5, 2]
Output: 8
Explanation:
Valid subarrays are: [1], [1, 3], [1, 3, 5], [1, 3, 5, 2], [3], [3, 5], [5], [2] -> total 8
Constraints:
1 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 105

 */

import java.util.Stack;

public class SubarraysWithFirstElementMinimum {
    public void nextSmallerElement(int[] arr, int[] nse) {
        int n = arr.length;
        Stack<Integer> s = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!(s.isEmpty()) && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            if (s.isEmpty()) {
                nse[i] = n;
            } else {
                nse[i] = s.peek();
            }
            s.push(i);
        }
        return;
    }

    public int countSubarrays(int[] arr) {
        // code here
        int n = arr.length;
        int[] nse = new int[n];
        nextSmallerElement(arr, nse);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ((nse[i] - 1) - i + 1);
        }
        return ans;
    }

}
