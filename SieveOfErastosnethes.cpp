/* 2523. Closest Prime Numbers in Range

    Given two positive integers left and right,
    find the two integers num1 and num2 such that :
    left <= num1 < num2 <= right.Both num1 and num2 are prime numbers.
    num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
    Return the positive integer array ans = [ num1, num2 ].If there are multiple pairs satisfying these conditions,
    return the one with the smallest num1 value.If no such numbers exist, return [ -1, -1 ].

                                                                                                                                                                                                                                                                        Example 1 :

    Input : left = 10,
                                                                                                                                                                                           right = 19 Output : [ 11, 13 ] Explanation : The prime numbers between 10 and 19 are 11, 13, 17, and 19. The closest gap between any pair is 2, which can be achieved by[11, 13] or [ 17, 19 ].Since 11 is smaller than 17, we return the first pair.Example 2 :

    Input : left = 4,
                                                                                                                                                                                           right = 6 Output : [ -1, -1 ] Explanation : There exists only one prime number in the given range, so the conditions cannot be satisfied.

                                                                                                                                                                                                                                                                                                  Constraints :

                                                                                                                                                                                                                                                                                                  1 <= left <= right <= 10^6
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes = SOE(left, right);
        vector<int> ans(2, -1);
        int diff = INT_MAX;
        if (primes.size() < 2)
            return ans;
        for (int i = 1; i < primes.size(); i++)
        {
            if (primes[i] - primes[i - 1] < diff)
            {
                diff = primes[i] - primes[i - 1];
                ans[0] = primes[i - 1];
                ans[1] = primes[i];
            }
        }
        return ans;
    }
    vector<int> SOE(int left, int right)
    {
        vector<int> sieve(right + 1, 1);
        vector<int> primes;
        sieve[0] = 0;
        sieve[1] = 0;
        for (int i = 2; i <= right; i++)
        {
            if (sieve[i] == 1)
            {
                int j = 2;
                while (i * j <= right)
                {
                    sieve[i * j] = 0;
                    j++;
                }
            }
        }
        for (int k = left; k <= right; k++)
        {
            if (sieve[k] == 1)
            {
                primes.push_back(k);
            }
        }
        return primes;
    }
};
