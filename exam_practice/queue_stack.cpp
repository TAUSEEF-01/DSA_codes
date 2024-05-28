#include <bits/stdc++.h>
using namespace std;

struct LinkedList
{
    int val;
    char ch;
    string str;
    LinkedList *next;
    LinkedList *prev;
};

struct Queue
{
    LinkedList *head = nullptr;
    LinkedList *tail = nullptr;

    void push(int value)
    {
        LinkedList *node = new LinkedList();
        node->val = value;
        node->next = nullptr;

        if (head == nullptr)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    int pop()
    {
        if (head == nullptr)
        {
            return -INT_MAX;
        }

        int value = head->val;
        head = head->next;

        return value;
    }

    int front()
    {
        if (head == nullptr)
        {
            return -INT_MAX;
        }

        int value = head->val;

        return value;
    }

    int back()
    {
        if (head == nullptr)
        {
            return -INT_MAX;
        }

        int value = tail->val;

        return value;
    }

    void sort()
    {
        LinkedList *node = head;
        while (node)
        {
            LinkedList *temp = head;
            while (temp)
            {
                if (temp->val > node->val) // ascending order
                {
                    int value = temp->val;
                    temp->val = node->val;
                    node->val = value;
                }
                temp = temp->next;
            }
            node = node->next;
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

struct Stack
{
    LinkedList *head = nullptr;
    LinkedList *tail = nullptr;

    void push(int value)
    {
        LinkedList *node = new LinkedList();
        node->val = value;
        node->next = nullptr;
        node->prev = tail;

        if (head == nullptr)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    int pop()
    {
        if (head == tail)
        {
            int value = head->val;
            head = tail = nullptr;
            return value;
        }

        // LinkedList *node = head;
        // while(node->next != tail)
        // {
        //     node = node->next;
        // }

        // int value = tail->val;
        // tail = node;
        // tail->next = nullptr;

        int value = tail->val;
        tail = tail->prev;

        return value;
    }

    int top()
    {
        if (head == nullptr)
        {
            return -INT_MAX;
        }

        int value = tail->val;
        return value;
    }

    void print()
    {
        LinkedList *node = tail;
        while (node)
        {
            cout << node->val << ' ';
            node = node->prev;
        }
        cout << endl;
    }
};

int main()
{
    // queue ------------------------------------>

    // int n;
    // cin >> n;

    // queue<int> q;
    // for(int i=0; i<n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     q.push(x);
    // }

    // cout << q.back() << endl;

    // q.pop();
    // q.pop();

    // while(!q.empty())
    // {
    //     cout << q.front() << ' ';
    //     q.pop();
    // }
    // cout << endl;

    int n;
    cin >> n;

    Queue Q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Q.push(x);
    }

    // Q.pop();
    // Q.pop();
    // Q.print();

    Q.sort();
    Q.print();

    // stack ----------------------------------->

    // int n;
    // cin >> n;

    // stack<int> s;

    // for(int i=0; i<n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     s.push(x);
    // }

    // s.pop();
    // s.pop();

    // while(!s.empty())
    // {
    //     cout << s.top() << ' ';
    //     s.pop();
    // }
    // cout << endl;

    // int n;
    // cin >> n;

    // Stack S;

    // for(int i=0; i<n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     S.push(x);
    // }

    // // S.print();

    // S.pop();
    // S.pop();
    // S.print();

    return 0;
}
