/* Missing in Array

You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNum(vector<int> &arr)
    {
        // code here
        long long n = arr.size();
        long long n1 = n + 1;
        long long sumreq = (n1 * (2 + n1 - 1)) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return (sumreq - sum);
    }
};

// note : ye q sirf is liye daala kyunki jab answer kuch test cases mein pass na ho, toh zara data types se khel
// ke dekho, for ex. upar agar long long nahi loge sab instead of int, to integer overflow ho jaaega!
// so yeah, data types ka aur integer overflow ka dhyaan rakhna hai!
// jab bhi lag raha ho integer overflow ho raha hai kuch test cases mein, toh long long laga do int ki jagah!
