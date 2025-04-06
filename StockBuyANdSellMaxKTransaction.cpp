/* Stock Buy and Sell – Max K Transactions Allowed
    In the stock market,a person buys a stock and sells it on some future date.
    You are given an array prices[] representing stock prices on different days
    and a positive integer k, find out the maximum profit a person can make in
    at - most k transactions.

    A transaction consists of buying and subsequently selling a stock and new
    transaction can start only when the previous transaction has been completed.

    Examples :

    Input : prices[] = [ 10, 22, 5, 80 ],k = 2 Output : 87 Explaination : 1st transaction : Buy at 10 and sell at 22. 2nd transaction : Buy at 5 and sell at 80. Total Profit will be 12 + 75 = 87. Input : prices[] = [ 20, 580, 420, 900 ], k = 3 Output : 1040 Explaination : 1st transaction : Buy at 20 and sell at 580. 2nd transaction : Buy at 420 and sell at 900. Total Profit will be 560 + 480 = 1040. Input : prices[] = [ 100, 90, 80, 50, 25 ], k = 1 Output : 0 Explaination : Selling price is decreasing continuously leading to loss.So seller cannot have any profit.Constraints : 1 ≤ prices.size() ≤ 103 1 ≤ k ≤ 200 1 ≤ prices[i] ≤ 103
    */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int f(int index, int investment, int transaction, int n, vector<int> &prices, vector<vector<vector<int>>> &dp, int k)
    {
        if (index == n || transaction >= k)
        {
            if (investment != 0)
                return -1e9;
            else
                return 0;
        }
        if (dp[index][transaction][investment] != -1)
        {
            return dp[index][transaction][investment];
        }
        if (investment != 0)
        {
            int sell = prices[index] + f(index + 1, 0, transaction + 1, n, prices, dp, k);
            int notsell = f(index + 1, 1, transaction, n, prices, dp, k);
            return dp[index][transaction][investment] = max(sell, notsell);
        }
        else
        {
            int pick = INT_MIN;
            if (transaction < k)
            {
                pick = -prices[index] + f(index + 1, 1, transaction, n, prices, dp, k);
            }
            int notpick = f(index + 1, 0, transaction, n, prices, dp, k);
            return dp[index][transaction][investment] = max(pick, notpick);
        }
    }
    int maxProfit(vector<int> &prices, int k)
    {
        // code here
        // Write your code here.
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2, -1)));
        int ans = f(0, 0, 0, n, prices, dp, k);
        if (ans < 0)
            return 0;
        else
            return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num)
        {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
