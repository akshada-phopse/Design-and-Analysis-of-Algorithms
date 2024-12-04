#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Function to find the unique subsets of the given array
void findUniqueSubsets(int nums[], int n)
{
    set<vector<int>> uniqueSubsets;  // To store unique subsets

    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                subset.push_back(nums[j]);
            }
        }

        // Add the subset to the set (automatically handles duplicates)
        uniqueSubsets.insert(subset);
    }

    // Print all unique subsets
   for (auto subset : uniqueSubsets) {
    cout << "{ ";
    for (auto elem : subset) {
        cout << elem << " ";
    }
    cout << "}" << endl;
    }
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    findUniqueSubsets(arr, n);
    return 0;
}
