/* Histogram Max Rectangular Area

    You are given a histogram represented by an array arr,
    where each element of the array denotes the height of the bars in the histogram.All bars have the same width of 1 unit.

    Your task is to find the largest rectangular area possible in the given histogram,
    where the rectangle can be formed using a number of contiguous bars.

    Examples :

    Input : arr[] = [ 60, 20, 50, 40, 10, 50, 60 ] Largest - Rectangular - Area - in - a - Histogram Output : 100
    Explanation : We get the maximum by picking bars highlighted above in green(50, and 60).The area is computed(smallest height) * (no.of the picked bars) = 50 * 2 = 100.
    Input : arr[] = [ 3, 5, 1, 7, 5, 9 ] Output : 15
    Explanation : We get the maximum by picking bars 7, 5 and 9. The area is computed(smallest height) * (no.of the picked bars) = 5 * 3 = 15. Input : arr[] = [3] Output : 3 Explanation : In this example the largest area would be 3 of height 3 and width 1.
    Constraints : 1 ≤ arr.size() ≤ 105 0 ≤ arr[i] ≤ 104  */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // } Driver Code Ends
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                nse[i] = n;
            }
            else
            {
                nse[i] = s.top();
            }
            s.push(i);
        }
        return nse;
    }
    vector<int> previousSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = s.top();
            }
            s.push(i);
        }
        return pse;
    }
    int getMaxArea(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        int ans = 0;
        vector<int> nse(n);
        vector<int> pse(n);
        nse = nextSmallerElement(arr);
        pse = previousSmallerElement(arr);
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] * (nse[i] - pse[i] - 1));
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
