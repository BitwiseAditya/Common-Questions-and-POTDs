/* Pascal Triangle

Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.



Examples:

Input: n = 4
Output: [1, 3, 3, 1]
Explanation: 4th row of pascal's triangle is [1, 3, 3, 1].
Input: n = 5
Output: [1, 4, 6, 4, 1]
Explanation: 5th row of pascal's triangle is [1, 4, 6, 4, 1].
Input: n = 1
Output: [1]
Explanation: 1st row of pascal's triangle is [1].
Constraints:
1 ≤ n ≤ 20 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // using formula nCr = (nCr-1 * (n-r+1))/r
    vector<int> nthRowOfPascalTriangle(int n)
    {
        // code here
        vector<int> nth_row;
        n--;
        int ncr_prev = 1;
        nth_row.push_back(ncr_prev);
        for (int i = 1; i <= n; i++)
        {
            int ncr = (ncr_prev * (n - i + 1)) / i;
            nth_row.push_back(ncr);
            ncr_prev = ncr;
        }
        return nth_row;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
