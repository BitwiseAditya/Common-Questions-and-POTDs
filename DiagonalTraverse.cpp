/* 498. Diagonal Traverse

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.



Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        ans.reserve(n * m);

        int row = 0, col = 0;
        int dir = 1; // 1 = up-right, -1 = down-left

        while (ans.size() < n * m)
        {
            ans.push_back(mat[row][col]);

            if (dir == 1)
            { // going up-right
                if (col == m - 1)
                { // right boundary
                    row++;
                    dir = -1;
                }
                else if (row == 0)
                { // top boundary
                    col++;
                    dir = -1;
                }
                else
                {
                    row--;
                    col++;
                }
            }
            else
            { // going down-left
                if (row == n - 1)
                { // bottom boundary
                    col++;
                    dir = 1;
                }
                else if (col == 0)
                { // left boundary
                    row++;
                    dir = 1;
                }
                else
                {
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};
