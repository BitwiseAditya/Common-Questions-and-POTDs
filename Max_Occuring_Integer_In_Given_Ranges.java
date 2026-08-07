/*Maximum occurring integer in given ranges

3 Feb, 2026
Given two arrays l[] and r[] of size n where l[i] and r[i] denotes a range of numbers, the task is to find the maximum occurring integer in all the ranges. If more than one such integer exists, print the smallest one. 

Examples: 

Input: l[] = [1, 2, 4, 3], r[] = [6, 4, 8, 5]
Output: 4
Explanation: The ranges are [1, 6], [2, 4], [4, 8], and [3, 5]. The maximum occurring integer is 4.

Input: l[] = [1, 5, 9, 13, 21], r[] = [15, 8, 12, 20, 30]
Output: 5
Explanation: Numbers having maximum occurrence i.e., 2 are 
5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15. The smallest number among all are 5. */

public class Max_Occuring_Integer_In_Given_Ranges {
    /*
     * The idea is to use a difference array technique to efficiently handle range
     * updates. Instead of individually incrementing each number in a range, we mark
     * the start and end of ranges. For each range [l[i], r[i]], we increment the
     * value at index l[i] and decrement the value at index r[i]+1. By calculating
     * the prefix sum, we can determine the frequency of each number across all
     * ranges.
     */

    static int maxOccured(int[] l, int[] r) {
        int n = l.length;

        // Find maximum value in ranges
        int maxi = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++)
            maxi = Math.max(maxi, r[i]);

        int[] diff = new int[maxi + 2];

        // Mark the starting and ending of ranges
        for (int i = 0; i < n; i++) {

            // Increment at start of range
            diff[l[i]]++;

            // Decrement at end+1 of range
            diff[r[i] + 1]--;
        }

        // Calculate the prefix sum and find maximum frequency
        int maxFreq = diff[0];
        int result = 0;

        for (int i = 1; i <= maxi; i++) {

            // Calculate prefix sum
            diff[i] += diff[i - 1];

            // Update result if current frequency is higher
            if (diff[i] > maxFreq) {
                maxFreq = diff[i];
                result = i;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] l = { 1, 2, 4, 3 };
        int[] r = { 6, 4, 8, 5 };
        System.out.println(maxOccured(l, r));
    }
}
