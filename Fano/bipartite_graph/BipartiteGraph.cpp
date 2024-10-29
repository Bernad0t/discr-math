#include "BipartiteGraph.h"
#include <algorithm>

void ProcessPrevEl(stack<OneStep>& stackStep, bool result) {
    if (!stackStep.empty()) {
        stackStep.top().result = new bool(result);
    }
}

void BipartiteGraph::find_v2_for_v1_i() {
    for (int v1 = 0; v1 < graph.size(); v1++) {
        for (int v2 = 0; v2 < graph[0].size(); v2++) {
            if (graph[v1][v2] == 1)
                v2_for_v1_i[v1].push_back(v2);
        }
    }
}

bool BipartiteGraph::dfs(int v) {
    if (visited[v])
        return false;
    visited[v] = true;
    for (int u : v2_for_v1_i[v]) {
        // если вершина свободна, то можно сразу с ней соединиться
        // если она занята, то с ней можно соединиться только тогда,
        // когда из её текущей пары можно найти какую-нибудь другую вершину
        if (matching[u] == -1 || dfs(matching[u])) {
            matching[u] = v;
            return true;
        }
    }
    return false;
}

void BipartiteGraph::SearchAug(int v1)
{
    stack<OneStep> stackStep;
    stackStep.push(OneStep(v1, move(vector<int>(v2_for_v1_i[v1][0])), nullptr));
    bool was_created_aug;
    while (!stackStep.empty()) {
        was_created_aug = false;
        visited[stackStep.top().v1] = true;
        for (int v2 : v2_for_v1_i[stackStep.top().v1]) {
            if (stackStep.top().v2_checked.size() > 1 && find(stackStep.top().v2_checked.begin(), stackStep.top().v2_checked.end() - 1, v2) != stackStep.top().v2_checked.end() - 1)
                continue;
            if (find(stackStep.top().v2_checked.begin(), stackStep.top().v2_checked.end(), v2) == stackStep.top().v2_checked.end())
                stackStep.top().v2_checked.push_back(v2);
            bool res_is_true = stackStep.top().result != nullptr && *stackStep.top().result;
            if (matching[v2] == -1 || res_is_true) {
                matching[v2] = stackStep.top().v1; // инвертируем
                stackStep.pop();
                ProcessPrevEl(stackStep, true);
                was_created_aug = true;
                break;
            }
            else if (stackStep.top().result == nullptr) {
                if (visited[matching[v2]]) {
                    continue;
                }
                else{
                    stackStep.push(OneStep(matching[v2], move(vector<int>(v2_for_v1_i[matching[v2]][0])), nullptr));
                    was_created_aug = true;
                    break;
                }
            }
        }
        if (!was_created_aug) {
            stackStep.pop();
            ProcessPrevEl(stackStep, false);
        }
    }
}

vector<int> BipartiteGraph::GetMaxMatching()
{
    for (int u = 0; u < graph[0].size(); u++) {
        matching[u] = -1;
    }
    for (int v = 0; v < graph.size(); v++) {
        for (int w = 0; w < graph.size(); w++)
            visited[w] = false;
        SearchAug(v);
    }
    return matching;
}

vector<int> BipartiteGraph::GetMaxMatchingReq()
{
    for (int u = 0; u < graph[0].size(); u++) {
        matching[u] = -1;
    }
    for (int v = 0; v < graph.size(); v++) {
        for (int w = 0; w < graph.size(); w++)
            visited[w] = false;
        dfs(v);
    }
    return matching;
}
