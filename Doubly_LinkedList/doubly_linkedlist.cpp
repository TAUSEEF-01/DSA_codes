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
        Node* prev;
    };

    Node* head = nullptr;
    Node* tail = nullptr;


    void insert_end(int value)
    {
        Node* node = (Node*) malloc(sizeof(Node));
        node->val = value;
        node->next = nullptr;
        node->prev = nullptr;

        if(!head)
        {
            head = node;
            tail = node;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
    }


    void insert_first(int value)
    {
        Node* node = (Node*) malloc(sizeof(Node));
        node->val = value;
        node->next = nullptr;
        node->prev = nullptr;

        if(!head)
        {
            head = node;
            tail = node;
            return;
        }

        head->prev = node;
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
        head->prev = nullptr;
    }


    void delete_last()
    {
        if(!head)
        {
            return;
        }

        tail = tail->prev;
        tail->next = nullptr;
    }


    void delete_node(int value)
    {
        if(head->val == value)
        {
            head = head->next;
            head->prev = nullptr;
            return;
        }

        Node* it = head;
        while(it->val != value)
        {
            it = it->next;
            if(!it) return;
        }

        if(it)
        {
            Node* temp = it->prev;
            temp->next = it->next;
            it = it->next;
            it->prev = temp;
        }
    }


    void PrintList_begin()
    {
        Node* it = head;
        while(it)
        {
            cout<<it->val<<' ';
            it = it->next;
        }
        cout<<endl;
    }

    void PrintList_end()
    {
        Node* it = tail;
        while(it)
        {
            cout<<it->val<<' ';
            it = it->prev;
        }
        cout<<endl;
    }

};



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);

    cout << "printing list from begining after insertion at the end: \n";
    list.PrintList_begin();

    cout << "\nprinting list from the end after insertion at the end: \n";
    list.PrintList_end();


    cout << "\nprinting list after insertion at first: \n";
    list.insert_first(100);
    list.insert_first(1000);
    list.PrintList_begin();


    cout << "\nprinting list after deleting the first element: \n";
    list.delete_first();
    list.PrintList_begin();


    cout << "\nprinting list after deleting the last element: \n";
    list.delete_last();
    list.PrintList_begin();

    cout << "\nprinting list after deleting the target node: \n";
    list.delete_node(3);
    list.PrintList_begin();


    cout << "\nprinting list from the end: \n";
    list.PrintList_end();

    list.insert_end(1000);

    cout << "\nprinting list from the begin: \n";
    list.PrintList_begin();

    cout << "\nprinting list from the end: \n";
    list.PrintList_end();


    list.delete_node(500);
    cout << "\nprinting list from the end: \n";
    list.PrintList_end();


    list.insert_end(500);
    cout << "\nprinting list from begining after insertion at the end: \n";
    list.PrintList_begin();

    return 0;
}
