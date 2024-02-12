#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    struct LinkedList
    {
        int val;
        LinkedList *next;
    };

    LinkedList *head = NULL;
    LinkedList *tail = NULL;

    void push(int value)
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->val = value;
        node->next = NULL;
        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    int front()
    {
        if (head == NULL)
        {
            return INT_MAX;
        }

        int value = head->val;
        return value;
    }

    int back()
    {
        if (tail == NULL)
        {
            return INT_MAX;
        }

        int value = tail->val;
        return value;
    }

    void pop()
    {
        if (head == NULL)
        {
            return;
        }

        head = head->next;
    }

    bool empty()
    {
        if (head == NULL)
            return true;
        else
            false;
    }

    void sort()
    {
        LinkedList *node1 = head;
        while (node1)
        {
            LinkedList *node2 = head;
            while (node2)
            {
                if (node2->val > node1->val)
                {
                    int temp = node2->val;
                    node2->val = node1->val;
                    node1->val = temp;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }

    void print()
    {
        LinkedList *node = head;
        while (node)
        {
            cout << node->val << ' ';
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        q.push(x);
    }

    q.print();
    q.sort();
    q.print();

    // int value = q.front();
    // int value2 = q.back();
    // cout << value << ' ' << value2 << endl;

    // q.pop();
    // q.print();

    return 0;
}