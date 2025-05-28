/* Find rectangle with corners as 1

Given an n x m binary matrix mat[][] containing only 0s and 1s,
determine if there exists a rectangle within the matrix such that
all four corners of the rectangle are 1. If such a rectangle exists,
return true; otherwise, return false.

Example:

Input: mat[][] =
[[1, 0, 0, 1, 0],
[0, 0, 1, 0, 1],
[0, 0, 0, 1, 0],
[1, 0, 1, 0, 1]]
Output: true
Explanation: Valid corners are at index (1,2), (1,4), (3,2), (3,4)
Input: mat[][] =
[[0, 0, 0],
[0, 0, 0],
[0, 0, 0]]
Output: false
Explanation: There are no valid corners.
Constraints:
1 <= n, m <= 200
0 <= mat[i] <= 1 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ValidCorner(vector<vector<int>> &mat)
    {
        // code here
        unordered_set<string> st;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                    continue;
                for (int col = j + 1; col < m; col++)
                {
                    if (mat[i][col] == 0)
                        continue;
                    string s = to_string(j) + "," + to_string(col);
                    if (mat[i][col] == 1)
                    {
                        if (st.find(s) != st.end())
                        {
                            return true;
                        }
                        st.insert(s);
                    }
                }
            }
        }
        return false;
    }
};
