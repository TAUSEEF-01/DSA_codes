#include<bits/stdc++.h>
using namespace std;
#define ll long long
// ctrl + shift + b --> to run  the code on sublime text

struct LinkedList
{
    struct Node 
    {
        int val; 
        Node* next;
    };

    Node* head = nullptr;
    Node* tail = nullptr;


    void insert_end(int value)
    {
        // Node* node = (Node*) malloc(sizeof(Node)); //Works fine
        Node* node = new Node{value, nullptr};
        node->val = value;
        node->next = nullptr;

        if(!tail)
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
        Node* node = (Node*) malloc(sizeof(Node));
        node->val = value;
        node->next = head;
        head = node;
    }


    void delete_first()
    {
        if(!head)
        {
            return;
        }
        head = head->next;
    }


    void delete_last()
    {
        if(!tail)
        {
            return;
        }

        Node* it = head;
        while(it->next != tail)
        {
            it = it->next;
        }

        it->next = nullptr;
    }


    void delete_node(int value)
    {
        if(head->val == value)
        {
            head = head->next;
            return;
        }

        Node* it = head;
        if(it->next->val != value)
        {
            it = it->next;
        }
        it->next = it->next->next;
    }


    void PrintList()
    {
        Node* it = head;
        while(it)
        {
            cout<<it->val<<' ';
            it = it->next;
        }
        cout<<endl;
    }

};



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin); // open input.txt of Single_LinkedList folder
    freopen("output.txt", "w", stdout); // open output.txt of Single_LinkedList folder

    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);

    list.PrintList();

    list.insert_first(100);
    list.insert_first(1000);
    list.PrintList();

    list.delete_first();
    list.PrintList();

    list.delete_last();
    list.PrintList();

    list.delete_node(2);
    list.PrintList();

    return 0;
}
