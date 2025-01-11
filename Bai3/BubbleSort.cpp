#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++) {
        haveSwap = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                haveSwap = true;
            }
        }
        if(haveSwap == false) {
            break;
        }
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
    } while(n <= 0);

    int a[n];

    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    bubbleSort(a, n);

    cout << "Mảng sau khi được sắp xếp: \n";
    printArray(a, n);

    return 0;
}