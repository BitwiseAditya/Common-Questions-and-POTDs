/*
 * Sum of subarray minimums

 * Given an array arr[] of positive integers, find the total sum of the minimum
 * elements of every possible subarrays.
 * 
 * Note: It is guaranteed that the total sum will fit within a 32-bit unsigned
 * integer.
 * 
 * Examples:
 * 
 * Input: arr[] = [10, 20]
 * Output: 40
 * Explanation: Subarrays are [10], [20], [10, 20]. Minimums are 10, 20, 10.
 * Sum of all these is 40.
 * Input: arr[] = [1, 2, 3, 4]
 * Output: 20
 * Explanation: Subarrays are [1], [2], [3], [4], [1, 2], [1, 2, 3], [1, 2, 3,
 * 4], [2, 3], [2, 3, 4], [3, 4]. Minimums are 1, 2, 3, 4, 1, 1, 1, 2, 2, 3.
 * Sum of all these is 20.
 * Constraints:
 * 1 ≤ arr.size() ≤ 3*104
 * 1 ≤ arr[i] ≤ 103
 * 
 * do it in O(n) time complexity.
 */

import java.util.Stack;

class SumOfSubarrayMinimums {
    void nextSmallerElement(int[] arr, int[] nse) {
        Stack<Integer> st = new Stack<Integer>();
        int n = arr.length;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] > arr[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                nse[i] = n;
            } else {
                nse[i] = st.peek();
            }
            st.push(i);
        }
        return;
    }

    void previousSmallerElement(int[] arr, int[] pse) {
        Stack<Integer> st = new Stack<Integer>();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] >= arr[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.peek();
            }
            st.push(i);
        }
        return;
    }

    public int sumSubMins(int[] arr) {
        // code here
        int n = arr.length;
        int[] nse = new int[n];
        int[] pse = new int[n];
        nextSmallerElement(arr, nse);
        previousSmallerElement(arr, pse);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            /*
             * int l = pse[i] + 1;
             * int r = nse[i] - 1;
             * ans += (((r-l+1)*(r-l+1+1))/2)*(arr[i]);
             */
            ans += ((i - pse[i]) * (nse[i] - i) * arr[i]);
        }
        return ans;
    }
}
