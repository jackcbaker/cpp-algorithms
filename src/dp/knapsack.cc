/* 0-1 knapsack problem
*  Algorithm that solves the 0-1 knapsack problem.
*/

#include <vector>
#include <iostream>
#include <string>

int knapsack(const std::vector<int>& vals, const std::vector<int>& wts, int W)
{
    int n = vals.size();
    // Rows are items available, columns is weight available.
    std::vector<std::vector<int>> V(
        n + 1,
        std::vector<int>(W + 1)
    );
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            }
            else if (wts[i - 1] <= j) {
                V[i][j] = std::max(
                    V[i - 1][j - wts[i - 1]] + vals[i - 1],
                    V[i - 1][j]
                );
            }
            else {
                V[i][j] = V[i - 1][j];
            }
        }
    }
    return V[n][W];
}