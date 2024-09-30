#include "./Stack.h"

FanoParametrs::FanoParametrs(int startProcess, int endProcess, int doneSize) {
	this->startProcess = startProcess;
	this->endProcess = endProcess;
	this->doneSize = doneSize;
}

Stack::Tree::List::List(FanoParametrs* a) {
	item = a;
	next = nullptr;
}

FanoParametrs* Stack::Tree::top() {
	return head->item;
}

Stack::Tree::Tree() {
	head = nullptr;
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