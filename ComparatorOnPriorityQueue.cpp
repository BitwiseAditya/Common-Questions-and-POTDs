#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        auto cmp = [](Node *a, Node *b)
        {
            return a->data > b->data;
        };
        priority_queue<Node *, vector<Node *>, decltype(cmp)> pq(cmp);
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        Node *head = new Node(0);
        Node *ptr = head;
        while (!pq.empty())
        {
            Node *temp = pq.top();
            pq.pop();
            ptr->next = temp;
            ptr = ptr->next;
            if (temp->next != NULL && temp->next != nullptr)
            {
                pq.push(temp->next);
            }
        }
        return head->next;
    }
};
