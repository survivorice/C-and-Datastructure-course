#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
	Node(int v) : value(v), next(NULL) {}
	Node(int v, Node* link) :value(v), next(link) {}
};

class List {
public:
	List(int* arr, int array_size);
	int length() const;
	bool insert(int pos, int value);
	int find(int pos, int value);
	int remove(int value);
	bool split(int pos, List& new_list);
	void combine(List& append_list);
	void print();
	~List();
private:
	Node *head;
	int size;
};

List::List(int* arr, int array_size) {
	size = array_size;
	if (size > 0) {
		head = new Node(arr[size - 1]);
		if (size > 1) {
			for (int i = size - 2; i >= 0; i--) {
				head = new Node(arr[i], head);
			}
		}
	}
}

int List::length() const {
	return List::size;
}

bool List::insert(int pos, int value) {
	if (pos >= 0 && pos <= size) {
		if (pos == 0) {
			head = new Node(value, head);
		}
		if (pos > 0) {
			Node* p1 = head->next;
			if (pos == 1) { Node* p = new Node(value, p1); head->next = p; }
			else {
				Node* p2 = p1;
				for (int i = 2; i <= pos; i++) {
					p2 = p1;
					p1 = p1->next;
				}
				Node* p = new Node(value, p1);
				p2->next = p;
			}

		}
		size++;
		return true;
	}
	else {
		return false;
	}
}

int List::find(int pos, int value) {
	Node* p = head;
	for (int i = 0; i < pos; i++) { p = p->next; }
	bool found = false;
	while (!p == NULL) {
		if (p->value == value) {
			return pos;
			found = true;
			break;
		}
		else {
			pos++;
			p = p->next;
		}
	}
	if (!found) { return -1; }
}

int List::remove(int value) {
	int pos = find(0, value);
	int number = 0;
	while (pos != -1) {
		if (pos == 0) { head = head->next; number++; size--; }
		else {
			Node* n = head->next;
			Node* p = head;
			if (pos == 1) {
				p->next = n->next;
			}
			else {
				for (int i = 2; i <= pos; i++) {
					n = n->next;
					p = p->next;
				}
				p->next = n->next;
			}
			number++;
			size--;
		}
		pos = find(0, value);
	}
	if (number == 0) { return -1; }
	else { return number; }
}

bool List::split(int pos, List& new_list) {
	if (new_list.size != 0) { return false; }
	else {
		Node* p = head;

		if (pos >= 0 && pos < size) {
			if (pos == 0) {
				new_list.head = p->next;
				p->next = NULL;
				new_list.size = size - 1;
				size = 1;
			}
			else {
				for (int i = 1; i <= pos; i++) {
					p = p->next;
				}
				new_list.head = p->next;
				p->next = NULL;
				new_list.size = size - pos - 1;
				size = pos + 1;
			}
			return true;
		}
		else {
			return false;
		}
	}
}

void List::combine(List& append_list) {
	Node* p = head;
	for (int i = 0; i <= size - 2; i++) {
		p = p->next;
	}
	p->next = append_list.head;
	size = size + append_list.size;
}

void List::print() {
	Node* p1 = head;
	if (size == 1) {
		cout << head->value << " ";
	}
	else {
		cout << p1->value << " ";
		while (!(p1->next == NULL)) {
			p1 = p1->next;
			cout << p1->value << " ";
		}
	}
	cout << endl;
}

List::~List() {
	Node* p = head;
	while (!p == NULL) {
		head = p;
		p = p->next;
		delete head;
	}
}
