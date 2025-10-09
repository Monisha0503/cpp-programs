#include <iostream>
using namespace std;

// ---------- Insertion Sort ----------
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------- Selection Sort ----------
void selectionSort(int arr[], int n) {
    int minIndex, temp;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ---------- Quick Sort ----------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int temp;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------- Print Array ----------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------- Main Function ----------
int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array:\n";
    printArray(arr1, n);

    insertionSort(arr1, n);
    cout << "\nAfter Insertion Sort:\n";
    printArray(arr1, n);

    selectionSort(arr2, n);
    cout << "\nAfter Selection Sort:\n";
    printArray(arr2, n);

    quickSort(arr3, 0, n - 1);
    cout << "\nAfter Quick Sort:\n";
    printArray(arr3, n);

    return 0;
}