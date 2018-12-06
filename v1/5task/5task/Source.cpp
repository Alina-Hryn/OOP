#include <iostream>
#include <cstdlib>

using namespace std;


struct Node {
	Node * next;
	int data;
};

struct List {
	Node* begin;
	Node* end;
	int length;
};

List* create_list() {
	List* result = new List;
	Node * node = new Node;
	node->next = nullptr;
	result->begin = nullptr;
	result->end = nullptr;
	result->length = 0;

	return result;
}

Node* append(List* lst, int data) {
	Node * add = new Node;
	add->data = data;

	if (lst->length == 0) {
		lst->begin = add;
		lst->end = add;
	}
	else {
		lst->end->next = add;
		lst->end = add;

	}
	add->next = nullptr;
	lst->length++;
	return add;

}

void remove(List* lst, Node* todelete) {
	Node* node = lst->begin;
	if (todelete == lst->begin) {
		node = node->next;
		lst->begin = node;
		delete todelete;
	}
	while (node) {
		if (node->next == todelete) {
			node->next = todelete->next;
			if (todelete == lst->end) {
				lst->end = node;
			}
			delete todelete;

		}

		node = node->next;
	}
}

void deleteList(List* lst) {
	Node* node = lst->begin;
	Node* a = lst->begin;
	while (node) {
		a = node;
		remove(lst, a);
		node = node->next;
	}
}

void printNode(Node* el) {
	cout << el->data << endl;
}

Node* find_by_index(List* lst, int index) {
	Node* el = lst->begin;
	for (int i = 0; i < index; i++) {
		el = el->next;
	}
	return el;

}

void show_list(List* list) {
	Node * node = list->begin;
	while (node) {
		cout << node->data ;
		if (node->next) { cout << " "; }
		node = node->next;
	}
	cout  << endl;
}

void new_list(List* list, int N) {
	List* list2 = create_list();
	Node * node = list->begin;
	while (node) {
		if (node->data >= N) {	
			int a = node->data;
			
			Node* newdata = append(list2, a);
			remove(list, node);
		}
		node = node ->next;
	}
	cout << "first list:";
	show_list(list);
	cout << "second list:";
	show_list(list2);
	deleteList(list);
	deleteList(list2);

}






int main() {
	List* list = create_list();
	Node* first = append(list, 11);
	show_list(list);
	Node* second = append(list, 22);
	show_list(list);
	Node* third = append(list, 31);
	show_list(list);
	Node* fourth = append(list,44);
	show_list(list);
	remove(list, second);
	show_list(list);
	int N;
	cin >> N;
	new_list(list, N);
	
	system("pause");
	return 0;
}

