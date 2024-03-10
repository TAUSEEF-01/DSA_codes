#include <bits/stdc++.h>
using namespace std;

void generate_permutation(stack<char> stk, string a, int sz)
{
    if (stk.size() == sz)
    {
        while (!stk.empty())
        {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
        
        return;
    }
    for (int i = 0; i < sz; i++)
    {
        stack<char> temp = stk;
        temp.push(a[i]);

        generate_permutation(temp, a, sz);
    }
}

int main()
{
    string s = "";
    string a;
    cin >> a;

    stack<char> stk;

    generate_permutation(stk, a, a.size());

    return 0;
}