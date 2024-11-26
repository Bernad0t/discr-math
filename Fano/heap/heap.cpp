#include "heap.h"
#include <stack>

void Heap::ChangeKey(int index, int newEl)
{
	if (newEl > heap[index].first) {
		heap[index].first = newEl;
		processParent(index);
	}
	else {
		heap[index].first = newEl;
		Heapify(index);
	}
}

pair<int, int> Heap::getMax()
{
	if (heap.size() == 0)
		return pair<int, int>();
	pair<int, int> result = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.resize(heap.size() - 1);
	Heapify(0);
	return result;
}

void Heap::AddElement(pair<int, int> newEl)
{
	heap.push_back(newEl);
	processParent(heap.size() - 1);
}

void Heap::Heapify(int i)
{
	int left, right, current;
	pair<int, int> tmp;
	bool flag = true;
	do {
		left = i * 2 + 1;
		right = i * 2 + 2;
		current = i;
		if (left < heap.size() && heap[left].first > heap[current].first) {
			current = left;
		}
		if (right < heap.size() && heap[right].first > heap[current].first) {
			current = right;
		}
		if (current != i) {
			tmp = heap[current];
			heap[current] = heap[i];
			heap[i] = tmp;
			i = current;
		}
		else
			flag = false;
	} while (flag);
}
