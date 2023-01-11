#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int val;
        Node *prev;
        Node *next;
        Node(int newVal)
        {
            val = newVal;
        }
    };

    Node *head = new Node(0);
    Node *tail = new Node(0);
    unordered_map<int, Node *> mp; // key, node ptr
    int currNum, cap;

    LRUCache(int capacity)
    {
        cap = capacity;
        currNum = 0;
        head->next = tail;
        tail->next = head;
        tail->prev = head;
    }

    // append new node to tail
    void add(Node *n)
    {
        tail->prev->next = n;
        n->prev = tail->prev;
        n->next = tail;
        tail->prev = n;
    }

    // delete node
    void del(Node *n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *n = mp[key];
            del(n); // O(1)
            add(n); // O(1)
            return mp[key]->val;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key]->val = value;
            del(mp[key]); // O(1)
            add(mp[key]); // O(1)
        }
        else
        {
            Node *n = new Node(value);
            while (currNum >= cap)
            {
                del(head->next); // delete the LRU node
                currNum--;
            }
            add(n);
            currNum++;
            mp[key] = n;
        }
    }
};

int main()
{
    LRUCache *obj = new LRUCache(1);
    obj->put(1, 1);
    obj->put(2, 2);
    int param_1 = obj->get(1);

    return 0;
}
