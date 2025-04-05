#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
	int data;
	Node *prev;
	Node *next;
};

// Doubly Linked List class
class DoublyLinkedList {
	private:
		Node *head;
		Node *tail;
		int size;

	public:
		DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

		// Insert at beginning
		void insertAtBeginning(int value) {
			Node *newNode = new Node{value, nullptr, head};
			if (head != nullptr) {
				head->prev = newNode;
			} else {
				tail = newNode;
			}
			head = newNode;
			size++;
			cout << "Inserted " << value << " at the beginning.\n";
		}

		// Insert at end
		void insertAtEnd(int value) {
			Node *newNode = new Node{value, tail, nullptr};
			if (tail != nullptr) {
				tail->next = newNode;
			} else {
				head = newNode;
			}
			tail = newNode;
			size++;
			cout << "Inserted " << value << " at the end.\n";
		}

		// Insert at specific position
		void insertAtPosition(int value, int position) {
			if (position < 1 || position > size + 1) {
				cout << "Invalid position. Position should be between 1 and " << size + 1 << ".\n";
				return;
			}

			if (position == 1) {
				insertAtBeginning(value);
				return;
			}

			if (position == size + 1) {
				insertAtEnd(value);
				return;
			}

			Node *current = head;
			for (int i = 1; i < position - 1; i++) {
				current = current->next;
			}

			Node *newNode = new Node{value, current, current->next};
			current->next->prev = newNode;
			current->next = newNode;
			size++;
			cout << "Inserted " << value << " at position " << position << ".\n";
		}

		// Delete from beginning
		void deleteFromBeginning() {
			if (head == nullptr) {
				cout << "List is empty. Nothing to delete.\n";
				return;
			}

			Node *temp = head;
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			} else {
				tail = nullptr;
			}
			cout << "Deleted " << temp->data << " from the beginning.\n";
			delete temp;
			size--;
		}

		// Delete from end
		void deleteFromEnd() {
			if (tail == nullptr) {
				cout << "List is empty. Nothing to delete.\n";
				return;
			}

			Node *temp = tail;
			tail = tail->prev;
			if (tail != nullptr) {
				tail->next = nullptr;
			} else {
				head = nullptr;
			}
			cout << "Deleted " << temp->data << " from the end.\n";
			delete temp;
			size--;
		}

		// Delete from specific position
		void deleteFromPosition(int position) {
			if (position < 1 || position > size) {
				cout << "Invalid position. Position should be between 1 and " << size << ".\n";
				return;
			}

			if (position == 1) {
				deleteFromBeginning();
				return;
			}

			if (position == size) {
				deleteFromEnd();
				return;
			}

			Node *current = head;
			for (int i = 1; i < position; i++) {
				current = current->next;
			}

			current->prev->next = current->next;
			current->next->prev = current->prev;
			cout << "Deleted " << current->data << " from position " << position << ".\n";
			delete current;
			size--;
		}

		// Display the list
		void display() {
			if (head == nullptr) {
				cout << "List is empty.\n";
				return;
			}

			cout << "Doubly Linked List (Size: " << size << "): ";
			Node *current = head;
			while (current != nullptr) {
				cout << current->data;
				if (current->next != nullptr) {
					cout << " <-> ";
				}
				current = current->next;
			}
			cout << "\n";
		}

		// Display the list in reverse
		void displayReverse() {
			if (tail == nullptr) {
				cout << "List is empty.\n";
				return;
			}

			cout << "Reversed Doubly Linked List: ";
			Node *current = tail;
			while (current != nullptr) {
				cout << current->data;
				if (current->prev != nullptr) {
					cout << " <-> ";
				}
				current = current->prev;
			}
			cout << "\n";
		}

		~DoublyLinkedList() {
			Node *current = head;
			while (current != nullptr) {
				Node *next = current->next;
				delete current;
				current = next;
			}
		}
};

// Main function with menu-driven interface
int main() {
	DoublyLinkedList dll;
	int choice, value, position;

	while (true) {
		cout << "\nDoubly Linked List Operations:\n";
		cout << "1. Insert at beginning\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert at specific position\n";
		cout << "4. Delete from beginning\n";
		cout << "5. Delete from end\n";
		cout << "6. Delete from specific position\n";
		cout << "7. Display list\n";
		cout << "8. Display list in reverse\n";
		cout << "9. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				dll.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				dll.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert: ";
				cin >> value;
				cout << "Enter position: ";
				cin >> position;
				dll.insertAtPosition(value, position);
				break;
			case 4:
				dll.deleteFromBeginning();
				break;
			case 5:
				dll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position to delete: ";
				cin >> position;
				dll.deleteFromPosition(position);
				break;
			case 7:
				dll.display();
				break;
			case 8:
				dll.displayReverse();
				break;
			case 9:
				cout << "Exiting program.\n";
				return 0;
			default:
				cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}