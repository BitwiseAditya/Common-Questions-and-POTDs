/* Majority Element

Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

Examples:

Input: arr[] = [1, 1, 2, 1, 3, 5, 1]
Output: 1
Explanation: Since, 1 is present more than 7/2 times, so it is the majority element.
Input: arr[] = [7]
Output: 7
Explanation: Since, 7 is single element and present more than 1/2 times, so it is the majority element.
Input: arr[] = [2, 13]
Output: -1
Explanation: Since, no element is present more than 2/2 times, so there is no majority element.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105 */

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int element = -1;
        int occurence = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element)
            {
                occurence++;
            }
            else if (occurence == 0)
            {
                element = arr[i];
                occurence = 1;
            }
            else
            {
                occurence--;
            }
        }
        int frequency = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element)
            {
                frequency++;
            }
        }
        if (frequency > n / 2)
        {
            return element;
        }
        else
            return -1;
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
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
