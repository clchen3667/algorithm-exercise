#include "heap_maker.h"

using namespace std;

void buildMaxHeap(vector<int>& arr, int num) {
	for (int i = num/2 -1;i >= 0;i--)
		maxHeapify(arr, num, i);
}

void maxHeapify(vector<int>& arr, int n, int idx) {
	if (idx >= n)
		return;
	int l_child = 2 * idx + 1;
	int r_child = 2 * idx + 2;
	int max;
	if (l_child < n && arr[l_child] > arr[idx]) {
		max = l_child;
	} else {
		max = idx;
	}
	if (r_child < n && arr[r_child] > arr[max]) {
		max = r_child;
	}
	if (max != idx) {
		swap(arr[max], arr[idx]);
		maxHeapify(arr, n, max);
	}
}
