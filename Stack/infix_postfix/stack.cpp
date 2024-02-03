#include<bits/stdc++.h>
using namespace std;

// implementing stack
struct Stack
{
    struct LinkedList
    {
        int val;
        char ch;
        string str;
        LinkedList* next;
    };

    LinkedList* head = NULL;
    LinkedList* tail = NULL;

    void push(char c)
    {
        LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
        node->ch = c;
        node->next = NULL;

        if(head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void push(int v)
    {
        LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
        node->val = v;
        node->next = NULL;

        if(head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void push(string s)
    {
        LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
        node->str = s;
        node->next = NULL;

        if(head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void pop()
    {
        if(head == NULL)
            return;

        LinkedList* node = head;
        while(node->next != tail)
            node = node->next;
        
        tail = node;
        tail->next = NULL;
    }

    char top(char c = 'c')
    {
        return tail->ch;
    }   

    int top(int v = 1)
    {
        return tail->val;
    }

    string top(string s = "")
    {
        return tail->str;
    }

    bool empty()
    {
        if(head == NULL)
            return true;
        else 
            return false;
    }
};



int main()
{
    Stack stk;

    return 0;
}













// #include <bits/stdc++.h>
// using namespace std;

// struct STACK
// {
//     struct Stack
//     {
//         int val;
//         Stack *next;
//     };

//     Stack *head = NULL;
//     Stack *tail = NULL;

//     void push(int ch)
//     {
//         Stack *node = (Stack *)malloc(sizeof(Stack));
//         node->val = ch;
//         node->next = NULL;

//         if (head == NULL)
//         {
//             head = tail = node;
//             return;
//         }

//         tail->next = node;
//         tail = node;
//     }

//     void pop()
//     {
//         if (head->next == NULL)
//         {
//             return;
//         }

//         Stack *node = head;
//         while (node->next != tail)
//         {
//             node = node->next;
//         }
//         tail = node;
//         tail->next = NULL;
//     }

//     int top()
//     {
//         return tail->val;
//     }

//     bool empty()
//     {
//         if (head->next == NULL)
//             return true;
//         else
//             return false;
//     }
// };

// int main()
// {
//     STACK stk;

//     return 0;
// }
