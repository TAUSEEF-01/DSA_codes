#include <bits/stdc++.h>
using namespace std;

struct LinkedList
{
    struct node
    {
        int val;
        node *next;
        node *prev;
    };

    node *head = NULL;
    node *tail = NULL;

    void push_front(int value)
    {
        node *Node = (node *)malloc(sizeof(node));
        Node->val = value;
        Node->next = head;
        Node->prev = NULL;
        if (head == NULL)
        {
            head = tail = Node;
            return;
        }

        head->prev = Node;
        head = Node;
    }

    void push_back(int value)
    {
        node *Node = (node *)malloc(sizeof(node));
        Node->val = value;
        Node->next = NULL;
        Node->prev = tail;
        if (head == NULL)
        {
            head = tail = Node;
            return;
        }

        tail->next = Node;
        tail = Node;
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        head = head->next;
        head->prev = NULL;
    }

    void pop_back()
    {
        if (tail == NULL)
            return;

        tail = tail->prev;
        tail->next = NULL;
    }

    void delete_node(int target)
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->val == target)
        {
            head = head->next;
            head->prev = NULL;
            return;
        }

        node *it = head;
        while (it->next->val != target)
        {
            it = it->next;
        }

        if (it->next == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            return;
        }

        node *temp = it->next->next;
        it->next = it->next->next;
        it = it->next;
        it->prev = temp->prev->prev;
    }

    void reverse()
    {
        if (head == NULL)
            return;

        node *Next = head->next;
        node *Prev = NULL;

        while (head->next != NULL)
        {
            Next = head->next;
            head->next = Prev;

            Prev = head;
            head = Next;
        }

        head->next = Prev;

        Next = tail;
        Prev = NULL;
        while (tail->prev != NULL)
        {
            Next = tail->prev;
            tail->prev = Prev;

            Prev = tail;
            tail = Next;
        }

        tail->prev = Prev;
    }

    void reverse_stack()
    {
        stack<int> st;
        node *temp = head;
        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
    }

    void print_begin()
    {
        node *it = head;
        while (it != NULL)
        {
            cout << it->val << ' ';
            it = it->next;
        }
        cout << endl;
    }

    void print_end()
    {
        node *it = tail;
        while (it != NULL)
        {
            cout << it->val << ' ';
            it = it->prev;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list.push_back(x);
    }

    list.push_back(100);

    cout << "Printing list after push_front and push_back operation" << endl;
    list.print_begin();
    list.print_end();
    cout << endl;

    cout << "Printing list after pop_back operation" << endl;
    list.pop_back();
    list.print_begin();
    list.print_end();
    cout << endl;

    cout << "Printing list after pop_front operation" << endl;
    list.pop_front();
    list.print_begin();
    list.print_end();
    cout << endl;

    cout << "Printing list after delete_node operation" << endl;
    list.delete_node(5);
    list.print_begin();
    list.print_end();
    cout << endl;

    list.push_back(8);
    list.push_front(1);
    cout << "updated list" << endl;
    list.print_begin();
    list.print_end();
    cout << endl;

    cout << "Printing list after 1st node deletion operation" << endl;
    list.delete_node(1);
    list.print_begin();
    list.print_end();
    cout << endl;

    cout << "Printing list after last node deletion operation" << endl;
    list.delete_node(8);
    list.print_begin();
    list.print_end();
    cout << endl;

    cout << "Printing list after reverse" << endl;
    list.reverse();
    list.print_begin();
    list.print_end();
    cout << endl;

    // cout << "Printing list after reverse_stack" << endl;
    // list.reverse_stack();
    // list.print_begin();
    // list.print_end();
    // cout << endl;

    return 0;
}
