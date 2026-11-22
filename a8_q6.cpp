#include <iostream>
using namespace std;

class PriorityQueue {
    int heap[1000];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }
    void insert(int x) {
        if (size == 1000) {
            cout << "Priority Queue is full\n";
            return;
        }

        int i = size;
        heap[size] = x;
        size++;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        cout << "Element inserted\n";
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }
        cout << "Deleted element: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        int i = 0;
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    void peek() {
        if (size == 0)
            cout << "Priority Queue is empty\n";
        else
            cout << "Highest priority element: " << heap[0] << endl;
    }
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";

        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, x;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete highest priority";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            pq.insert(x);
            break;

        case 2:
            pq.deleteMax();
            break;

        case 3:
            pq.peek();
            break;

        case 4:
            pq.display();
            break;

        case 0:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}