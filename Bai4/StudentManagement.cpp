#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
using namespace std;

// Hàm nhập danh sách sinh viên
int soLuongThemMoi;

void nhapDanhSach(map<string, vector<string>> &ds, int &n) {
    cout << "Nhập số lượng sinh viên mới: ";
    cin >> soLuongThemMoi;
    cin.ignore();

    for  (int i = 0; i < soLuongThemMoi; i++) {
        string name, date, gender, math, physics, chemistry, avgScore;

        cout << "\nNhập thông tin sinh viên thứ " << n + i + 1 << ":\n";
        cout << "Họ tên: ";
        getline(cin, name);
        cout << "Ngày sinh (dd/mm/yyyy): ";
        getline(cin, date);
        cout << "Giới tính: ";
        getline(cin, gender);

        float mathScore, physicsScore, chemistryScore;
        cout << "Điểm Toán: ";
        cin >> mathScore;
        cout << "Điểm Lý: ";
        cin >> physicsScore;
        cout << "Điểm Hóa: ";
        cin >> chemistryScore;
        cin.ignore();

        math = to_string(mathScore);
        physics = to_string(physicsScore);
        chemistry = to_string(chemistryScore);
        avgScore = to_string((mathScore + physicsScore + chemistryScore) / 3);

        ds["name"].push_back(name);        
        ds["date"].push_back(date);        
        ds["gender"].push_back(gender);        
        ds["math"].push_back(math);        
        ds["physics"].push_back(physics);        
        ds["chemistry"].push_back(chemistry);        
        ds["avgScore"].push_back(avgScore);        
    }

    n += soLuongThemMoi;
}

// Hàm in danh sách sinh viên
void inDanhSach(const map<string, vector<string>> &ds, int n) {
    cout << left << setw(25) << "Họ tên"
         << setw(15) << "Ngày sinh"
         << setw(10) << "Giới tính"
         << setw(10) << "Toán"
         << setw(10) << "Lý"
         << setw(10) << "Hóa"
         << setw(10) << "ĐTB" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(25) << ds.at("name")[i]
             << setw(15) << ds.at("date")[i]
             << setw(10) << ds.at("gender")[i]
             << setw(10) << ds.at("math")[i]
             << setw(10) << ds.at("physics")[i]
             << setw(10) << ds.at("chemistry")[i]
             << setw(10) << fixed << setprecision(2) << stof(ds.at("avgScore")[i]) << endl;
    }
}

string layTuCuoiCuaTen(const string &hoTen) {
    size_t pos = hoTen.find_last_of(' ');
    if (pos != string::npos) {
        return hoTen.substr(pos + 1);
    }
    return hoTen; // Nếu không tìm thấy khoảng trắng, trả về tên gốc
}

// Hàm sắp xếp danh sách theo từ cuối cùng của họ tên
void sapXepTheoHoTen(map<string, vector<string>> &ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string tuCuoi1 = layTuCuoiCuaTen(ds["name"][i]);
            string tuCuoi2 = layTuCuoiCuaTen(ds["name"][j]);
            if (tuCuoi1 > tuCuoi2) {
                for (auto &entry : ds) {
                    swap(entry.second[i], entry.second[j]);
                }
            }
        }
    }
}

// Hàm sắp xếp danh sách theo điểm trung bình
void sapXepTheoDTB(map<string, vector<string>> &ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stof(ds["avgScore"][i]) < stof(ds["avgScore"][j])) {
                for (auto &entry : ds) {
                    swap(entry.second[i], entry.second[j]);
                }
            }
        }
    }
}

// Main
int main() {
    map<string, vector<string>> danhSach; // Mảng lưu trữ danh sách sinh viên
    int n = 0; // Số lượng sinh viên
    int luaChon;
    bool isDataEntered = false; // Biến kiểm tra xem đã nhập dữ liệu hay chưa

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Nhập danh sách sinh viên\n";
        cout << "2. In danh sách sinh viên\n";
        cout << "3. Sắp xếp theo họ tên\n";
        cout << "4. Sắp xếp theo điểm trung bình\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn: ";
        cin >> luaChon;
        cin.ignore(); // Đọc bỏ ký tự newline sau khi nhập lựa chọn

        switch (luaChon) {
            case 1:
                nhapDanhSach(danhSach, n);
                isDataEntered = true; // Đánh dấu đã nhập dữ liệu
                break;
            case 2:
                if (isDataEntered) {
                    inDanhSach(danhSach, n);
                } else {
                    cout << "Chưa có dữ liệu sinh viên để in.\n";
                }
                break;
            case 3:
                if (isDataEntered) {
                    sapXepTheoHoTen(danhSach, n);
                    cout << "Danh sách đã được sắp xếp theo họ tên.\n";
                } else {
                    cout << "Chưa có dữ liệu để sắp xếp.\n";
                }
                break;
            case 4:
                if (isDataEntered) {
                    sapXepTheoDTB(danhSach, n);
                    cout << "Danh sách đã được sắp xếp theo điểm trung bình.\n";
                } else {
                    cout << "Chưa có dữ liệu để sắp xếp.\n";
                }
                break;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (luaChon != 0);

    return 0;
}