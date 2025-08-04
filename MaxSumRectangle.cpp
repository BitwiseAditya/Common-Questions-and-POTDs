/*
Maximum sum Rectangle
Difficulty: HardAccuracy: 49.78%Submissions: 45K+Points: 8
Given a 2D matrix mat[][] with dimensions n×m. Find the maximum possible sum of any submatrix within the given matrix.

Examples:

Input: mat[][] = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
Output: 29
Explanation: The matrix is as follows and the green rectangle denotes the maximum sum rectangle which is equal to 29.

Input: mat[][] = [[-1, -2], [-3, -4]]
Output: -1
Explanation: Taking only the first cell is the optimal choice.
Constraints:
1 ≤ n, m ≤ 300
-1000 ≤ mat[i][j] ≤ 1000


*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kadaneMaxSumSubarray(vector<int> &temp)
    {
        int currsum = temp[0];
        int ans = temp[0];
        int n = temp.size();
        for (int i = 1; i < n; i++)
        {
            currsum = max(temp[i], currsum + temp[i]);
            ans = max(ans, currsum);
        }
        return ans;
    }
    int maxRectSum(vector<vector<int>> &mat)
    {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        int ans = -1e9;
        for (int i = 0; i < cols; i++)
        {
            vector<int> temp(rows, 0);
            for (int j = i; j < cols; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    temp[k] += mat[k][j];
                }
                ans = max(ans, kadaneMaxSumSubarray(temp));
            }
        }
        return ans;
    }
};
