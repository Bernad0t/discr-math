#pragma once
#include <vector>

using namespace std;

class Heap
{
public:
	Heap(vector<int> const& values) {
		for (int i = 0; i < values.size(); i++) {
			heap.push_back(pair<int, int>(values[i], i));
		}
		createHeap();
	}
	void ChangeKey(int index, int newEl);
	pair<int, int> getMax();
	void AddElement(pair<int, int> newEl);
	vector<pair<int, int>> heap;
private:
	void Heapify(int i);
	void createHeap() {
		for (int i = (heap.size() - 1) / 2; i >= 0; i--) {
			Heapify(i);
		}
	}
	void processParent(int index) {
		pair<int, int> tmp;
		while (index >= 0 && heap[index].first > heap[index / 2].first) {
			tmp = heap[index];
			heap[index] = heap[index / 2];
			heap[index / 2] = tmp;
			index /= 2;
		}
	}
};

