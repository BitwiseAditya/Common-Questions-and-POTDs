/* Prime List

You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

Examples :

Input: head = 2 → 6 → 10
Output: 2 → 5 → 11

Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19

Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int num)
    {
        val = num;
        next = NULL;
    }
};

class Solution
{
public:
    vector<bool> seive(int n)
    {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    int checkNearestPrime(int val, vector<bool> &primes)
    {
        if (primes[val])
            return val;
        int i = val, j = val;
        int n = primes.size();
        while (i >= 0 && !primes[i])
            i--;
        while (j < n && !primes[j])
            j++;
        if (i < 0)
            return j;
        if (j >= n)
            return i;
        return abs(val - i) <= abs(val - j) ? i : j;
    }
    Node *primeList(Node *head)
    {
        // code here
        int maxi = INT_MIN;
        Node *temp = head;
        while (temp != NULL)
        {
            maxi = max(temp->val, maxi);
            temp = temp->next;
        }
        vector<bool> primes = seive(maxi + 100); // small buffer for edge cases
        temp = head;
        while (temp != NULL)
        {
            temp->val = checkNearestPrime(temp->val, primes);
            temp = temp->next;
        }
        return head;
    }
};
