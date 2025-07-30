/*Subarrays with sum K
Difficulty: MediumAccuracy: 49.74%Submissions: 89K+Points: 4
Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

Examples:

Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
Input: arr[] = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.
Constraints:
1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
-105 ≤ k ≤ 105  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cntSubarrays(vector<int> &arr, int k)
    {
        // unordered_map to store prefix sums frequencies
        unordered_map<int, int> prefixSums;

        int res = 0;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            // Add current element to sum so far.
            currSum += arr[i];

            // If currSum is equal to desired sum, then a new
            // subarray is found. So increase count of subarrays.
            if (currSum == k)
                res++;

            // Check if the difference exists in the prefixSums map.
            if (prefixSums.find(currSum - k) != prefixSums.end())
                res += prefixSums[currSum - k];

            // Add currSum to the set of prefix sums.
            prefixSums[currSum]++;
        }

        return res;
    }
};
