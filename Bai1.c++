#include <iostream>
#include <vector>
#include <limits.h> // Để sử dụng INT_MIN và INT_MAX

using namespace std;

int main() {
    int n;
    cout << "Nhập số lượng phần tử của dãy: ";
    cin >> n;

    if (n <= 0) {
        cout << "Số lượng phần tử phải lớn hơn 0!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Nhập " << n << " số nguyên: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minVal = INT_MAX; // Giá trị lớn nhất có thể để bắt đầu tìm Min
    int maxVal = INT_MIN; // Giá trị nhỏ nhất có thể để bắt đầu tìm Max

    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    cout << "Giá trị nhỏ nhất (Min): " << minVal << endl;
    cout << "Giá trị lớn nhất (Max): " << maxVal << endl;

    return 0;
}
