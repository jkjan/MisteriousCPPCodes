#include <iostream>
#define MAX_SIZE 100000
using namespace std;

typedef struct _d {
    int sum, till, no;
} d;

int main() {
    int N;
    d dp[MAX_SIZE];
    int mandarin[MAX_SIZE];

    scanf(" %d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %d", mandarin + i);
    }

    dp[0] = d{mandarin[0], 0, 0};

    if (mandarin[0] >= 0 && mandarin[1] >= 0)
        dp[1] = d{mandarin[0] + mandarin[1], 1, 0};
    else if (mandarin[1] >= 0) {
        dp[1] = d{mandarin[1], 1, 0};
    }
    else {
        if (mandarin[0] < mandarin[1]) {
            dp[1] = d{mandarin[1], 1, 0};
        }
        else {
            dp[1] = d{mandarin[0], 0, mandarin[1]};
        }
    }

    for (int i = 2; i < N; i++) {
        int ifAdded = dp[i-1].sum + dp[i-1].no + mandarin[i];

        if (ifAdded <= mandarin[i]) {
            dp[i] = d{mandarin[i], i, 0};
        }
        else if (ifAdded >= dp[i-1].sum) {
            dp[i] = d{ifAdded, i, 0};
        }

        else {
            int s = 0;
            for (int j = dp[i-1].till + 1; j <= i; j++) {
                s += mandarin[j];
            }
            dp[i] = d{dp[i-1].sum, dp[i-1].till, s};
        }
    }

    printf("%d", dp[N-1].sum);

    return 0;
}
