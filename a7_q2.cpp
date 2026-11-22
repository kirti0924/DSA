#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;

        // Find minimum and maximum in the unsorted part
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;

            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        // Place minimum at the beginning
        swap(a[left], a[minIndex]);

        // If maximum was at left, it moved to minIndex
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum at the end
        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int a[1000], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}