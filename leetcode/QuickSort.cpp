#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int key = arr[left];
		int i = left, j = right;
		while (i < j) {
			while (arr[j] > key && i < j)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (arr[i] < key && i < j)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = key;
		QuickSort(arr, left, i - 1);
		QuickSort(arr, i + 1, right);
	}
}