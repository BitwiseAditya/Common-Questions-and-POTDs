/*Given an array of unique integers numbers,
your task is to find the number of pairs of indices
(i, j) such that i ≤ j and the sum numbers[i] + numbers[j]
 is equal to some power of 2.

Note: The numbers 2pow0  = 1, 2pow1 = 2, 2pow2 = 4, 2pow3 = 8, etc. are considered to be powers of 2.
Example

For numbers = [1, -1, 2, 3], the output should be solution(numbers) = 5.
– There is one pair of indices where the sum of the elements is 2pow0 = 1:(1, 2): numbers[1] + numbers[2] = -1 + 2 = 1
– There are two pairs of indices where the sum of the elements is 2pow1 = 2: (0, 0) and (1, 3)
– There are two pairs of indices where the sum of the elements is 2pow2 = 4: (0, 3) and (2, 2)
– In total, there are 1 + 2 + 2 = 5 pairs summing to powers of 2.

For numbers = [2], the output should be solution(numbers) = 1.
– The only pair of indices is (0, 0) and the sum is equal to 2pow2 = 4. So, the answer is 1.

For numbers = [-2, -1, 0, 1, 2], the output should be solution(numbers) = 5.
– There are two pairs of indices where the sum of the elements is 2pow0 = 1: (2, 3) and (1, 4)
– There are two pairs of indices where the sum of the elements is 2pow1 = 2: (2, 4) and (3, 3)
– There is one pair of indices where the sum of the elements is 2pow2 = 4: (4, 4)
– In total, there are 2 + 2 + 1 = 5 pairs summing to powers of 2.

Guaranteed constraints:

1 ≤ numbers.length ≤ 105
-106 ≤ numbers[i] ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;

long pow0f2Pair(vector<int> &arr)
{
    unordered_map<long, long> freqmap;
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 21; j++)
        {
            long temp = (1 << j) - arr[i];
            if (freqmap.find(temp) != freqmap.end())
            {
                count += freqmap[temp];
            }
        }
        if (((2 * arr[i]) & (2 * arr[i] - 1)) == 0)
        {
            count += 1;
        }
        freqmap[arr[i]] += 1;
    }
    return count;
}
