#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

class CircularDoublyLinkedList {
	private:
		Node *head;

	public:
		CircularDoublyLinkedList() : head(nullptr) {}

		void insertAtBeginning(int value) {
			Node *newNode = new Node{value, nullptr, nullptr};
			if (!head) {
				head = newNode;
				head->next = head->prev = newNode;
			} else {
				Node *tail = head->prev;
				newNode->next = head;
				newNode->prev = tail;
				head->prev = newNode;
				tail->next = newNode;
				head = newNode;
			}
		}

		void insertAtEnd(int value) {
			Node *newNode = new Node{value, nullptr, nullptr};
			if (!head) {
				head = newNode;
				head->next = head->prev = newNode;
			} else {
				Node *tail = head->prev;
				newNode->next = head;
				newNode->prev = tail;
				tail->next = newNode;
				head->prev = newNode;
			}
		}

		void insertAtPosition(int position, int value) {
			if (position == 1) {
				insertAtBeginning(value);
				return;
			}

			Node *current = head;
			for (int i = 1; i < position - 1 && current->next != head; i++) {
				current = current->next;
			}

			Node *newNode = new Node{value, current->next, current};
			current->next->prev = newNode;
			current->next = newNode;
		}

		void deleteFromBeginning() {
			if (!head)
				return;
			if (head->next == head) {
				delete head;
				head = nullptr;
				return;
			}

			Node *tail = head->prev;
			Node *temp = head;
			head = head->next;
			head->prev = tail;
			tail->next = head;
			delete temp;
		}

		void deleteFromEnd() {
			if (!head)
				return;
			if (head->next == head) {
				delete head;
				head = nullptr;
				return;
			}

			Node *tail = head->prev;
			Node *newTail = tail->prev;
			newTail->next = head;
			head->prev = newTail;
			delete tail;
		}

		void deleteFromPosition(int position) {
			if (position == 1) {
				deleteFromBeginning();
				return;
			}

			Node *current = head;
			for (int i = 1; i < position && current->next != head; i++) {
				current = current->next;
			}

			if (current->next == head)
				return;

			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}

		void display() {
			if (!head) {
				cout << "List is empty" << endl;
				return;
			}

			Node *temp = head;
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
			cout << endl;
		}
};

int main() {
	CircularDoublyLinkedList list;

	list.insertAtBeginning(10);
	list.insertAtEnd(20);
	list.insertAtEnd(30);
	list.insertAtPosition(2, 15);

	cout << "List: ";
	list.display();

	list.deleteFromBeginning();
	list.deleteFromEnd();
	list.deleteFromPosition(2);

	cout << "After deletions: ";
	list.display();

	return 0;
}
