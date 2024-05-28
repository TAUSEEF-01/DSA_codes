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
    // string s = "";
    string a;
    cin >> a;

    stack<char> stk;

    generate_permutation(stk, a, a.size());

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // int cnt = 0;
// void permuteWords(string s, string word){
//     if( s.size() == word.size() ){
//         // cnt++;
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