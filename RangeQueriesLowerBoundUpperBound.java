/* Elements in range [a, b]

Given an unsorted array arr[] and a 2D array queries[][] of size q, where each query is in the form of [a, b]. For each query, count how many elements in arr[] lie within the range [a, b], i.e., elements satisfying a ≤ x ≤ b.

Return the results for all queries as a list of integers, where each integer corresponds to the count of elements in the respective query range.

Examples:

Input: arr[] = [1, 4, 2, 8, 5], queries[][] = [[1, 4], [3, 6], [0, 10]]
Output: [3, 2, 5]
Explanation: Query [1, 4]: Elements in range → [1, 4, 2] → Count = 3
Query [3, 6]: Elements in range → [4, 5] → Count = 2
Query [0, 10]: All elements → [1, 4, 2, 8, 5] → Count = 5
Input: arr[] = [10, 20, 30, 40, 50], queries[][] = [[5, 15], [25, 45], [10, 50]]
Output: [1, 2, 5]
Explanation: Query [5, 15]: Elements in range → [10] → Count = 1
Query [25, 45]: Elements in range → [30, 40] → Count = 2
Query [10, 50]: Elements in range → [10, 20, 30, 40, 50] → Count = 5
Constraints:
1 ≤ arr.size(), q ≤ 105
0 ≤ arr[i] ≤ 106
0 ≤ queries[i][0] ≤ queries[i][1] ≤ 106 */

package GFG_POTD;

import java.util.ArrayList;
import java.util.Arrays;

public class RangeQueriesLowerBoundUpperBound {
    public static ArrayList<Integer> cntInRange(int[] arr,
            int[][] queries) {
        ArrayList<Integer> result = new ArrayList<>();

        // sort the array once
        Arrays.sort(arr);

        for (int[] query : queries) {
            int a = query[0];
            int b = query[1];

            // find the first index where element >= a
            int left = lowerBound(arr, a);

            // find the first index where element > b
            int right = upperBound(arr, b);

            // number of elements in [a, b] is right - left
            result.add(right - left);
        }

        return result;
    }

    // binary search for first index with element >= target
    private static int lowerBound(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    // binary search for first index with element > target
    private static int upperBound(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 4, 2, 8, 5 };
        int[][] queries = { { 1, 4 }, { 3, 6 }, { 0, 10 } };
        ArrayList<Integer> res = cntInRange(arr, queries);
        for (int count : res) {
            System.out.print(count + " ");
        }
        System.out.println();
    }

}

/* Can also be done in following way : */
/*
 * public ArrayList<Integer> cntInRange(int[] arr,
 * int[][] queries) {
 * ArrayList<Integer> result = new ArrayList<>();
 * 
 * // sort the array once
 * Arrays.sort(arr);
 * 
 * for (int[] query : queries) {
 * int a = query[0];
 * int b = query[1];
 * 
 * 
 * int left = lowerBound(arr, a);
 * 
 * 
 * int right = upperBound(arr, b);
 * 
 * if(right < 0 || right >= arr.length || left < 0 || left >= arr.length){
 * result.add(0);
 * }
 * else{
 * result.add(right - left + 1);
 * }
 * }
 * 
 * return result;
 * }
 * 
 * 
 * private int lowerBound(int[] arr, int target) {
 * int low = 0, high = arr.length-1;
 * int lb = -1;
 * while (low <= high) {
 * int mid = (low + high) / 2;
 * if (arr[mid] >= target){
 * lb = mid;
 * high = mid - 1;
 * }
 * else
 * low = mid + 1;
 * }
 * return lb;
 * }
 * 
 * 
 * private int upperBound(int[] arr, int target) {
 * int low = 0, high = arr.length-1;
 * int lb = -1;
 * while (low <= high) {
 * int mid = (low + high) / 2;
 * if (arr[mid] <= target){
 * lb = mid;
 * low = mid + 1;
 * }
 * else
 * high = mid - 1;
 * }
 * return lb;
 * }
 * 
 */
