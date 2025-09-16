
#include <iostream>
using namespace std;

const int MAX = 100;
int maxHeap[MAX], maxSize = 0;
int minHeap[MAX], minSize = 0;


void insertMax(int val) {
    int i = maxSize++;
    maxHeap[i] = val;
    while (i != 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(maxHeap[i], maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMax() {
    if (maxSize == 0) return -1;
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    int i = 0;
    while (true) {
        int left = 2*i + 1, right = 2*i + 2, largest = i;
        if (left < maxSize && maxHeap[left] > maxHeap[largest]) largest = left;
        if (right < maxSize && maxHeap[right] > maxHeap[largest]) largest = right;
        if (largest != i) {
            swap(maxHeap[i], maxHeap[largest]);
            i = largest;
        } else break;
    }
    return root;
}

void displayMaxHeap() {
    cout << "Max Heap: ";
    for (int i = 0; i < maxSize; ++i)
        cout << maxHeap[i] << " ";
    cout << endl;
}


void insertMin(int val) {
    int i = minSize++;
    minHeap[i] = val;
    while (i != 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(minHeap[i], minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMin() {
    if (minSize == 0) return -1;
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    int i = 0;
    while (true) {
        int left = 2*i + 1, right = 2*i + 2, smallest = i;
        if (left < minSize && minHeap[left] < minHeap[smallest]) smallest = left;
        if (right < minSize && minHeap[right] < minHeap[smallest]) smallest = right;
        if (smallest != i) {
            swap(minHeap[i], minHeap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

void displayMinHeap() {
    cout << "Min Heap: ";
    for (int i = 0; i < minSize; ++i)
        cout << minHeap[i] << " ";
    cout << endl;
}


int main() {
    int choice, val;
    while (true) {
        cout << "\n--- Heap Menu ---\n";
        cout << "1. Insert into Max Heap\n";
        cout << "2. Delete from Max Heap\n";
        cout << "3. Display Max Heap\n";
        cout << "4. Insert into Min Heap\n";
        cout << "5. Delete from Min Heap\n";
        cout << "6. Display Min Heap\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into Max Heap: ";
                cin >> val;
                insertMax(val);
                break;
            case 2:
                val = deleteMax();
                if (val == -1) cout << "Max Heap is empty.\n";
                else cout << "Deleted from Max Heap: " << val << endl;
                break;
            case 3:
                displayMaxHeap();
                break;
            case 4:
                cout << "Enter value to insert into Min Heap: ";
                cin >> val;
                insertMin(val);
                break;
            case 5:
                val = deleteMin();
                if (val == -1) cout << "Min Heap is empty.\n";
                else cout << "Deleted from Min Heap: " << val << endl;
                break;
            case 6:
                displayMinHeap();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
