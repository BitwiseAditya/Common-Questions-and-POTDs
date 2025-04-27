/* Multiply two strings

Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

Examples:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66
Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253
Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.
Constraints:
1 ≤ s1.size() ≤ 103
1 ≤ s2.size() ≤ 103 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoii(char d)
    {
        return (d - 48);
    }
    /*You are required to complete below function */
    string multiplyStrings(string &s1, string &s2)
    {
        // Your code here
        string ss1 = s1;
        string ss2 = s2;
        if (ss1.length() < ss2.length())
        {
            string temp = ss1;
            ss1 = ss2;
            ss2 = temp;
        }
        int counter = 0;
        if (ss1[0] == '-' || ss2[0] == '-')
        {
            if (ss1[0] == '-' && ss2[0] == '-')
            {
                ss1.erase(ss1.begin(), ss1.begin() + 1);
                ss2.erase(ss2.begin(), ss2.begin() + 1);
            }
            else if (ss1[0] == '-')
            {
                ss1.erase(ss1.begin(), ss1.begin() + 1);
                counter = 1;
            }
            else
            {
                ss2.erase(ss2.begin(), ss2.begin() + 1);
                counter = 1;
            }
        }
        int n = ss1.length();
        int m = ss2.length();
        vector<int> ans(n + m, 0);
        int counter01 = 0;
        for (int i = 0; i < n; i++)
        {
            if (ss1[i] != '0')
                counter01 = 1;
        }
        int counter02 = 0;
        for (int i = 0; i < m; i++)
        {
            if (ss2[i] != '0')
                counter02 = 1;
        }
        if (counter01 == 0 || counter02 == 0)
        {
            string ans = "0";
            return ans;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            int a = stoii(ss2[i]);
            vector<int> temp;
            int carry = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                int b = stoii(ss1[j]);
                int c = a * b;
                c += carry;
                carry = c / 10;
                temp.push_back(c % 10);
            }
            temp.push_back(carry);
            reverse(temp.begin(), temp.end());
            for (int k = 0; k < (m - i - 1); k++)
            {
                temp.push_back(0);
            }
            int l = n + m - 1;
            carry = 0;
            int s = temp.size();
            for (int p = s - 1; p >= 0; p--)
            {
                int tempnum = temp[p] + ans[l] + carry;
                ans[l] = tempnum % 10;
                carry = tempnum / 10;
                l--;
            }
            while (carry != 0 && l >= 0)
            {
                ans[l] += carry;
                carry = ans[l] / 10;
                ans[l] = ans[l] % 10;
                l--;
            }
            if (carry != 0)
            {
                ans.insert(ans.begin(), carry);
            }
        }
        string final;
        int s = ans.size();
        int j;
        for (j = 0; j < s; j++)
        {
            if (ans[j] != 0)
                break;
        }
        for (int i = j; i < s; i++)
        {
            char c = ans[i] + 48;
            final += c;
        }
        if (counter == 1)
        {
            final.insert(final.begin(), '-');
        }
        return final;
    }
};
