#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 2;
    else if (c == '*' || c == '/')
        return 1;
    else if (c == '+' || c == '-')
        return 0;
    else
        return -1;
}

char associativity(char c)
{
    if (c == '^')
        return 'R';

    return 'L';
}

void infix_to_postfix(string s)
{
    stack<char> a; // stack of characters; not strings

    string ans;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            ans.push_back(c);
        }
        else if (c == '(')
        {
            a.push(c);
        }
        else if (c == ')')
        {
            while (a.top() != '(') // here ( this is used first bracket
            {
                ans.push_back(a.top()); // push_back a.top(); not c
                a.pop();
            }
            a.pop();
        }
        else
        {
            while (!a.empty() && (precedence(c) <= precedence(a.top())))
            {
                ans.push_back(a.top()); // push_back a.top(); not c
                a.pop();
            }
            a.push(c);
        }
    }

    while (!a.empty())
    {
        ans.push_back(a.top());
        a.pop();
    }

    cout << ans << endl;
}

int main()
{
    string s;
    cin >> s;

    infix_to_postfix(s);

    return 0;
}
