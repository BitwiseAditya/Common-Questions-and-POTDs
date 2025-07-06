/*
You are given an array A of length N and an
integer k.
It is given that a subarray from l to r is considered
good, if the number of distinct elements in that
subarray doesn’t exceed k. Additionally, an empty
subarray is also a good subarray and its sum is
considered to be zero.
Find the maximum sum of a good subarray.

Input Format
The first line contains an integer, N, denoting the
number of elements in A.
The next line contains an integer, k, denoting the
limit on the distinct elements.
Each line i of the N subsequent lines (where 0 ≤ i <
N) contains an integer describing A[i].

Constraints
1 <= N <= 10^5
1 <= k <= n
-10^5 <= A[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

int goodSubarray(vector<int> &arr, int n, int k)
{
    int left = 0, right = 0;
    int ans = 0, sum = 0;
    unordered_map<int, int> freq;
    while (right < n)
    {
        freq[arr[right]] += 1;
        sum += arr[right];
        while (freq.size() > k || (arr[left] < 0 && right > left))
        {
            freq[arr[left]] -= 1;
            sum -= arr[left];
            if (freq[arr[left]] == 0)
                freq.erase(arr[left]);
            left++;
        }
        ans = max(ans, sum);
        right++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << goodSubarray(arr, n, k) << endl;
    return 0;
}
