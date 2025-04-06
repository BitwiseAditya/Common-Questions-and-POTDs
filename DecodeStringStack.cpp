/* Decode the string
    Given an encoded string s,
    the task is to decode it.The encoding rule is :

    k[encodedString],where the encodedString inside the square brackets is
    being repeated exactly k times.Note that k is guaranteed to be a positive
    integer.Note : The test cases are generated so that the length of the output
    string will never exceed 105 .

    Examples :
    Input : s = "1[b]" Output : "b" Explanation : "b" is present only one time.Input : s = "3[b2[ca]]" Output : "bcacabcacabcaca" Explanation : 1. Inner substring “2 [ca]” breakdown into “caca”.2. Now,
            new string becomes “3 [bcaca]” 3. Similarly “3 [bcaca]” becomes “bcacabcacabcaca ” which is final result.
            Constraints : 1 ≤ | s | ≤ 105 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string decodedString(string &s)
    {
        // code here
        stack<int> s1;
        stack<string> s2;
        string currstr = "";
        int currnum = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                currnum = currnum * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                s1.push(currnum);
                s2.push(currstr);
                currnum = 0;
                currstr = "";
            }
            else if (s[i] == ']')
            {
                int n1 = s1.top();
                s1.pop();
                string s = s2.top();
                s2.pop();
                for (int i = 0; i < n1; i++)
                {
                    s += currstr;
                }
                currstr = s;
            }
            else
            {
                currstr += s[i];
            }
        }
        return currstr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends