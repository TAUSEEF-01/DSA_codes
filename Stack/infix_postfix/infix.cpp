#include<bits/stdc++.h>
using namespace std;

struct inPostFix
{
    struct Stack 
    {
        char val;
        Stack* next;
    };

    Stack* head = NULL;
    Stack* tail = NULL;

    void push(char ch)
    {
        Stack* node = (Stack*)malloc(sizeof(Stack));
        node->val = ch;
        node->next = NULL;

        if(head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void pop()
    {
        if(head->next == NULL)
        {
            return;
        }

        Stack* node = head;
        while(node->next != tail)
        {
            node = node->next;
        }
        tail = node;
        tail->next = NULL;
    }

    char top()
    {
        return tail->val;
    }

    int precedence(char ch)
    {
        if(ch == '^') return 2;
        else if(ch == '*' || ch == '/') return 1;
        else if(ch == '+' || ch == '-') return 0;
        else return -1;
    }

    char associativity(char ch)
    {
        if(ch == '^') return 'R';
        else return 'L';
    }

    bool empty()
    {
        if(head->next == NULL) return true;
        else return false;
    }

    void print()
    {
        Stack* node = head;
        while(node)
        {
            cout<<node->val;
            node = node->next;
        }
        cout << endl;
    }
};


int main()
{
    inPostFix a, b;

    string s;
    cin >> s;

    b.push('@');
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
        {
            a.push(s[i]);
        }
        else 
        {
            if(s[i] == '(')
            {
                b.push(s[i]);
                continue;
            }
            else if(s[i] == ')')
            {
                while(b.top() != '(' && !b.empty())
                {
                    a.push(b.top());
                    b.pop();
                }

                b.pop();
                continue;
            }
            else if(b.precedence(s[i]) <= b.precedence(b.top()))
            {
                while(b.precedence(s[i]) <= b.precedence(b.top()) && !b.empty())
                {
                    a.push(b.top());
                    b.pop();
                }
            }

            b.push(s[i]);
        }
    }


    while(!b.empty())
    {
        a.push(b.top());
        b.pop();
    }

    a.print();

    return 0;
}
