#include <iostream>
#include <queue>
#define MAX_SIZE 50
#include <bitset>
using namespace std;

typedef unsigned int u_int;
typedef struct pos {
    int y, x;
}pos;
typedef struct trial {
    pos p;
    int keys, dist;
}visit;

pos operator+(pos a, pos b) {
    return pos{a.y + b.y, a.x + b.x};
}

int N, M;
char maze[MAX_SIZE][MAX_SIZE];
pos indexMover[] = {{-1, 0}, {0, 1},
                    {1, 0}, {0, -1}};

pos input();
int bfs(pos start);
bool isKey(u_int keys, char key);
u_int getKey(u_int keys, char key);
template <class T> T* get(T _2dArray[][MAX_SIZE], pos p);

int main() {
    pos minSu = input();
    printf("%d", bfs(minSu));
    return 0;
}

pos input() {
    pos minSu;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &(maze[i][j]));
            if (maze[i][j] == '0')
                minSu = {i, j};
        }
        getchar();
    }
    return minSu;
}

bool isIn(int a, int x, int b) {
    return (a <= x && x <= b);
}

bool isValid(pos p) {
    return isIn(0, p.y, N-1) && isIn(0, p.x, M-1);
}

int bfs(pos start) {
    queue<visit> willVisit;
    bool visited[64][MAX_SIZE][MAX_SIZE] = {false, };
    willVisit.push({start, 0, 0});
    while (!willVisit.empty()) {
        visit nowVisit = willVisit.front();
        willVisit.pop();

        if (*get(maze, nowVisit.p) == '1')
            return nowVisit.dist;

        for (auto m : indexMover) {
            pos adj = nowVisit.p + m;
            if (!isValid(adj) || *get(maze, adj) == '#' || *get(visited[nowVisit.keys], adj))
                continue;

            int keys = nowVisit.keys;

            *get(visited[keys], adj) = true;

            if (isIn('a', *get(maze, adj), 'f')) {
                keys = getKey(keys, *get(maze, adj));
                *get(visited[keys], adj) = true;
            }

            else if (isIn('A', *get(maze, adj), 'F')) {
                if (!isKey(keys, *get(maze, adj)))
                    continue;
            }

            willVisit.push({adj, keys, nowVisit.dist + 1});
        }
    }

    return -1;
}

u_int alphaToBits(char alpha) {
    return 1u << (u_int)(5 - (toupper(alpha) - 'A'));
}

u_int getKey(u_int keys, char key) {
    return keys | alphaToBits(key);
}

bool isKey(u_int keys, char key) {
    return keys & alphaToBits(key);
}

template <class T> T* get(T _2dArray[][MAX_SIZE], pos p) {
    return _2dArray[p.y] + p.x;
}