#include <bits/stdc++.h>
using namespace std;

struct inPostFix
{
    struct Stack
    {
        int val;
        Stack *next;
    };

    Stack *head = NULL;
    Stack *tail = NULL;

    void push(int ch)
    {
        Stack *node = (Stack *)malloc(sizeof(Stack));
        node->val = ch;
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
        if (head->next == NULL)
        {
            return;
        }

        Stack *node = head;
        while (node->next != tail)
        {
            node = node->next;
        }
        tail = node;
        tail->next = NULL;
    }

    int top()
    {
        return tail->val;
    }

    bool empty()
    {
        if (head->next == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    inPostFix a;

    string s;
    cin >> s;
    int n = s.size();

    int value = 0;

    for (int i = 0; i < n; i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            value = a.top();

            a.pop();

            if (s[i] == '+')
                value += a.top();
            else if (s[i] == '-')
                value = a.top() - value;
            else if (s[i] == '*')
                value *= a.top();
            else if (s[i] == '/')
                value = a.top() / value;
            else if (s[i] == '^')
                value = (int)pow(a.top(), value);

            a.pop();

            a.push(value);
            // cout << value << endl;
        }
        else
        {
            a.push(s[i] - '0');
        }
    }

    cout << value << endl;

    return 0;
}
