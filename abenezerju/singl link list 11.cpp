#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
	private:
		Node *head;

	public:
		SinglyLinkedList() : head(nullptr) {}

		// Insertion at the beginning
		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			newNode->next = head;
			head = newNode;
		}

		// Insertion at the end
		void insertAtEnd(int value) {
			Node *newNode = new Node(value);
			if (head == nullptr) {
				head = newNode;
				return;
			}
			Node *temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}

		// Insertion at a specific position
		void insertAtPosition(int value, int position) {
			if (position == 0) {
				insertAtBeginning(value);
				return;
			}
			Node *newNode = new Node(value);
			Node *temp = head;
			for (int i = 1; i < position && temp != nullptr; i++) {
				temp = temp->next;
			}
			if (temp == nullptr) {
				cout << "Position out of bounds!" << endl;
				return;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}

		// Deletion from the beginning
		void deleteFromBeginning() {
			if (head == nullptr) {
				cout << "List is empty!" << endl;
				return;
			}
			Node *temp = head;
			head = head->next;
			delete temp;
		}

		// Deletion from the end
		void deleteFromEnd() {
			if (head == nullptr) {
				cout << "List is empty!" << endl;
				return;
			}
			if (head->next == nullptr) {
				delete head;
				head = nullptr;
				return;
			}
			Node *temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}

		// Deletion from a specific position
		void deleteFromPosition(int position) {
			if (head == nullptr) {
				cout << "List is empty!" << endl;
				return;
			}
			if (position == 0) {
				deleteFromBeginning();
				return;
			}
			Node *temp = head;
			for (int i = 1; i < position && temp->next != nullptr; i++) {
				temp = temp->next;
			}
			if (temp->next == nullptr) {
				cout << "Position out of bounds!" << endl;
				return;
			}
			Node *deleteNode = temp->next;
			temp->next = deleteNode->next;
			delete deleteNode;
		}

		// Display the linked list
		void display() {
			if (head == nullptr) {
				cout << "List is empty!" << endl;
				return;
			}
			Node *temp = head;
			while (temp != nullptr) {
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
};

int main() {
	SinglyLinkedList list;

	// Testing the list operations
	list.insertAtBeginning(10);
	list.insertAtEnd(20);
	list.insertAtPosition(15, 1);
	list.display();

	list.deleteFromBeginning();
	list.deleteFromEnd();
	list.deleteFromPosition(0);
	list.display();

	return 0;
}
