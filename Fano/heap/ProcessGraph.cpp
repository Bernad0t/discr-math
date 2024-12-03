#include "ProcessGraph.h"
#include <string>

vector<pair<int, int>> ProcessGraph::GetEdge(vector<int> powers)
{
    Heap heap(powers);
    vector<pair<int, int>> edges;
    vector<pair<int, int>> tmp;
    pair<int, int> current, next;
    while (!heap.heap.empty()) {
        if (heap.heap.size() == 1 && heap.heap[0].first != 0)
            throw string("unreal create graph");
        current = heap.getMax();
        int size = heap.heap.size();
        for (int k = 0; k < current.first; k++) {
            if (k == size)
                throw string("unreal create graph");
            next = heap.getMax();
            edges.push_back(pair<int, int>(current.second, next.second));
            if (next.first > 1) {
                next.first -= 1;
                tmp.push_back(next);
            }
        }
        for (int i = 0; i < tmp.size(); i++) {
            heap.AddElement(tmp[i]);
        }
        tmp.clear();
    }
    return edges;
}
