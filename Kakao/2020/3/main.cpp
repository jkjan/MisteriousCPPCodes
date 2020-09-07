#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> arr2d;

int N;
int M;
int H;

void rotate(arr2d* key) {
    arr2d temp(M, vector<int>(M));
    copy(key->begin(), key->end(), temp.begin());
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            key->at(M - 1 - j)[i] = temp[i][j];
        }
    }
}

bool isIn(arr2d* key, arr2d* lock, int startY, int startX) {
    int h = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            int lockY = startY + i;
            int lockX = startX + j;
            if (!(-1 < lockY && lockY < N && -1 < lockX && lockX < N))
                continue;
            if (key->at(i)[j] == lock->at(lockY)[lockX])
                return false;
            else {
                if (lock->at(lockY)[lockX] == 0)
                    h++;
            }
        }
    }
    return h == H;
}

bool solution(arr2d key, arr2d lock) {
    M = key.size();
    N = lock.size();
    for (auto l : lock) {
        for (auto h : l) {
            if (h == 0)
                H++;
        }
    }

    for (int i = -M + 1; i < N; ++i) {
        for (int j = -M + 1; j < N; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (isIn(&key, &lock, i, j))
                    return true;
                rotate(&key);
            }
        }
    }
    return false;
}