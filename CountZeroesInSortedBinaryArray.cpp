// Implement a problem of number of zeroes.
// Statement: Given an array of 1s and 0s which has all 1s first 
// followed by all 0s? Find the number of 0s. Count the number of 
// zeroes in the given array.
// Input: arr[] = {1, 1, 1, 1, 0, 0} Output: 2
// Input: arr[] = {1, 0, 0, 0, 0} Output: 4

#include <bits/stdc++.h>
using namespace std;
int firstZero(int arr[], int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if ((mid == 0 || arr[mid - 1] == 1) && 
						arr[mid] == 0)
			return mid;
		if (arr[mid] == 1) 
			return firstZero(arr, (mid + 1), high);
		else
			return firstZero(arr, low, (mid -1));
	}
	return -1;
}

int countZeroes(int arr[], int n)
{
	int first = firstZero(arr, 0, n - 1);

	if (first == -1)
		return 0;

	return (n - first);
}

// Driver Code
int main()
{
	int arr[] = {1, 1, 1, 0, 0, 0, 0, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Count of zeroes is "
		<< countZeroes(arr, n);
	return 0;
}


