#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef struct _H {
    char* h;
    int seq;
} H;

bool operator < (H a, H b) {
    return a.seq > b.seq;
}

struct cmp {
    bool operator() (char const *a, char const *b) const {
        return strcmp(a, b) < 0;
    }
};

int main() {
    int K, L;
    scanf(" %d %d", &K, &L);
    map<char*, int, cmp> sugang;
    priority_queue<H> pq;
    for(int i = 0; i < L; i++) {
        char* hakbun = new char[9];
        scanf(" %s", hakbun);
        sugang[hakbun] = i;
    }

    for(auto & itor : sugang) {
        pq.push(H{itor.first, itor.second});
    }

    int cnt = 0;
    while (!pq.empty()) {
        if (cnt >= K)
            break;
        printf("%s\n", pq.top().h);
        pq.pop();
        cnt++;
    }

    return 0;
}
