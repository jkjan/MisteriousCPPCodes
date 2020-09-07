#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> stock;

int stockPairs(vector<int> stocksProfit, long target);

int main() {
    vector<int> stocksProfit;
    stocksProfit.push_back(6);
    stocksProfit.push_back(12);
    stocksProfit.push_back(3);
    stocksProfit.push_back(9);
    stocksProfit.push_back(5);
    stocksProfit.push_back(1);
    printf("%d", stockPairs(stocksProfit, 12));
    return 0;
}

int stockPairs(vector<int> stocksProfit, long target) {
    set<stock> dupCheck;
    int cnt = 0;
    int size = stocksProfit.size();
    for (int i = 0; i < size-1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (stocksProfit[i] + stocksProfit[j] == target) {
                if (!dupCheck.count({stocksProfit[i], stocksProfit[j]})) {
                    cnt++;
                    dupCheck.insert({stocksProfit[i], stocksProfit[j]});
                }
            }
        }
    }
    return cnt;
}
