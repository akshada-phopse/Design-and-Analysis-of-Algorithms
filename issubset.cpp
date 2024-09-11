// C++ Program for Space Optimized Dynamic Programming
// Solution to Subset Sum Problem
#include <bits/stdc++.h>
using namespace std;

// Returns true if there exists a subset in the array `setElements[]`
// with a sum equal to the target `targetSum`
bool hasSubsetWithSum(vector<int> setElements, int targetSum)
{
    int setSize = setElements.size();
    // Vectors to store the current and previous states of the subset sums
    vector<bool> previousState(targetSum + 1, false), currentState(targetSum + 1);

    // Initialize previousState[0] = true since it's always possible
    // to achieve a sum of 0 with an empty subset
    previousState[0] = true;

    // Iterate over the elements of the set and fill the state table in a bottom-up fashion
    for (int i = 1; i <= setSize; i++) {
        for (int j = 0; j <= targetSum; j++) {
            // If the current element is greater than the target sum `j`,
            // carry forward the previous state's value
            if (j < setElements[i - 1])
                currentState[j] = previousState[j];
            else
                // Otherwise, update the current state by checking if either
                // we can make the sum without the current element or by including it
                currentState[j] = (previousState[j] || previousState[j - setElements[i - 1]]);
        }
        // Update the previous state with the current state after each iteration
        previousState = currentState;
    }
    return previousState[targetSum];
}

// Driver code
int main()
{
    vector<int> setElements = { 3, 34, 4, 12, 5, 2 };
    int targetSum = 9;
    
    if (hasSubsetWithSum(setElements, targetSum))
        cout << "Found a subset with the given sum";
    else
        cout << "No subset with the given sum";
    
    return 0;
}
