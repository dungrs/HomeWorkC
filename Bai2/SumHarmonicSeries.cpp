#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double S = 0.0; 

    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai lon hon 0!" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        S += 1.0 / i;
    }

    cout << "Tong S = " << fixed << setprecision(6) << S << endl;

    return 0;
}
