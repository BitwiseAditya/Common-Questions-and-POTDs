/*Count elements less than or equal to k in a sorted rotated array

Given a sorted array arr[] containing distinct positive integers that has been rotated at some unknown pivot, and a value x. Your task is to count the number of elements in the array that are less than or equal to x.

Examples:

Input: arr[] = [4, 5, 8, 1, 3], x = 6
Output: 4
Explanation: 1, 3, 4 and 5 are less than 6, so the count of all elements less than 6 is 4.
Input: arr[] = [6, 10, 12, 15, 2, 4, 5], x = 14
Output: 6
Explanation: All elements except 15 are less than 14, so the count of all elements less than 14 is 6.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i], x ≤ 109*/

#include <iostream>
#include <vector>
using namespace std;

// Standard binary search to count
// elements ≤ x in a sorted subarray
int countInSorted(vector<int> &arr, int left, int right, int x)
{
    int l = left, r = right, res = left - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res - left + 1;
}

// Function to find index of the smallest
// element (pivot) in rotated array
int findPivot(vector<int> &arr)
{
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    // index of the smallest element
    return l;
}

// Main function to count elements ≤ x
// in a rotated sorted array
int countLessEqual(vector<int> &arr, int x)
{
    int n = arr.size();
    int pivot = findPivot(arr);

    // Search in both sorted parts
    int count1 = countInSorted(arr, 0, pivot - 1, x);
    int count2 = countInSorted(arr, pivot, n - 1, x);

    return count1 + count2;
}

int main()
{
    vector<int> arr = {6, 10, 12, 15, 2, 4, 5};
    int x = 14;

    cout << countLessEqual(arr, x) << endl;

    return 0;
}
