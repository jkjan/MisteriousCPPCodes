#include <iostream>
#include <vector>
#define MAX_SIZE 51
using namespace std;

int N, M;
vector<int> parties[MAX_SIZE];
vector<int> participants[MAX_SIZE];
bool knows[MAX_SIZE] = {false, };
bool visited[MAX_SIZE] = {false, };

void input();
void makeThemKnow();
int count();

int main() {
    input();
    makeThemKnow();
    printf("%d", count());
    return 0;
}

void makeVector(int partyNum) {
    int howMany, person;
    scanf(" %d", &howMany);
    for (int i = 0; i < howMany; i++) {
        scanf(" %d", &person);
        if (!partyNum) {
            knows[person] = true;
        }
        else {
            parties[person].push_back(partyNum);
            participants[partyNum].push_back(person);
        }
    }
}

void input() {
    scanf(" %d %d", &N, &M);
    makeVector(0);
    for (int i = 1; i <= M; ++i) {
        makeVector(i);
    }
}

void spreadTheWord(int spreader) {
    for (auto party : parties[spreader]) {
        if (!visited[party]) {
            visited[party] = true;
            for (auto p : participants[party]) {
                if (p != spreader) {
                    knows[p] = true;
                    spreadTheWord(p);
                }
            }
        }
    }
}

void makeThemKnow() {
    for (int i = 1; i <= N; i++) {
        if (knows[i]) {
            spreadTheWord(i);
        }
    }
}

int count() {
    int cnt = M;
    for (int i = 1; i <= M; i++) {
        for (auto p : participants[i]) {
            if (knows[p]) {
                cnt--;
                break;
            }
        }
    }
    return cnt;
}