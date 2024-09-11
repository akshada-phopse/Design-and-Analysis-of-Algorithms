#include <bits/stdc++.h>

using namespace std;

// Returns the total distinct ways to achieve the target amount using `n` coins of
// different denominations
int countWays(vector<int>& denominations, int numCoins, int targetAmount)
{
    // 2D dp array where numCoins represents the number of coin
    // denominations and targetAmount represents the target sum
    vector<vector<int>> dp(numCoins + 1, vector<int>(targetAmount + 1, 0));

    // Base case where the targetAmount is 0, meaning there's exactly one way
    // to achieve it (by not using any coins)
    dp[0][0] = 1;

    // Fill the dp array
    for (int i = 1; i <= numCoins; i++) {
        for (int j = 0; j <= targetAmount; j++) {

            // Include the number of ways to achieve the targetAmount without using the current coin
            dp[i][j] += dp[i - 1][j];

            // If the current denomination can be used, add the ways to achieve (targetAmount - current denomination)
            if ((j - denominations[i - 1]) >= 0) {
                dp[i][j] += dp[i][j - denominations[i - 1]];
            }
        }
    }
    return dp[numCoins][targetAmount];
}

int main()
{
    vector<int> denominations{ 1, 2, 3 };
    int numCoins = 3;
    int targetAmount = 5;
    cout << countWays(denominations, numCoins, targetAmount);
    return 0;
}
