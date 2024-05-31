#include <bits/stdc++.h>
using namespace std;

void postfix_to_infix_calc(string s)
{
    stack<int> a;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9')) // ! before ()
        {
            int value = a.top();
            a.pop();

            if (s[i] == '+')
                value += a.top();
            else if (s[i] == '-')
                value = a.top() - value; // a.top() comes first always
            else if (s[i] == '*')
                value *= a.top();
            else if (s[i] == '/')
                value = a.top() / value;
            else if (s[i] == '^')
                value = (int)pow(a.top(), value);

            a.pop();
            a.push(value);
        }
        else
        {
            a.push(s[i] - '0');
        }
    }

    cout << a.top() << endl;
}


bool isOperand(char c)
{
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
       return true;

    return false;
}

void postfix_to_infix(string s)
{
    stack<string> a;

    int n = s.size();
    for(int i=0; i<n; i++)
    {
        if(isOperand(s[i]))
        {
            string temp;
            temp.push_back(s[i]);
            a.push(temp);
        }
        else 
        {
            string temp1 = a.top();
            a.pop();
            string temp2 = a.top();
            a.pop();

            a.push("(" + temp2 + s[i] + temp1 + ")"); // temp2 first and temp1 second
        }
    }

    cout << a.top() << endl;
}

// a+b*(c^d-e)^(f+g*h)-i  ----> precedence: ^, * /, + -
// ((a+(b*(((c^d)-e)^(f+(g*h)))))-i)

int main()
{
    string s = "37^57/-34*5/+62*+"; // ((((3^7)-(5/7))+((3*4)/5))+(6*2))
    s = "abcd^e-fgh*+^*+i-"; // ((a+(b*(((c^d)-e)^(f+(g*h)))))-i)

    cin >> s;

    // postfix_to_infix_calc(s);
    postfix_to_infix(s);

    return 0;
}
