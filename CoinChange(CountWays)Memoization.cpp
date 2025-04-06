/* Coin Change(Count Ways)

    Given an integer array coins[] representing different denominations of currency and an integer sum,
    find the number of ways you can make sum by using different combinations from coins[].
    Note : Assume that you have an infinite supply of each type of coin.Therefore, you can use any coin as many times as you want.
    Answers are guaranteed to fit into a 32 - bit integer.

                                                                                                                                                                                                                                                                  Examples :

    Input : coins[] = [ 1, 2, 3 ],sum = 4 Output : 4
     Explanation : Four Possible ways are : [ 1, 1, 1, 1 ], [ 1, 1, 2 ], [ 2, 2 ], [ 1, 3 ].
    Input : coins[] = [ 2, 5, 3, 6 ], sum = 10 Output : 5
     Explanation : Five Possible ways are : [ 2, 2, 2, 2, 2 ], [ 2, 2, 3, 3 ], [ 2, 2, 6 ], [ 2, 3, 5 ] and [ 5, 5 ].
     Input : coins[] = [ 5, 10 ], sum = 3 Output : 0
     Explanation : Since all coin denominations are greater than sum, no combination can make the target sum.
     Constraints : 1 <= sum <= 103 1 <= coins[i] <= 104 1 <= coins.size() <= 103 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int f(int index, int target, int n, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;
        else if (index == n - 1 && target != 0)
        {
            if (target % coins[index] == 0)
                return 1;
            else
                return 0;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int pick = 0, notpick;
        if (target >= coins[index])
        {
            pick = f(index, target - coins[index], n, coins, dp);
        }
        notpick = f(index + 1, target, n, coins, dp);
        return dp[index][target] = (pick + notpick);
    }
    int count(vector<int> &coins, int sum)
    {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(0, sum, n, coins, dp);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends