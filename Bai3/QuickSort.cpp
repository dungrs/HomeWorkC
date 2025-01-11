#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && arr[left] < pivot) left++;
        while (right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu phai lon hon 0!" << endl;
        return 0;
    }

    int arr[n];
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi được sắp xếp: \n";
    printArray(arr, n);

    return 0;
}