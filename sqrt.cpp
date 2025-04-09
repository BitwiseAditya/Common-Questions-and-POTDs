/* Square Root
Difficulty: EasyAccuracy: 54.03%Submissions: 316K+Points: 2Average Time: 20m
Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
Input: n = 1
Output: 1
Constraints:
1 ≤ n ≤  3 x 104 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution
{
public:
    int floorSqrt(int n)
    {
        // Your code goes here
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid * mid == n)
                return mid;
            else if (mid * mid > n)
                r = mid - 1;
            else if (mid * mid < n)
                l = mid + 1;
        }
        return r;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
