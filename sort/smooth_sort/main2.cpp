#include <iostream>
#include <vector>

using namespace std;

// Define the Leonardo numbers
int leonardo(int k)
{
	if (k < 2) {
		return 1;
	}
	return leonardo(k - 1) + leonardo(k - 2) + 1;
}

// Build the Leonardo heap by merging
// pairs of adjacent trees
void heapify(vector<int>& arr, int start, int end)
{
	int i = start;
	int j = 0;
	int k = 0;

	while (k < end - start + 1) {
		if (k & 0xAAAAAAAA) {
			j = j + i;
			i = i >> 1;
		}
		else {
			i = i + j;
			j = j >> 1;
		}

		k = k + 1;
	}

	while (i > 0) {
		j = j >> 1;
		k = i + j;
		while (k < end) {
			if (arr[k] > arr[k - i]) {
				break;
			}
			swap(arr[k], arr[k - i]);
			k = k + i;
		}

		i = j;
	}
}

// Smooth Sort function
vector<int> smooth_sort(vector<int>& arr)
{
	int n = arr.size();

	int p = n - 1;
	int q = p;
	int r = 0;

	// Build the Leonardo heap by merging
	// pairs of adjacent trees
	while (p > 0) {
		if ((r & 0x03) == 0) {
			heapify(arr, r, q);
		}

		if (leonardo(r) == p) {
			r = r + 1;
		}
		else {
			r = r - 1;
			q = q - leonardo(r);
			heapify(arr, r, q);
			q = r - 1;
			r = r + 1;
		}

		swap(arr[0], arr[p]);
		p = p - 1;
	}

	// Convert the Leonardo heap
	// back into an array
	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j = j - 1;
		}
	}

	return arr;
}

// Driver code
int main()
{
	vector<int> arr = { 1, 7, 8, 2, 3, 5, 4, 6 };

	// Original Array
	cout << "Input: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Function call
	arr = smooth_sort(arr);

	// Sorted Array
	cout << "Output: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
