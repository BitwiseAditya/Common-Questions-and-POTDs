/* Stock span problem

The stock span problem is a financial problem where we have a series of daily price quotes
 for a stock and we need to calculate the span of stock price for all days. The span arr[i]
 of the stocks price on a given day i is defined as the maximum number of consecutive days
 just before the given day, for which the price of the stock on the given day is less than
 or equal to its price on the current day.

Examples:

Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more elements behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 60 is greater than equal to 60 and smaller than 80 so the span is 1, 70 is greater than equal to 60,70 and smaller than 80 so the span is 2 and so on.  Hence the output will be 1 1 1 2 1 4 6.
Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more elements behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4,5 and smaller than 10 so the span is 2,  and so on. Hence the output will be 1 1 2 4 5 1.
Constraints:
1 ≤ arr.size()≤ 105
1 ≤ arr[i] ≤ 105 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        // write code here
        stack<int> s;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                ans[i] = i + 1;
                s.push(i);
            }
            else
            {
                while (!s.empty() && arr[s.top()] <= arr[i])
                {
                    s.pop();
                }
                if (!s.empty())
                {
                    ans[i] = i - s.top();
                }
                else
                {
                    ans[i] = i + 1;
                }
                s.push(i);
            }
        }
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
