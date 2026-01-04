/*Problem Statement: You are given a string s and a positive integer k.
Return the number of substrings that contain exactly k distinct characters.
Example 1:
Input:
 s = "pqpqs", k = 2
Output:
 7
Explanation:
  All substrings with exactly 2 distinct characters:
"pq", "pqp", "pqpq", "qp", "qpq", "pqs", "qs"
Total = 7.

Example 2:
Input:
 s = "abcbaa", k = 3
Output:
 5
Explanation:
  All substrings with exactly 3 distinct characters:
"abc", "abcb", "abcba", "bcba", "cbaa"
Total = 5.*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to count substrings with at most k distinct characters
int atMostKDistinct(string s, int k)
{
    // Left pointer and result
    int left = 0, res = 0;
    // Frequency map
    unordered_map<char, int> freq;

    // Iterate through string with right pointer
    for (int right = 0; right < s.size(); right++)
    {
        // Add current character
        freq[s[right]]++;

        // Shrink window if distinct characters exceed k
        while (freq.size() > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        // Count substrings in current window
        res += (right - left + 1);
    }
    return res;
}

// Function to count substrings with exactly k distinct characters
int countSubstrings(string s, int k)
{
    // Exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main()
{
    // Sample test
    string s = "pqpqs";
    int k = 2;

    // Output the result
    cout << "Count: " << countSubstrings(s, k) << endl; // Output: 7
    return 0;
}
