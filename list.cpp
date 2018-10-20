#include <iostream>
using namespace std;
#include "list.h"

list::list() {
	head = nullptr;
	current = nullptr;
}

list::~list() {
	while (head) {
		node *t = head->next;
		delete head;
		head = t;
	};
}

void list::insert(int a) {
	node *t = new node;
	t->next = head;
	head = t;
	head->val = a;
}

void list::goToHead() {
	current = head;
}

int list::getCurrentData() {
	return current->val;
}

void list::advance() {
	current = current->next;
}

bool list::moreData() {
	if (current)
		return true;
	else
		return false;
}

list::list(const list &l) {
	head = nullptr; // default constructor step#1
	current = nullptr; // default constructor step#2
	node *src, **dst;
	src = l.head; // source pointer set to the first node of the list
	dst = &head;
	while (src) { // terminates after last node is copied
		*dst = new node;
		(*dst)->val = src->val; // copying the value from the source node
		(*dst)->next = nullptr;
		if (src == l.current)
			current = *dst; // setting current so that it points to the same node
		src = src->next; // src pointer incrementation
		dst = &((*dst)->next); // dst pointer incrementation
	}
}

list & list::operator=(const list &l) {
	if (&l == this)
		return *this;

	current = nullptr;
	node *src, **dst;
	src = l.head;
	dst = &head;

	while (src) {
		if (!(*dst)) {
			*dst = new node;
			(*dst)->next = nullptr;
		}
		(*dst)->val = src->val;

		if(src == l.current)
			current = *dst;

		src = src->next;
		dst = &((*dst)->next);
	}

	while (*dst) {
		node *remaining = (*dst)->next;
		delete *dst;
		*dst = remaining;
	}

	return *this;
}