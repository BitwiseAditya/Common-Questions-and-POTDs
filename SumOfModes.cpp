/* Sum of Mode

Given an array arr[] of positive integers and an integer k. You have to find the sum of the modes of all the subarrays of size k.
Note: The mode of a subarray is the element that occurs with the highest frequency. If multiple elements have the same highest frequency, the smallest such element is considered the mode.

Examples:

Input: arr[] = [1, 2, 3, 2, 5, 2, 4, 4], k = 3
Output: 13
Explanation: The mode of each k size subarray is [1, 2, 2, 2, 2, 4] and sum of all modes is 13.
Input: arr[] = [1, 2, 1, 3, 5], k = 2
Output: 6
Explanation: The mode of each k size subarray is [1, 1, 1, 3] and sum of all modes is 6.
Constraints:
1 ≤ k ≤ arr.size() ≤105
1 ≤ arr[i] ≤ 105 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfModes(vector<int> &arr, int k)
    {
        // code here
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.second == b.second)
            {
                return a.first < b.first;
            }
            return a.second > b.second;
        };
        set<pair<int, int>, decltype(cmp)> st(cmp);
        unordered_map<int, int> mp;
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < k; i++)
        {
            if (mp.find(arr[i]) != mp.end())
            {
                st.erase({arr[i], mp[arr[i]]});
            }
            mp[arr[i]] += 1;
            st.insert({arr[i], mp[arr[i]]});
        }
        int left = 0, right = k - 1;
        while (right < n)
        {
            sum += (*(st.begin())).first;
            if (mp[arr[left]] == 1)
            {
                st.erase({arr[left], mp[arr[left]]});
                mp.erase(arr[left]);
            }
            else
            {
                st.erase({arr[left], mp[arr[left]]});
                mp[arr[left]] -= 1;
                st.insert({arr[left], mp[arr[left]]});
            }
            left++;
            if (mp.find(arr[right + 1]) != mp.end())
            {
                st.erase({arr[right + 1], mp[arr[right + 1]]});
                mp[arr[right + 1]] += 1;
                st.insert({arr[right + 1], mp[arr[right + 1]]});
            }
            else
            {
                mp[arr[right + 1]] += 1;
                st.insert({arr[right + 1], mp[arr[right + 1]]});
            }
            right++;
        }
        return sum;
    }
};