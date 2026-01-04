/* 402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        /* stack<char> st;
         for(int i=0; i<num.length(); i++){
             while(!st.empty() && k>=1 && (st.top()-'0') > (num[i] - '0')){
                 st.pop();
                 k--;
             }
             st.push(num[i]);
         }
         while(!st.empty() && k > 0){
             st.pop();
             k--;
         }
         if(st.empty()) return "0";
         string s = "";
         while(!st.empty()){
             s += st.top();
             st.pop();
         }
         reverse(s.begin(),s.end());
         for(int i = s.length() - 1; i >= 0; i-- ){
             if(s[i] == '0') s.pop_back();
         }
         if(s.length() == 0) return "0";
         else
         return s;*/
        stack<char> st; // Stack

        // Traverse on the given string
        for (int i = 0; i < num.size(); i++)
        {

            // Current digit
            char digit = num[i];

            /* Pop last digits (when possible)
            if a smaller digit is found*/
            while (!st.empty() && k > 0 && st.top() > digit)
            {

                st.pop(); // Pop the last digit
                k--;      // Decrement K by 1
            }

            // Push the current digit
            st.push(digit);
        }

        // If more digits can be removed
        while (!st.empty() && k > 0)
        {

            st.pop(); // Pop the last added digits
            k--;      // Decrement K by 1
        }

        // Handling edge case
        if (st.empty())
            return "0";

        // To store the result
        string res = "";

        // Adding digits in stack to result
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        // Trimming the zeroes at the back
        while (res.size() > 0 &&
               res.back() == '0')
        {

            res.pop_back();
        }

        // Reverse to get the actual number
        reverse(res.begin(), res.end());

        // Edge case
        if (res.empty())
            return "0";

        // Return the stored result
        return res;
    }
};
