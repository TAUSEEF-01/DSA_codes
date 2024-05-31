// #include<bits/stdc++.h>
// using namespace std;

// struct inPostFix
// {
//     struct Stack 
//     {
//         char val;
//         Stack* next;
//     };

//     Stack* head = NULL;
//     Stack* tail = NULL;

//     void push(char ch)
//     {
//         Stack* node = (Stack*)malloc(sizeof(Stack));
//         node->val = ch;
//         node->next = NULL;

//         if(head == NULL)
//         {
//             head = tail = node;
//             return;
//         }

//         tail->next = node;
//         tail = node;
//     }

//     void pop()
//     {
//         if(head->next == NULL)
//         {
//             return;
//         }

//         Stack* node = head;
//         while(node->next != tail)
//         {
//             node = node->next;
//         }
//         tail = node;
//         tail->next = NULL;
//     }

//     char top()
//     {
//         return tail->val;
//     }

//     int precedence(char ch)
//     {
//         if(ch == '^') return 2;
//         else if(ch == '*' || ch == '/') return 1;
//         else if(ch == '+' || ch == '-') return 0;
//         else return -1;
//     }

//     char associativity(char ch)
//     {
//         if(ch == '^') return 'R';
//         else return 'L';
//     }

//     bool empty()
//     {
//         if(head->next == NULL) return true;
//         else return false;
//     }

//     void print()
//     {
//         Stack* node = head;
//         while(node)
//         {
//             cout<<node->val;
//             node = node->next;
//         }   
//         cout << endl;
//     }
// };


// int main()
// {
//     inPostFix a, b;

//     string s;
//     cin >> s;

//     b.push('@');
//     int n = s.size();

//     for(int i = 0; i < n; i++)
//     {
//         if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
//         {
//             a.push(s[i]);
//         }
//         else 
//         {
//             if(s[i] == '(')
//             {
//                 b.push(s[i]);
//                 continue;
//             }
//             else if(s[i] == ')')
//             {
//                 while(b.top() != '(' && !b.empty())
//                 {
//                     a.push(b.top());
//                     b.pop();
//                 }

//                 b.pop();
//                 continue;
//             }
//             else if(b.precedence(s[i]) <= b.precedence(b.top()))
//             {
//                 while(b.precedence(s[i]) <= b.precedence(b.top()) && !b.empty())
//                 {
//                     a.push(b.top());
//                     b.pop();
//                 }
//             }

//             b.push(s[i]);
//         }
//     }


//     while(!b.empty())
//     {
//         a.push(b.top());
//         b.pop();
//     }

//     a.print();

//     return 0;
// }










#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }

        // If an operator is scanned
        else {
            // while (!st.empty() && prec(s[i]) < prec(st.top()) ||
            //        !st.empty() && prec(s[i]) == prec(st.top()) &&
            //        associativity(s[i]) == 'L') {

            while (!st.empty() && prec(s[i]) <= prec(st.top()) && associativity(s[i]) == 'L') {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

// Driver code
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    cin >> exp;

    infixToPostfix(exp);

    return 0;
}
