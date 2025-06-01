/*
Kth element in Matrix
Difficulty: MediumAccuracy: 61.42%Submissions: 73K+Points: 4Average Time: 35m
Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
Output: 30
Explanation: 30 is the 7th smallest element.
Constraints:
1 <= n <= 500
1 <= mat[i][j] <= 10000
1 <= k <= n*n */

// C++ program to find the Kth smallest element
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of
// elements less than or equal to x
int countSmallerEqual(const vector<vector<int>> &matrix, int x)
{
    int n = matrix.size();
    int count = 0;
    int row = 0;
    int col = n - 1;

    // Traverse from the top-right corner
    while (row < n && col >= 0)
    {
        if (matrix[row][col] <= x)
        {

            // If current element is less than
            // or equal to x, all elements in this
            // row up to the current column are <= x
            count += (col + 1);
            row++;
        }
        else
        {

            // Move left in the matrix
            col--;
        }
    }

    return count;
}

// Function to find the kth smallest
// element in a sorted 2D matrix
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Count elements less than or equal to mid
        int count = countSmallerEqual(matrix, mid);

        if (count < k)
        {

            // If there are less than k elements
            // <= mid, the kth smallest is larger
            low = mid + 1;
        }
        else
        {

            // Otherwise, mid might be the answer,
            // but we need to check for smaller values
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix =
        {{10, 20, 30, 40},
         {15, 25, 35, 45},
         {24, 29, 37, 48},
         {32, 33, 39, 50}};
    int k = 3;
    int result = kthSmallest(matrix, k);

    cout << result << endl;

    return 0;
}
