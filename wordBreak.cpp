/* Word Break
    You are given a string s and a list dictionary[] of words.
    Your task is to determine whether the string s can be formed
    by concatenating one or more words from the dictionary[].

    Note : From dictionary[],any word can be taken any number
    of times and in any order.

    Examples :
    Input : s = "ilike",dictionary[] = [ "i", "like", "gfg" ] Output : true
    Explanation : s can be breakdown as "i like".
    Input : s = "ilikegfg", dictionary[] = [ "i", "like", "man", "india", "gfg" ] Output : true
    Explanation : s can be breakdown as "i like gfg".
    Input : s = "ilikemangoes", dictionary[] = [ "i", "like", "man", "india", "gfg" ] Output : false
    Explanation : s cannot be formed using dictionary[] words.
    Constraints : 1 ≤ s.size() ≤ 3000 1 ≤ dictionary.size() ≤ 1000 1 ≤ dictionary[i].size() ≤ 100 */

// Recursive Solution, TLE :-

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool wordBreakRec(int index, int n, string &s, unordered_set<string> &st)
    {
        if (index == n)
        {
            return true;
        }
        string prefix = "";
        for (int i = index; i < n; i++)
        {
            prefix += s[i];
            if ((st.find(prefix) != st.end()) && wordBreakRec(i + 1, n, s, st))
            {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string &s, vector<string> &dictionary)
    {
        // code here
        unordered_set<string> st;
        int n = s.length();
        for (const auto &str : dictionary)
        {
            st.insert(str);
        }
        return wordBreakRec(0, n, s, st);
    }
};

//{ Driver Code Starts.

vector<string> inputLine()
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str)
    {
        res.push_back(str);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary))
        {
            cout << "true\n";
        }
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
