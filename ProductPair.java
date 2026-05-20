/*Product Pair

Given an integer array arr[] and an integer target, determine whether there exists a pair of elements in the array whose product is equal to target.

Return true if such a pair exists; otherwise, return false.

Examples:

Input: arr[] = [10, 20, 9, 40], target = 400
Output: true
Explanation: As 10 * 40 = 400, the answer is true.
Input: arr[] = [-10, 20, 9, -40], target = 30
Output: false
Explanation: No pair exists with product 30.
Input: arr[] = [-10, 0, 9, -40], target = 0
Output: true
Explanation: As -10 * 0 = 0, the answer is true.
Constraints:
2 ≤ arr.size ≤ 105
-108 ≤ arr[i] ≤ 108
-1018 ≤ target ≤ 1018 */

import java.util.HashSet;
import java.util.Set;

public class ProductPair {
    public boolean isProduct(int[] arr, long target) {
        // code here
        Set<Long> st = new HashSet<>();
        for (int num : arr) {
            if (target == 0L && num == 0) {
                return true;
            }
            if (num == 0) {
                st.add((long) num);
                continue;
            }
            if (target % num == 0) {
                long temp = target / num;
                if (st.contains(temp)) {
                    return true;
                }
            }
            st.add((long) num);
        }
        return false;
    }
}
