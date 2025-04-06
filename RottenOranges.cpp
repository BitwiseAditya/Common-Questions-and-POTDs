/* Rotten Oranges

Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

Examples:

Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
Output: 1
Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
Input: mat[][] = [[2, 2, 0, 1]]
Output: -1
Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).
Input: mat[][] = [[2, 2, 2], [0, 2, 0]]
Output: 0
Explanation: There is no fresh orange.
Constraints:
1 ≤ mat.size() ≤ 500
1 ≤ mat[0].size() ≤ 500
mat[i][j] = {0, 1, 2}  */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &mat)
    {
        // Code here
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    visited[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }
        while (!q.empty())
        {
            int count = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            ans = max(ans, count);
            q.pop();
            if (r - 1 >= 0 && mat[r - 1][c] == 1 && visited[r - 1][c] == false)
            {
                visited[r - 1][c] = true;
                mat[r - 1][c] = 2;
                q.push({count + 1, {r - 1, c}});
            }
            if (r + 1 < n && mat[r + 1][c] == 1 && visited[r + 1][c] == false)
            {
                visited[r + 1][c] = true;
                mat[r + 1][c] = 2;
                q.push({count + 1, {r + 1, c}});
            }
            if (c - 1 >= 0 && mat[r][c - 1] == 1 && visited[r][c - 1] == false)
            {
                visited[r][c - 1] = true;
                mat[r][c - 1] = 2;
                q.push({count + 1, {r, c - 1}});
            }
            if (c + 1 < m && mat[r][c + 1] == 1 && visited[r][c + 1] == false)
            {
                visited[r][c + 1] = true;
                mat[r][c + 1] = 2;
                q.push({count + 1, {r, c + 1}});
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
