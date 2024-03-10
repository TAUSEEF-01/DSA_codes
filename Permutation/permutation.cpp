#include <bits/stdc++.h>
using namespace std;

void print_stk(stack<char> stk)
{
    while (!stk.empty())
    {
        char ch = stk.top();
        cout << ch;
        stk.pop();
    }
    cout << endl;
}

void generate_permutation(stack<char> stk, string voc, string a, int sz)
{
    if (stk.size() == sz)
    {
        print_stk(stk);
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        stack<char> temp = stk;
        temp.push(a[i]);

        string s = "";
        s += a[i];

        generate_permutation(temp, s, a, sz);
    }
}

int main()
{
    string a = "hello";
    stack<char> s;
    int sz = a.size();

    generate_permutation(s, "", a, sz);

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// // int cnt = 0;
// void permuteWords(string s, string word){
//     if( s.size() == word.size() ){
//         cnt++;
//         cout << s << endl;
//         return ;
//     }
//     //cout << "word is "<< word << endl;
//     for(int i = 0; i < word.size() ; i++){
//         string copy = s;
//         //cout << "copy is " << copy << endl;
//         copy += word[i];
//         permuteWords(copy, word);
//     }

// }

// int main(){
//     string word,s = "";
//     cin >> word;
//     permuteWords(s, word);
//     // cout << cnt << endl;
// }