#Array Operations
#include <iostream>
using namespace std;

void initialize(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << "Array elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}

void disp(int a[], int n) {
    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void insert(int a[], int &n) {
    int p, k;
    cout << "Enter element to be inserted: ";
    cin >> k;
    cout << "Enter position to be inserted: ";
    cin >> p;

    if (p == 0) { // insert at beginning
        for (int i = n; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = k;
    } else if (p == n) { // insert at end
        a[n] = k;
    } else { // insert in middle
        for (int i = n; i > p; i--) {
            a[i] = a[i - 1];
        }
        a[p] = k;
    }
    n = n + 1;
}

void del(int a[], int &n, int p) {
    if (p == n - 1) { // delete last element
        n = n - 1;
    } else if (p == 0) { // delete first element
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n = n - 1;
    } else { // delete middle element
        for (int i = p; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n = n - 1;
    }
}

void delnum(int a[], int &n) {
    int d;
    cout << "Enter number to be deleted: ";
    cin >> d;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == d) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        del(a, n, pos);
    } else {
        cout << "Element not found.\n";
    }
}

void minmax(int a[], int n) {
    int min = a[0], max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    cout << "Minimum: " << min << "\n";
    cout << "Maximum: " << max << "\n";
}

int main() {
    int a[20], n, p;

    cout << "Enter the number of elements: ";
    cin >> n;

    initialize(a, n);

    cout << "Insertion:\n";
    insert(a, n);
    disp(a, n);

    cout << "Enter the index position to delete: ";
    cin >> p;
    del(a, n, p);
    disp(a, n);

    cout << "Deletion with number:\n";
    delnum(a, n);
    disp(a, n);

    cout << "Minimum and Maximum:\n";
    minmax(a, n);

    return 0;
}
