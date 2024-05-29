#include <bits/stdc++.h>
using namespace std;

struct LinkedList
{
    struct Node
    {
        int val;
        Node *next;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    void insertEnd(int value)
    {
        Node *node = new Node();
        node->val = value;
        node->next = nullptr;

        if (head == nullptr)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void insertBegin(int value)
    {
        Node *node = new Node();
        node->val = value;
        node->next = head;

        if (head == nullptr)
        {
            head = tail = node;
            return;
        }

        head = node;
    }

    void deleteFirstNode()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;

        free(temp);
    }

    void deleteLastNode()
    {
        if (head == nullptr)
            return;

        if (head == tail)
        {
            head = tail = nullptr;
            free(tail);
            return;
        }

        Node *node = head;
        while (node->next != tail)
        {
            node = node->next;
        }

        Node *temp = tail;
        tail = node;
        tail->next = nullptr;

        free(temp);
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
            return;

        if (head->val == value)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return;
        }

        Node *node = head;
        while (node->next != nullptr && node->next->val != value)
        {
            node = node->next;
        }

        if (node->next != nullptr && node->next->val == value)
        {
            if (node->next == tail)
            {
                Node *temp = tail;
                tail = node;
                tail->next = nullptr;
                free(temp);
            }
            else
            {
                Node *temp = node->next;
                node->next = node->next->next;
                free(temp);
            }
        }
    }

    void print()
    {
        Node *node = head;
        while (node)
        {
            cout << node->val << ' ';
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    int n;
    cin >> n;

    for (int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;
        list.insertEnd(x);
    }

    for (int i = 0; i < 2; i++)
    {
        int x;
        cin >> x;
        list.insertBegin(x);
    }

    list.print();

    list.deleteFirstNode();
    list.deleteLastNode();
    list.print();

    list.deleteNode(6);
    list.print();

    return 0;
}
