/* Minimum Jumps
     You are given an array arr[] of non - negative numbers.
     Each number tells you the maximum number of steps you can
     jump forward from that position.

     For example :
     If arr[i] = 3,
    you can jump to index i + 1, i + 2, or i + 3 from position i.
    If arr[i] = 0, you cannot jump forward from that position.
    Your task is to find the minimum number of jumps needed to move from the
    first position in the array to the last position.

    Note : Return -
    1 if you can't reach the end of the array.
    Examples :

    Input : arr[] = [ 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 ] Output : 3 Explanation : First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9,
       and from here we will jump to the last.Input : arr = [ 1, 4, 3, 2, 6, 7 ] Output : 2 Explanation : First we jump from the 1st to 2nd element and then jump to the last element.Input : arr = [ 0, 10, 20 ] Output : -1 Explanation : We cannot go anywhere from the 1st element.Constraints : 2 ≤ arr.size() ≤ 104 0 ≤ arr[i] ≤ 104
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int f(int index, int n, vector<int> &arr, vector<int> &dp)
    {
        if (index >= n)
        {
            return INT_MAX;
        }
        if (index == n - 1)
        {
            return 0;
        }
        if (arr[index] == 0 && index != (n - 1))
        {
            return INT_MAX;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= arr[index]; i++)
        {
            if (index + i <= n)
            {
                int jump = f(index + i, n, arr, dp);
                if (jump != INT_MAX)
                {
                    ans = min(ans, jump + 1);
                }
            }
        }
        return dp[index] = ans;
    }
    int minJumps(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        int temp = f(0, n, arr, dp);
        if (temp == INT_MAX)
            return -1;
        else
            return temp;
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
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl
             << "~\n";
    }
    return 0;
}

// } Driver Code Ends
