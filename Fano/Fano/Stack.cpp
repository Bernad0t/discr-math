#include "./Stack.h"

FanoParametrs::FanoParametrs(int startProcess, int endProcess) {
	this->startProcess = startProcess;
	this->endProcess = endProcess;
}

Stack::Tree::List::List(FanoParametrs* a) {
	item = a;
	next = nullptr;
}

Stack::Tree::List::~List() {
	delete item;
}

FanoParametrs* Stack::Tree::top() {
	return head->item;
}

Stack::Tree::Tree() {
	head = nullptr;
}

void Stack::Tree::DeleteTree(List* tree){
	if (tree == nullptr)
		return;
	DeleteTree(tree->next);
	delete tree;
}

Stack::Tree::~Tree() {
	DeleteTree(head);
}

void Stack::Tree::push(FanoParametrs* a) {
	List* newHead = new List;
	newHead->next = head;
	newHead->item = a;
	head = newHead;
}

FanoParametrs* Stack::Tree::pop() {
	List* tmpHead = head;
	head = head->next;
	return tmpHead->item;
}

bool Stack::Tree::empty() {
	return head == nullptr;
}

void Stack::push(FanoParametrs* a) {
	tree.push(a);
}

FanoParametrs* Stack::pop() {
	return tree.pop();
}

bool Stack::empty() {
	return tree.empty();
}

FanoParametrs* Stack::top() {
	return tree.top();
}