#include <vector>

using namespace std;

int knapsack(std::vector<int> vals, std::vector<int> wts, int W)
{
    int n = vals.size();
    // Rows are items available, columns is weight available.
    std::vector<std::vector<int>> V(
        n + 1,
        std::vector<int>(W + 1)
    );
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            int val_i = vals[i];
            int wt_i = wts[i];
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            }
            else if (wt_i <= j) {
                V[i][j] = std::max(
                    V[i][j - wt_i] + val_i,
                    V[i-1][j]
                );
            }
            else {
                V[i][j] = V[i-1][j];
            }
        }
    }
    return V[n][W];
}