/*Pairs with Less Than K Diff

Given an array arr[] of positive integers and an integer k, find the total number of pairs of elements that have an absolute difference strictly less than k.

Note:  Pair (i, j) is considered the same as (j, i).

Examples:

Input : arr[] = [1, 10, 4, 2], k = 3
Output : 2
Explanation: We have an array arr[] = [1, 10, 4, 2] and k = 3 We can make only two pairs with a difference of less than 3. (1, 2) and (4, 2). So, the answer is 2.
Input : arr[] = [2, 3, 4], k = 5
Output : 3
Explanation:  For the given array arr[] = [2, 3, 4] and k = 5, there are 3 valid pairs where the absolute difference between the pair's elements is less than 5. These pairs are (2, 3), (2, 4), and (3, 4). Hence, the output is 3.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105 */

import java.util.Arrays;

public class Pairs_With_Less_Than_K_Difference {
    public static int upperBound(int left, int right, int[] arr, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }

    public static int countPairs(int arr[], int k) {
        // code here
        Arrays.sort(arr);
        int count = 0;
        int n = arr.length;
        for (int i = 0; i <= (n - 2); i++) {
            int index = upperBound(i + 1, n - 1, arr, (k + arr[i]));
            if (index == i + 1) {
                if (Math.abs(arr[i] - arr[i + 1]) < k)
                    count++;
            } else {
                if (Math.abs(arr[i] - arr[index]) < k) {
                    count += (index - i);
                } else {
                    count += (index - i - 1);
                }
            }
        }
        return count;
    }
}
