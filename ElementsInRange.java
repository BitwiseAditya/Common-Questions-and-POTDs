/*Elements in the Range

Given an array arr[] containing distinct positive integers, and two integers start and end defining a range. Determine if the array contains all elements within inclusive range [start, end].

Note: If the array contains all elements in the given range return true otherwise return false.

Examples :

Input: start = 2, end = 5, arr[] =  [1, 4, 5, 2, 7, 8, 3]
Output: true
Explanation: All integers within the range [2, 5] are 2, 3, 4, and 5, and all of them are present in the array. Therefore, the answer is true for this test case.
Input: start = 2, end = 6, arr[] = [1, 4, 5, 2, 7, 8, 3]
Output: false
Explanation: The array does not contain 6; hence, it does not contain all the elements in the range [2, 6]. Therefore, the output is false.
Constraints:
1 ≤ arr.size(), arr[i] ≤ 105
1 ≤ start ≤ end ≤ 105 */

class Solution {
    public boolean checkElements(int start, int end, int[] arr) {
        // code here
        int n = arr.length;
        int range = end - start + 1;
        for (int i = 0; i < n; i++) {
            if (Math.abs(arr[i]) >= start && Math.abs(arr[i]) <= end) {
                int index = Math.abs(arr[i]) - start;
                if (index < n && arr[index] > 0)
                    arr[index] = -1 * arr[index];
            }
        }
        for (int i = 0; i < range; i++) {
            if (arr[i] > 0)
                return false;
        }
        return true;
    }
}
