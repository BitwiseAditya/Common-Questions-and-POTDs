/* Coin Change(Minimum Coins)
             You are given an array coins[],
    where each element represents a coin of a different denomination, and a target value sum.You have an unlimited supply of each coin type{coins1, coins2, ..., coinsm}.
    Your task is to determine the minimum number of coins needed to obtain the target sum.If it is not possible to form the sum using the given coins,
    return -1.

     Examples :

    Input : coins[] = [ 25, 10, 5 ],
    sum = 30 Output : 2 Explanation : Minimum 2 coins needed, 25 and 5
    Input : coins[] = [ 9, 6, 5, 1 ], sum = 19 Output : 3 Explanation : 19 = 9 + 9 + 1
    Input : coins[] = [ 5, 1 ], sum = 0 Output : 0 Explanation : For 0 sum, we do not need a coin
    Input : coins[] = [ 4, 6, 2 ], sum = 5 Output : -1 Explanation : Not possible to make the given sum. */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    int f(int index, int target, vector<int> &coins, int n, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 0; // If target is 0, no coins are needed
        if (index == n)
            return INT_MAX; // If no coins left, return large value

        if (dp[index][target] != -1)
            return dp[index][target];

        int pick = INT_MAX, notpick;
        if (target >= coins[index])
        {
            int res = f(index, target - coins[index], coins, n, dp);
            if (res != INT_MAX)
                pick = 1 + res; // Add 1 since we picked a coin
        }
        notpick = f(index + 1, target, coins, n, dp);

        return dp[index][target] = min(pick, notpick);
    }
    int minCoins(vector<int> &coins, int sum)
    {
        // code here
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int ans = f(0, sum, coins, n, dp);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
