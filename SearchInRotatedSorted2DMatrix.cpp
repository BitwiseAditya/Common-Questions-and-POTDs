/* Search in fully rotated sorted 2D matrix

You are given a 2D matrix mat[][] of size n x m that was initially filled in the following manner:


Each row is sorted in increasing order from left to right.
The first element of every row is greater than the last element of the previous row.

This implies that if the matrix is flattened row-wise, it forms a strictly sorted 1D array.
Later, this sorted 1D array was rotated at some unknown pivot. The rotated array was then written back into the matrix row-wise to form the current matrix.


Given such a matrix mat[][] and an integer x, determine whether x exists in the matrix.


Examples:

Input: x = 3,
mat[][] = [[7, 8, 9, 10],
          [11, 12, 13, 1],
          [2, 3, 4, 5]]
Output: true
Explanation: 3 is located at the 3rd row and 2nd column.
Input: x = 10,
mat[][] = [[6, 7, 8],
          [9, 1, 2],
          [3, 4, 5]]
Output: false
Explanation: The value 10 does not exist in the matrix.
Constraint:
1 ≤ n × m ≤ 105
1 ≤ mat[i][j], x ≤ 106 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int left = 0;
        int right = m * n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int r0 = mid / m;
            int c0 = mid % m;
            int r1 = right / m;
            int c1 = right % m;
            int r2 = left / m;
            int c2 = left % m;
            if (mat[r0][c0] == x)
            {
                return true;
            }
            else if (mat[r0][c0] <= mat[r1][c1])
            {
                if (x > mat[r0][c0] && x <= mat[r1][c1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if (x < mat[r0][c0] && x >= mat[r2][c2])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
