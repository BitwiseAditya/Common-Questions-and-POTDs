/* Tywin's War Strategy

You are given an array arr[] of size n, where arr[i] represents the number of soldiers in the i-th troop. You are also given an integer k. A troop is considered "lucky" if its number of soldiers is a multiple of k. Find the minimum total number of soldiers to add across all troops so that at least ⌈n / 2⌉ troops become lucky.

Examples:

Input: arr = [5, 6, 3, 2, 1], k = 2
Output: 1
Explanation: By adding 1 soldier for the troop with 1 soldier, we get [5, 6, 3, 2, 2]. Now 3 out of 5 troops (6, 2, and 2) are multiples of 2 that satisfy the requirement.
Input: arr = [3, 5, 6, 7, 9, 10], k = 4
Output: 4
Explanation: We need at least 3 lucky troops since ⌈6 / 2⌉ = 3. Currently, no troop is divisible by 4.
Add 1 soldier for troop 3 → 4,
Add 2 for troop 6 → 8,
Add 1 for troop 7 → 8.
New array: [4, 5, 8, 8, 9, 10] with 3 lucky troops (4, 8, 8).
Total soldiers added = 4.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSoldiers(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        // Ye question sirf agli likhi line ki wajah se daala hai. seedha ceil(n/2) karke answer nahi aayega
        // pehle dono ko double mein alag se type cast karo, fir divide karo aur fir ceil lagao,
        // tab jaake hoga. Ex. ceil(5/2) == 2 but ceil((double)5 / (double)2) == 3. Ye hai asli baat !
        int toLucky = ceil(((double)n) / ((double)2));
        int alreadyLucky = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % k == 0)
                alreadyLucky++;
        }
        toLucky -= alreadyLucky;
        if (toLucky <= 0)
            return 0;
        vector<int> toLuckyArr;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % k != 0)
            {
                int divi = arr[i] / k;
                int temp = ((divi + 1) * k) - arr[i];
                toLuckyArr.push_back(temp);
            }
        }
        sort(toLuckyArr.begin(), toLuckyArr.end());
        int ans = 0;
        for (int i = 0; i < toLuckyArr.size(); i++)
        {
            if (toLuckyArr[i] != 0 && toLucky != 0)
            {
                ans += toLuckyArr[i];
                toLucky--;
            }
            else if (toLucky == 0)
            {
                break;
            }
        }
        return ans;
    }
};
