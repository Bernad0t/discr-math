#include "Gamilton.h"

vector<int> Gamilton::getCycle(vector<vector<int>>& matrix)
{
    if (matrix.size() == 0)
        return vector<int>();
    vector<bool> visited(matrix.size(), false);
    int current, start = 0;
    bool choosen, end = false;
    stack<pair<int, int>> myStack; // тут будет цикл. 1 эл - эл пути, 2 эл - последний попробованный вариант, когда строили путь
    myStack.push(pair<int, int>(0, 0));
    while (!end) {
        current = myStack.top().first;
        choosen = false;
        for (int i = myStack.top().second + 1; i < matrix.size(); i++) {
            if (i == start && myStack.size() == matrix.size() && matrix[current][i] == 1) { // n вершин же поучаствовали в построении цикла
                end = true;
                choosen = true;
                break;
            }
            if (i != start && !visited[i] && matrix[current][i] == 1) {
                myStack.top().second = i;
                myStack.push(pair<int, int>(i, -1));
                visited[i] = true;
                choosen = true;
                break;
            }
        }
        if (!choosen) {
            if (current == start)
                throw string("unreal create gamilton cycle");
            visited[current] = false;
            myStack.pop();
        }
    }
    if (myStack.size() != matrix.size())
        throw string("unreal create gamilton cycle");
    auto get_vector_from_stack = [&](stack<pair<int, int>> stack)->vector<int> {
        vector<int> res(stack.size());
        for (int i = 0; i < res.size(); i++) {
            res[res.size() - i - 1] = stack.top().first;
            stack.pop();
        }
        return res;
    };
    return get_vector_from_stack(myStack);
}
