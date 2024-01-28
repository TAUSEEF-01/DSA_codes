#include<bits/stdc++.h>
using namespace std;

struct ListNode {
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


	node* reverseNode(node* head)
	{
		node* prev = nullptr;
		node* Next = head->next;

		while(head->next)
		{
			Next = head->next;
			head->next = prev;

			prev = head;
			head = Next;
		}
		head->next = prev;

		return head;
	}

	void removeNthFromEnd(int n) {

		node* nn = reverseNode(head);
		node* last = nn;
		node* prev = nn;
		int pos = 1;

		while(last)
		{
			if(pos == n)
			{
				prev->next = last->next;
				break;
			}
			prev = last;
			last = last->next;
			pos++;
		}

		head = reverseNode(nn);
	}
};



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	ListNode list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);

	list.removeNthFromEnd(2);
	list.printList(); 

	return 0;
}







