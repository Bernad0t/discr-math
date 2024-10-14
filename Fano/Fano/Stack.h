#pragma once
#include <string>

using namespace std;

class FanoParametrs {
public:
	int startProcess;
	int endProcess;
	FanoParametrs(int startProcess, int endProcess);
};

class Stack {
	class Tree {
		class List {
		public:
			List() {}

			List(FanoParametrs* a);

			~List();

			FanoParametrs* item;
			List* next;
		};
		void DeleteTree(List* tree);
	public:
		List* head;
		Tree();
		~Tree();

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
