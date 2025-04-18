/* Implement Trie

Implement Trie class and complete insert(), search() and isPrefix() function for the following queries :

Type 1 : (1, word), calls insert(word) function and insert word in the Trie
Type 2 : (2, word), calls search(word) function and check whether word exists in Trie or not.
Type 3 : (3, word), calls isPrefix(word) function and check whether word exists as a prefix of any string in Trie or not.
Examples :

Input: query[][] = [[1, "abcd"], [1, "abc"], [1, "bcd"], [2, "bc"], [3, "bc"], [2, "abc"]]
Output: [false, true, true]
Explanation: string "bc" does not exist in the trie, "bc" exists as prefix of the word "bcd" in the trie, and "abc" also exists in the trie.
Input: query[][] = [[1, "gfg"], [1, "geeks"], [3, "fg"], [3, "geek"], [2, "for"]]
Output: [false, true, false]
Explanation: The string "for" is not present in the trie, "fg" is not a valid prefix, while "geek" is a valid prefix of the word "geeks" in the trie.
Constraints:
1 ≤ query.size() ≤ 104
1 ≤ word.size() ≤ 103 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct trie
{
    vector<struct trie *> arr;
    int isprefix;
    bool exists;
    trie()
    {
        arr = vector<struct trie *>(26, NULL);
        isprefix = 0;
        exists = false;
    }
};
// User function template for C++
class Trie
{
    struct trie *head;

public:
    Trie()
    {
        // implement Trie
        head = new struct trie();
    }

    void insert(string &word)
    {
        // insert word into Trie
        int n = word.length();
        struct trie *temp = head;
        for (int i = 0; i < n; i++)
        {
            if (temp->arr[word[i] - 97] == NULL)
            {
                temp->arr[word[i] - 97] = new struct trie();
                temp->arr[word[i] - 97]->isprefix += 1;
            }
            else
            {
                temp->arr[word[i] - 97]->isprefix += 1;
            }
            temp = temp->arr[word[i] - 97];
        }
        temp->exists = true;
    }

    bool search(string &word)
    {
        // search word in the Trie
        int n = word.length();
        struct trie *temp = head;
        for (int i = 0; i < n; i++)
        {
            if (temp->arr[word[i] - 97] == NULL)
            {
                return false;
            }
            else
            {
                temp = temp->arr[word[i] - 97];
            }
        }
        if (temp->exists == true)
            return true;
        else
            return false;
    }

    bool isPrefix(string &word)
    {
        // search prefix word in the Trie
        int n = word.length();
        struct trie *temp = head;
        for (int i = 0; i < n; i++)
        {
            if (temp->arr[word[i] - 97] == NULL)
            {
                return false;
            }
            else
            {
                temp = temp->arr[word[i] - 97];
            }
        }
        if (temp->isprefix > 0)
            return true;
        else
            return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1)
            {
                ob.insert(s);
            }
            else if (x == 2)
            {
                ans.push_back(ob.search(s));
            }
            else if (x == 3)
            {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
