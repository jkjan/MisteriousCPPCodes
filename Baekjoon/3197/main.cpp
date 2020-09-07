#include <iostream>
#include <queue>
#include <set>
#define MAX_SIZE 1500
#define EMPTY '.'
#define ICE 'X'
#define SWAN 'L'
using namespace std;

typedef struct pos {
    int y, x;
}pos;
typedef struct space {
    char type;
    int dist;
}space;

int R, C;
vector<pos> swan;
space lake[MAX_SIZE][MAX_SIZE];
vector<pos> toMelt[MAX_SIZE];
set<int> center;
pos deltas[] = {
        {-1 ,0}, {0, 1}, {1, 0}, {0, -1}
};

void input();
void calc();
void calc2();
void print();
char fileName[] = "large.txt";
int tikiTaka();

int main() {
    int cnt = 0;
    input();
    calc();
    calc2();
    printf("%d", tikiTaka());
    return 0;
}

inline pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}
inline bool operator==(pos a, pos b) {
    return (a.y == b.y && a.x == b.x);
}
bool isValid(pos adj) {
    return (-1 < adj.y && adj.y < R && -1 < adj.x && adj.x < C);
}

template<typename ty>
ty* get(ty arr[][MAX_SIZE], pos a) {
    return &arr[a.y][a.x];
}

void input() {
    char field;
//    FILE * fp = fopen(fileName, "rt");
    fscanf(stdin, " %d %d", &R, &C);
//    printf("%d %d\n", R, C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            fscanf(stdin, " %c", &field);
            auto ptr = get(lake, {i, j});
            ptr->type = field;
            if (field == ICE)
                ptr->dist = MAX_SIZE;
            else {
                ptr->dist = 0;
                if (field == SWAN) {
                    swan.push_back({i, j});
                }
            }
        }
    }
}

void print() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%c", get(lake, {i, j})->type);
        }
        printf("\n");
    }
}

typedef struct node {
    pos p;
    pos from;
} p;
void howManyDays(pos start) {
    queue<node> willVisit;
    bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
    willVisit.push({start, start});
    *get(*get(visited, start), {0, 0}) = true;
    while (!willVisit.empty()) {
        auto nowVisit = willVisit.front();
        willVisit.pop();
        for (auto d : deltas) {
            auto adj = nowVisit.p + d;
            if (isValid(adj)) {
                auto from = nowVisit.from;
                if (!*get(*get(visited, from), adj)) {
                    if (get(lake, nowVisit.p)->type != ICE && get(lake, adj)->type == ICE) {
                        from = nowVisit.p;
                        get(lake, adj)->dist = 1;
                    }
                }
                
            }
        }
    }

}

bool bfs(queue<pos>* willVisit, pos destination, bool visited[][MAX_SIZE]) {
    queue<pos> blocked;
    while (!willVisit->empty()) {
        pos nowVisit = willVisit->front();
        willVisit->pop();
        if (nowVisit == destination)
            return true;
        for (auto delta : deltas) {
            pos adj = nowVisit + delta;
            if (isValid(adj)) {
                if (!*get(visited, adj)) {
                    *get(visited, adj) = true;
                    if (get(lake, nowVisit)->type != ICE && get(lake, adj)->type == ICE)
                        blocked.push(adj);
                    else if (get(lake, adj)->type != ICE) {
                        willVisit->push(adj);
                    }
                }
            }
        }
    }
    while (!blocked.empty()) {
        auto temp = blocked.front();
//        printf("blocked : %d, %d\n", temp.y, temp.x);
        willVisit->push(temp);
        *get(visited, temp) = false;
        blocked.pop();
    }
    return false;
}

int tikiTaka() {
    int cnt = 0;
    queue<pos> willVisit;
    willVisit.push(swan[0]);
    bool visited[MAX_SIZE][MAX_SIZE] = {false, };
    *get(visited,swan[0]) = true;
    center.erase(0);
    for (auto c : center) {
//        print();
//        printf("\n");
        if (bfs(&willVisit, swan[1], visited)) {
//            printf("met!!!\n");
            break;
        }
        for (int i = cnt+1; i <= c; ++i) {
            for (auto t : toMelt[i]) {
                get(lake, t)->type = EMPTY;
            }
        }
        cnt = c;
    }
    return cnt;
}