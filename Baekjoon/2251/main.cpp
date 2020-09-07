#include <iostream>
#include <vector>
#include <set>
#define MAX_SIZE 201
using namespace std;

set<int> possibleC;
int limits[3];
void dfs(vector<int> trial);

int main() {
    scanf(" %d %d %d", limits, limits + 1, limits + 2);
    dfs({0, 0, limits[2]});
    for (auto p : possibleC)
        printf("%d ", p);
    return 0;
}

bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE] = {false, };

void fill(int* from, int* to, int limit) {
    int maxCapacity = limit - *to;
    int filling = maxCapacity > *from ? *from : maxCapacity;
    *to += filling;
    *from -= filling;
}

void fill(vector<int> trial, std::string policy) {
    int *from, *to, limit;
    for (int i = 0; i < 3; i++) {
        if (policy[i] == '1')
            from = &(trial[i]);
        else if (policy[i] == '2') {
            to = &(trial[i]);
            limit = limits[i];
        }
    }
    fill(from, to, limit);
    if (!visited[trial[0]][trial[1]][trial[2]])
        dfs(trial);
}

void dfs(vector<int> trial) {
    if (trial[0] == 0)
        possibleC.insert(trial[2]);
    visited[trial[0]][trial[1]][trial[2]] = true;
    fill(trial, "120");
    fill(trial, "102");
    fill(trial, "210");
    fill(trial, "012");
    fill(trial, "201");
    fill(trial, "021");
}