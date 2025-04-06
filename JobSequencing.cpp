/* Job Sequencing Problem

You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
Constraints:
1 ≤ deadline.size() == profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500     */

//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        // code here
        vector<pair<int, int>> gr;
        int n = deadline.size();
        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        vector<int> possible(maxDeadline + 2, 0);
        for (int i = 0; i < n; i++)
        {
            gr.push_back({deadline[i], profit[i]});
        }
        sort(gr.begin(), gr.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });
        int maxJobs = 0;
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            int j = gr[i].first;
            while (j > 0)
            {
                if (possible[j] == 0)
                {
                    possible[j] = 1;
                    maxJobs += 1;
                    maxProfit += gr[i].second;
                    break;
                }
                j--;
            }
        }
        return vector<int>{maxJobs, maxProfit};
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
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
// Time Complexity = O(nSquared), TLE.
