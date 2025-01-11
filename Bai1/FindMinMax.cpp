#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhập số phần tử của dãy: ";
    cin >> n;

    if (n <= 0) {
        cout << "Số phần tử phải lớn hơn 0!" << endl;
        return 0;
    }

    int arr[n];
    cout << "Nhập các phần tử của dãy: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    cout << "Giá trị nhỏ nhất: " << minVal << endl;
    cout << "Giá trị lớn nhất: " << maxVal << endl; 
}