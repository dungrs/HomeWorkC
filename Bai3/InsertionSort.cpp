#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
}

int main() {
    int n;
    do {
        cout << "\nNhập vào số lượng phần tử có trong mảng: ";
        cin >> n;
    } while (n <= 0);

    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    insertionSort(a, n);
    cout << "Mảng sau khi được sắp xếp: \n";
    printArray(a, n);

    return 0;
}