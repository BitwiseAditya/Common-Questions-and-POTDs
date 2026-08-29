/*Minimum Moves to Sort Permutation

Given an array arr[] containing each integer from 1 to n exactly once, 
where n is the size of arr, sort the array in ascending order.

In one operation, you can pick any element and move it either to the beginning
 or to the end of the array. Return the minimum number of operations required to 
 sort the array.

Examples:

Input: arr[] = [2, 1, 3]
Output: 1
Explanation: Move 1 to the beginning to obtain [1, 2, 3].
Input: arr[] = [4, 3, 1, 2]
Output: 2
Explanation: Move 3 to the end to obtain [4, 1, 2, 3], then move 4 to the end to obtain [1, 2, 3, 4].
Constraints:

arr.size() ≤ 105
1 ≤ arr[i] ≤ arr.size() */

public class MinMoveswToSortPermutation {
    public int minMoves(int[] arr) {
        // code here
        int n = arr.length;
        int largest = 0;
        int[] nums = new int[n + 1];
        for (int i = 0; i < n; i++) {
            if (nums[arr[i] - 1] != 0) {
                nums[arr[i]] = nums[arr[i] - 1] + 1;
            } else {
                nums[arr[i]] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            largest = Math.max(largest, nums[i]);
        }
        return n - largest;
    }
}
