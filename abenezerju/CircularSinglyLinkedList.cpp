#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class CircularSinglyLinkedList {
	private:
		Node *head;
	public:
		CircularSinglyLinkedList() : head(nullptr) {}

		// Insertion at the beginning
		void insertAtBeginning(int value) {
			Node *newNode = new Node{value, nullptr};
			if (!head) {
				head = newNode;
				newNode->next = head;
			} else {
				Node *temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				newNode->next = head;
				temp->next = newNode;
				head = newNode;
			}
		}

		// Insertion at the end
		void insertAtEnd(int value) {
			Node *newNode = new Node{value, nullptr};
			if (!head) {
				head = newNode;
				newNode->next = head;
			} else {
				Node *temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->next = head;
			}
		}

		// Insertion at a specific position
		void insertAtPosition(int value, int position) {
			if (position == 1) {
				insertAtBeginning(value);
				return;
			}
			Node *newNode = new Node{value, nullptr};
			Node *temp = head;
			for (int i = 1; i < position - 1 && temp->next != head; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}

		// Deletion from the beginning
		void deleteFromBeginning() {
			if (!head)
				return;
			if (head->next == head) {
				delete head;
				head = nullptr;
			} else {
				Node *temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				Node *toDelete = head;
				head = head->next;
				temp->next = head;
				delete toDelete;
			}
		}

		// Deletion from the end
		void deleteFromEnd() {
			if (!head)
				return;
			if (head->next == head) {
				delete head;
				head = nullptr;
			} else {
				Node *temp = head;
				while (temp->next->next != head) {
					temp = temp->next;
				}
				Node *toDelete = temp->next;
				temp->next = head;
				delete toDelete;
			}
		}

		// Deletion from a specific position
		void deleteFromPosition(int position) {
			if (!head)
				return;
			if (position == 1) {
				deleteFromBeginning();
				return;
			}
			Node *temp = head;
			for (int i = 1; i < position - 1 && temp->next != head; i++) {
				temp = temp->next;
			}
			if (temp->next == head)
				return; // Invalid position
			Node *toDelete = temp->next;
			temp->next = toDelete->next;
			delete toDelete;
		}

		// Display the linked list
		void display() {
			if (!head) {
				cout << "List is empty!" << endl;
				return;
			}
			Node *temp = head;
			do {
				cout << temp->data << " -> ";
				temp = temp->next;
			} while (temp != head);
			cout << "(head)" << endl;
		}
};

int main() {
	CircularSinglyLinkedList list;
	list.insertAtBeginning(3);
	list.insertAtEnd(5);
	list.insertAtBeginning(1);
	list.insertAtPosition(2, 2);

	cout << "Linked List: ";
	list.display();

	list.deleteFromBeginning();
	cout << "After deleting from the beginning: ";
	list.display();

	list.deleteFromEnd();
	cout << "After deleting from the end: ";
	list.display();

	list.deleteFromPosition(2);
	cout << "After deleting from position 2: ";
	list.display();

	return 0;
}
