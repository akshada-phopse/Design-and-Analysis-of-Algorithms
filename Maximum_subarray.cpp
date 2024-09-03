#include <iostream>
#include <vector>
#include <algorithm> // For max
#include <limits.h>  // For INT_MIN

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray(vector<int>& A, int L, int R) {
        if (L > R) return INT_MIN;

        int mid = (L + R) / 2;
        int leftSum = 0, rightSum = 0;

        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for (int i = mid - 1, curSum = 0; i >= L; i--) {
            curSum += A[i];
            leftSum = max(leftSum, curSum);
        }

        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for (int i = mid + 1, curSum = 0; i <= R; i++) {
            curSum += A[i];
            rightSum = max(rightSum, curSum);
        }

        // Return max of 3 cases 
        return max({maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R), leftSum + A[mid] + rightSum});
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSubArray(nums1);
    cout << "Maximum subarray sum is: " << result << endl;

    vector<int> nums2 = {1};
    result = sol.maxSubArray(nums2);
    cout << "Maximum subarray sum is: " << result << endl;

    vector<int> nums3 = {5, 4, -1, 7, 8};
    result = sol.maxSubArray(nums3);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
