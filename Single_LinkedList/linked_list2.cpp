#include<bits/stdc++.h>
using namespace std;

struct ll {
    struct node {
        node* next;
        int val;
    };
    node* head = nullptr;
    node* tail = nullptr;

    // Function to add a new node to the end of the linked list
    void append(int value) {
        node* new_node = new node{nullptr, value};
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Function to print the values of all nodes in the linked list
    void printList() {
        node* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    ll list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.printList(); // Output: 1 2 3

    return 0;
}
