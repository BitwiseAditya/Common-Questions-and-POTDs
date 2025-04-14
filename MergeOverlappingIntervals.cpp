/* Overlapping Intervals

Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
             {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0]; });
        vector<vector<int>> ans;
        vector<int> temp(2);
        temp[0] = arr[0][0];
        temp[1] = arr[0][1];
        for (int i = 1; i < n; i++)
        {
            if (temp[1] >= arr[i][0])
            {
                if (temp[1] < arr[i][1])
                {
                    temp[1] = arr[i][1];
                }
            }
            else
            {
                ans.push_back(temp);
                temp[0] = arr[i][0];
                temp[1] = arr[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
