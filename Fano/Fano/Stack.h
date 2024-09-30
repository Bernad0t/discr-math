#pragma once
#include <string>

using namespace std;

class FanoParametrs {
public:
	int startProcess;
	int endProcess;
	int doneSize;
	FanoParametrs(int startProcess, int endProcess, int doneSize);
};

class Stack {
	class Tree {
		class List {
		public:
			List() {}

			List(FanoParametrs* a);

			FanoParametrs* item;
			List* next;
		};
	public:
		List* head;
		Tree();

		void push(FanoParametrs* a);

		FanoParametrs* pop();

		bool empty();

		FanoParametrs* top();
	};
	Tree tree;
public:
	void push(FanoParametrs* a);

	FanoParametrs* pop();

	bool empty();

	FanoParametrs* top();
};
