#include <bits/stdc++.h>
using namespace std;

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

int precedence(char ch)
{
    if (ch == '^')
        return 2;
    else if (ch == '*' || ch == '/')
        return 1;
    else if (ch == '+' || ch == '-')
        return 0;
    else
        return -1;
}

bool isOperand(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}

// Infix
void Infix()
{
    Stack infix, Operator;

    string s;
    cin >> s;

    string ans;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isOperand(s[i]))
        {
            ans.push_back(s[i]);
            continue;
        }
        if (s[i] == '(')
        {
            Operator.push(s[i]);
            continue;
        }
        else if (s[i] == ')')
        {
            while (Operator.top('c') != '(')
            {
                ans.push_back(Operator.top('c'));
                Operator.pop();
            }
            Operator.pop();
            continue;
        }
        else
        {
            while (!Operator.empty() && precedence(s[i]) <= precedence(Operator.top('c')))
            {
                ans.push_back(Operator.top('c'));
                Operator.pop();
            }
        }
        Operator.push(s[i]);
    }

    while (!Operator.empty())
    {
        ans.push_back(Operator.top('c'));
        Operator.pop();
    }

    cout << ans << endl;
}

// Postfix
void Postfix()
{
    Stack postfix;

    string s;
    cin >> s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isOperand(s[i]))
        {
            string temp = "";
            temp += s[i];
            postfix.push(temp);
        }
        else
        {
            // string temp = "";
            // temp += postfix.top("");
            // postfix.pop();
            // temp.push_back(s[i]);
            // temp += postfix.top("");
            // postfix.pop();

            // temp = "(" + temp + ")";

            // postfix.push(temp);

            string temp1 = "", temp2 = "", temp3 = "";
            temp1 += postfix.top("");
            postfix.pop();

            temp2.push_back(s[i]);

            temp3 += postfix.top("");
            postfix.pop();

            string temp = "";
            temp = "(" + temp3 + temp2 + temp1 + ")";

            postfix.push(temp);
        }
    }

    string ans = postfix.top("");
    cout << ans << endl;

    // int n = ans.size();
    // string str = "";
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (ans[i] == ')')
    //         str += "(";
    //     else if (ans[i] == '(')
    //         str += ")";
    //     else
    //         str += ans[i];
    // }

    // cout << str << endl;
}

// Postfix calculation
void Postfix_calc()
{
    Stack postfix_calc;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isOperand(s[i]))
        {
            postfix_calc.push(s[i] - '0');
        }
        else
        {
            ans = postfix_calc.top(1);
            postfix_calc.pop();
            if (s[i] == '+')
                ans += postfix_calc.top(1);
            else if (s[i] == '-')
                ans = postfix_calc.top(1) - ans;
            else if (s[i] == '*')
                ans *= postfix_calc.top(1);
            else if (s[i] == '/')
                ans = postfix_calc.top(1) / ans;
            else if (s[i] == '^')
                ans ^= postfix_calc.top(1);

            postfix_calc.pop();
            postfix_calc.push(ans);
        }
    }

    ans = postfix_calc.top(1);
    cout << ans << endl;
}

// Prefix
void Prefix()
{
    Stack prefix;
    string s;
    cin >> s;

    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (isOperand(s[i]))
        {
            string temp = "";
            temp += s[i];
            prefix.push(temp);
        }
        else
        {
            string temp1 = "", temp2 = "", temp3 = "";
            temp1 += prefix.top("");
            prefix.pop();

            temp2 += s[i];

            temp3 += prefix.top("");
            prefix.pop();

            string temp = "";
            temp = "(" + temp1 + temp2 + temp3 + ")";

            prefix.push(temp);
        }
    }

    string ans = prefix.top("");
    cout << ans << endl;
}

// Prefix calculation
void Prefix_calc()
{
    Stack prefix_calc;
    string s;
    cin >> s;

    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (isOperand(s[i]))
        {
            prefix_calc.push(s[i] - '0');
        }
        else
        {
            int ans = prefix_calc.top(1);
            prefix_calc.pop();
            if (s[i] == '+')
                ans += prefix_calc.top(1);
            else if (s[i] == '-')
                ans = prefix_calc.top(1) - ans;
            else if (s[i] == '*')
                ans *= prefix_calc.top(1);
            else if (s[i] == '/')
                ans = prefix_calc.top(1) / ans;
            else if (s[i] == '^')
                ans ^= prefix_calc.top(1);

            prefix_calc.pop();
            prefix_calc.push(ans);
        }
    }

    int ans = prefix_calc.top(1);
    cout << ans << endl;
}

int main()
{
    // Infix();
    // Postfix();
    // Postfix_calc();
    // Prefix();
    Prefix_calc();

    return 0;
}