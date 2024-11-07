# Quadratic time complexity -	O(n^2)

The example in lesson 4  illustrates an algorithm with quadratic time complexity, where the running time increases quadratically with the input size

* The function `printPairs` uses two nested loops, each iterating through the array. 
* The number of clock cycles required grows quadratically with the size of the array.


### Another Example - Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

```C++ 

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

```

# Output
```
Sorted array:
11 12 22 25 34 64 90
```

# Time Complexity
- Worst and Average Case Time Complexity: O(n^2). Worst case occurs when array is reverse sorted.
- Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
- Auxiliary Space: O(1)
- Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
- Sorting In Place: Yes
- Stable: Yes
- Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
- In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n).
- The only significant advantage that bubble sort has over most other algorithms, even quicksort, but not insertion sort, is the ability to detect if the list is already sorted.
- When the list is already sorted (best-case), the complexity of bubble sort is only O(n). By contrast, most other algorithms, even those with better average-case complexity, perform their entire sorting process on the set and thus are more complex. However, not only does insertion sort have this property, but it also has better average-case complexity than bubble sort.
