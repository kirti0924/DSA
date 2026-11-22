#include <iostream>
using namespace std;

// Max heap
void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

// Min heap
void minHeapify(int a[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

// Heap sort in increasing order
void heapSortIncreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

// Heap sort in decreasing order
void heapSortDecreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }
}

int main() {
    int a[1000], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1. Increasing order";
    cout << "\n2. Decreasing order";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        heapSortIncreasing(a, n);
    else if (choice == 2)
        heapSortDecreasing(a, n);
    else {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}