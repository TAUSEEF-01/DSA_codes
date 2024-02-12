#include <bits/stdc++.h>
using namespace std;

// implementing queue
struct Queue
{
    struct LinkedList
    {
        int val;
        char ch;
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

    void push(char value)
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->ch = value;
        node->next = NULL;
        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    int front(int p)
    {
        if (head == NULL)
        {
            return INT_MAX;
        }

        int value = head->val;
        return value;
    }

    char front(char p)
    {
        if (head == NULL)
        {
            return INT_MAX;
        }

        int value = head->ch;
        return value;
    }

    int back(int p)
    {
        if (tail == NULL)
        {
            return INT_MAX;
        }

        int value = tail->val;
        return value;
    }

    char back(char p)
    {
        if (tail == NULL)
        {
            return INT_MAX;
        }

        int value = tail->ch;
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

    void print(int p)
    {
        LinkedList *node = head;
        while (node)
        {
            cout << node->val << ' ';
            node = node->next;
        }
        cout << endl;
    }

    void print(char p)
    {
        LinkedList *node = head;
        while (node)
        {
            cout << node->ch << ' ';
            node = node->next;
        }
        cout << endl;
    }
};

// implementing stack
struct Stack
{
    struct LinkedList
    {
        int val;
        char ch;
        string str;
        LinkedList *next;
    };

    LinkedList *head = NULL;
    LinkedList *tail = NULL;

    void push(char c)
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->ch = c;
        node->next = NULL;

        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void push(int v)
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->val = v;
        node->next = NULL;

        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void push(string s)
    {
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->str = s;
        node->next = NULL;

        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void pop()
    {
        if (head == tail)
        {
            head = tail = NULL;
            return;
        }

        LinkedList *node = head;
        while (node->next != tail)
            node = node->next;

        tail = node;
        tail->next = NULL;
    }

    char top(char c)
    {
        if (tail == NULL)
            return '@';
        return tail->ch;
    }

    int top(int v)
    {
        if (tail == NULL)
            return 0;
        return tail->val;
    }

    string top(string s)
    {
        if (tail == NULL)
            return "";
        return tail->str;
    }

    bool empty()
    {
        if (tail == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    string a;
    cin >> a;

    Queue q;
    Stack s;

    int n = a.size();
    for (int i = 0; i < ((n / 2) + (n % 2)); i++)
    {
        q.push(a[i]);
    }
    for (int i = n / 2; i < n; i++)
    {
        s.push(a[i]);
    }

    bool flag = true;

    while (!q.empty() && !s.empty())
    {
        if (q.front('@') != s.top('@'))
        {
            flag = false;
            break;
        }
        q.pop();
        s.pop();
    }

    if (!q.empty() || !s.empty())
    {
        flag = false;
    }

    if (flag)
    {
        cout << "Palindrome.\n";
    }
    else
    {
        cout << "Not Palindrome.\n";
    }

    return 0;
}