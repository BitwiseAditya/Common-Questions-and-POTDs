/*
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put. */

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int ky;
    int val;
    struct node *next;
    struct node *prev;
};

class LRUCache
{
    int capacity;
    int currCapacity;
    struct node *firstNode;
    struct node *lastNode;
    unordered_map<int, struct node *> mp;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        currCapacity = 0;
        firstNode = new struct node();
        firstNode->ky = -1;
        firstNode->val = -1;
        firstNode->prev = nullptr;
        lastNode = new struct node();
        lastNode->ky = -1;
        lastNode->val = -1;
        lastNode->prev = firstNode;
        lastNode->next = nullptr;
        firstNode->next = lastNode;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            struct node *temp = mp[key];
            if (firstNode->next != temp)
            {
                struct node *temp1 = temp->prev;
                struct node *temp2 = temp->next;
                temp1->next = temp2;
                temp2->prev = temp1;
                struct node *temp3 = firstNode->next;
                firstNode->next = temp;
                temp->prev = firstNode;
                temp->next = temp3;
                temp3->prev = temp;
            }
            return temp->val;
        }
    }
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            struct node *temp = mp[key];
            temp->val = value;
            struct node *temp1 = temp->prev;
            struct node *temp2 = temp->next;
            if (temp1 != firstNode)
            {
                temp1->next = temp2;
                temp2->prev = temp1;
                struct node *temp3 = firstNode->next;
                firstNode->next = temp;
                temp->prev = firstNode;
                temp->next = temp3;
                temp3->prev = temp;
            }
        }
        else if (currCapacity < capacity)
        {
            struct node *temp = new struct node();
            temp->ky = key;
            temp->val = value;
            struct node *temp1 = firstNode->next;
            firstNode->next = temp;
            temp->prev = firstNode;
            temp->next = temp1;
            temp1->prev = temp;
            mp[key] = temp;
            currCapacity++;
        }
        else if (currCapacity == capacity)
        {
            struct node *toRemove = lastNode->prev;
            struct node *temp = new struct node();
            temp->ky = key;
            temp->val = value;
            struct node *temp1 = toRemove->prev;
            temp1->next = lastNode;
            lastNode->prev = temp1;
            mp.erase(toRemove->ky);
            toRemove->next = nullptr;
            toRemove->prev = nullptr;
            delete toRemove;
            struct node *temp2 = firstNode->next;
            firstNode->next = temp;
            temp->prev = firstNode;
            temp->next = temp2;
            temp2->prev = temp;
            mp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
