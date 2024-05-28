#include <bits/stdc++.h>
using namespace std;
#define ll long long
// ctrl + shift + b --> to run  the code on sublime text

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *head = nullptr;
Node *tail = nullptr;

void insert_end(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = value;
    node->next = nullptr;

    if (tail == nullptr)
    {
        head = node;
        tail = node;
        return;
    }

    tail->next = node;
    tail = node;
}

void insert_first(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = value;
    node->next = head;
    head = node;
}

void PrintList()
{
    Node *it = head;
    while (it)
    {
        cout << it->val << ' ';
        it = it->next;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *list;

    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);

    PrintList();

    insert_first(100);
    insert_first(1000);
    PrintList();

    return 0;
}
