#include <bits/stdc++.h>
using namespace std;

struct inPostFix
{
    struct Stack
    {
        string str;
        char val;
        Stack *next;
    };

    Stack *head = NULL;
    Stack *tail = NULL;
    

    void push(string ch)
    {
        Stack *node = (Stack *)malloc(sizeof(Stack));
        node->str = ch;
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

    string top()
    {
        return tail->str;
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

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'))
        {
            string str = "";

            str += a.top();
            str += s[i];
            a.pop();
            str += a.top();
            a.pop();
            str = "(" + str + ")";

            a.push(str);
        }
        else
        {
            string ss;
            ss.push_back(s[i]);
            a.push(ss);
        }
    }

    ans = a.top();

    n = ans.size();
    string str = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (ans[i] == ')')
            str += "(";
        else if (ans[i] == '(')
            str += ")";
        else
            str += ans[i];
    }

    cout << str << endl;

    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// bool isOperand(char x)
// {
//     return (x >= 'a' && x <= 'z') ||
//            (x >= 'A' && x <= 'Z') ||
//            (x >= '0' && x <= '9');
// }

// string getInfix(string exp)
// {
//     stack<string> s;

//     for (int i = 0; exp[i] != '\0'; i++)
//     {
//         if (isOperand(exp[i]))
//         {
//             string op(1, exp[i]);
//             s.push(op);
//         }
//         else
//         {
//             string op1 = s.top();
//             s.pop();
//             string op2 = s.top();
//             s.pop();
//             s.push("(" + op2 + exp[i] + op1 + ")");
//         }
//     }

//     return s.top();
// }

// int main()
// {
//     string exp;
//     cin >> exp;
//     cout << getInfix(exp);
//     return 0;
// }
