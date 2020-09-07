#include <map>
#include <vector>
#include <cstring>
#define MAX_SIZE 100001

using namespace std;

struct cmp {
    bool operator() (char const* a, char const* b) const  {
        return strcmp(a, b) < 0;
    }
};

typedef map<char*, int, cmp> nt;

void test();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++) {
        test();
    }
    return 0;
}

int getParent(int* label, int x) {
    if (label[x] == x)
        return x;
    return label[x] = getParent(label, label[x]);
}

int unionParent(int* groupSize, int* label, int a, int b) {
    a = getParent(label, a);
    b = getParent(label, b);
    if (a != b) {
        if (a > b)
            swap(a, b);
        label[b] = a;
        groupSize[a] += groupSize[b];
    }
    return groupSize[a];
}

void insert(nt* network, char* name) {
    if (network->count(name) == 0) {
        network->insert(make_pair(name, network->size() + 1));
    }
}

void test() {
    int F;
    nt network;
    int label[MAX_SIZE];
    int groupSize[MAX_SIZE];

    scanf(" %d", &F);

    for (int i = 1; i <= MAX_SIZE; i++) {
        label[i] = i;
        groupSize[i] = 1;
    }

    for (int i = 0; i < F; i++) {
        char* name1 = new char[21];
        char* name2 = new char[21];
        scanf(" %s %s", name1, name2);
        insert(&network, name1);
        insert(&network, name2);
        printf("%d\n", unionParent(groupSize, label, network[name1], network[name2]));
    }
}