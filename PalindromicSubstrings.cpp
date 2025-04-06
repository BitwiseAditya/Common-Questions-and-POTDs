/* Palindrome SubStrings
    Given a string s,count all palindromic sub - strings present in the string.
    The length of the palindromic sub - string must be greater than or equal to 2.

    Examples

    Input : s = "abaab" Output : 3 Explanation : All palindromic substrings are : "aba",
    "aa", "baab".
    Input : s = "aaa" Output : 3 Explanation : All palindromic substrings are : "aa", "aa", "aaa".
    Input : s = "abbaeae" Output : 4 Explanation : All palindromic substrings are : "bb", "abba", "aea", "eae".
    Constraints : 2 ≤ s.size() ≤ 103 string contains only lowercase english characters */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void expandAround(string s, int left, int right, int &ans)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            if (right - left + 1 >= 2)
            {
                ans++;
            }
            left--;
            right++;
        }
    }
    int countPS(string &s)
    {
        // code here
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            expandAround(s, i, i, ans);
            expandAround(s, i, i + 1, ans);
        }
        return ans;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
