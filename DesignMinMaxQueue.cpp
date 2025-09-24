/* Design MinMax Queue

Design a SpecialQueue data structure that functions like a normal queue but with additional support for retrieving the minimum and maximum element efficiently.
The SpecialQueue must support the following operations:

enqueue(x): Insert an element x at the rear of the queue.
dequeue(): Remove the element from the front of the queue.
getFront(): Return the front element without removing.
getMin(): Return the minimum element in the queue in O(1) time.
getMax(): Return the maximum element in the queue in O(1) time.
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2:  Call dequeue()
3: Call getFront()
4: Call getMin()
5: Call getMax()
The driver code will process the queries, call the corresponding functions, and print the outputs of getFront(), getMin(), getMax() operations.
You only need to implement the above five functions.

Note: It is guaranteed that all the queries are valid.

Examples:

Input: q = 6, queries[][] = [[1, 4], [1, 2], [3], [4], [2], [5]]
Output: [4, 2, 2]
Explanation: Queries on queue are as follows:
enqueue(4): Insert 4 at the rear of the queue.
enqueue(2): Insert 2 at the rear of the queue.
return the front element i.e 4
return minimum element from the queue i.e 2
dequeue(): Remove the front element 4 from the queue
return maximum element from the queue i.e 2
Input: q = 4, queries[][] = [[1, 3], [4], [1, 5], [5]]
Output: [3, 5]
Explanation: Queries on queue are as follows:
enqueue(3): Insert 3 at the rear of the queue.
return minimum element from the queue i.e 3
enqueue(5): Insert 5 at the rear of the queue.
return maximum element from the queue i.e 5
Constraints:
1 ≤ queries.size() ≤ 105
0 ≤ values in the queue ≤ 109*/

#include <bits/stdc++.h>
using namespace std;

class SpecialQueue
{

public:
    queue<int> q1;
    deque<int> q2;
    deque<int> q3;
    SpecialQueue()
    {
        // Define Data Structures
        q1 = queue<int>();
        q2 = deque<int>();
        q3 = deque<int>();
    }

    void enqueue(int x)
    {
        // Insert element into the queue
        q1.push(x);
        while (!q2.empty() && q2.back() > x)
        {
            q2.pop_back();
        }
        q2.push_back(x);
        while (!q3.empty() && q3.back() < x)
        {
            q3.pop_back();
        }
        q3.push_back(x);
    }

    void dequeue()
    {
        // Remove element from the queue
        if (q1.empty())
            return;
        int temp = q1.front();
        q1.pop();
        if (!q2.empty())
        {
            if (temp == q2.front())
            {
                q2.pop_front();
            }
        }
        if (!q3.empty())
        {
            if (temp == q3.front())
            {
                q3.pop_front();
            }
        }
    }

    int getFront()
    {
        // Get front element
        return q1.front();
    }

    int getMin()
    {
        // Get minimum element
        return q2.front();
    }

    int getMax()
    {
        // Get maximum element
        return q3.front();
    }
};