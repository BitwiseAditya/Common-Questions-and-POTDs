/* Longest Increasing Subsequence

    Given an array arr[] of non - negative integers,
    the task is to find the length of the Longest Strictly Increasing Subsequence(LIS).

    A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

    Examples :

    Input : arr[] = [ 5, 8, 3, 7, 9, 1 ] Output : 3 Explanation : The longest strictly increasing subsequence could be[5, 7, 9],
            which has a length of 3. Input : arr[] = [ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 ] Output : 6 Explanation : One of the possible longest strictly increasing subsequences is[0, 2, 6, 9, 13, 15], which has a length of 6. Input : arr[] = [ 3, 10, 2, 1, 20 ] Output : 3 Explanation : The longest strictly increasing subsequence could be[3, 10, 20], which has a length of 3. Constraints : 1 ≤ arr.size() ≤ 103 0 ≤ arr[i] ≤ 106
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int f(int currIndex, int prevIndex, vector<int> &arr, int n, vector<vector<int>> &dp)
    {
        if (currIndex == n)
            return 0;

        if (dp[currIndex][prevIndex + 1] != -1)
            return dp[currIndex][prevIndex + 1];

        int pick = INT_MIN, notpick = INT_MIN;
        notpick = 0 + f(currIndex + 1, prevIndex, arr, n, dp);
        if (prevIndex == -1 || arr[currIndex] > arr[prevIndex])
        {
            pick = 1 + f(currIndex + 1, currIndex, arr, n, dp);
        }
        return dp[currIndex][prevIndex + 1] = max(pick, notpick);
    }
    int lis(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, arr, n, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--)
    {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
