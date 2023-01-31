#include <iostream>

using std::cout;
using std::endl;

auto x_ = 200 * 100;
auto y_ = 200 * 100;





int &access_at(int x, int y, int* arr) {
    return arr[x + y * x_];
}

void fill_linear(int* arr) {
    int k = 0;
    for (auto j = 0; j < y_; j++) {
        for (auto i = 0; i < x_; i++) {
            access_at(i, j, arr) = k++;
        }
    }
}

int count_linear(int* arr) {
    int sum = 0;
    for (auto j = 0; j < y_; j++) {
        for (auto i = 0; i < x_; i++) {
           sum |= access_at(i, j, arr);
        }
    }
    return sum;
}


int main() {

    auto data = new int[x_ * y_];
    fill_linear(data);

    cout << count_linear(data) << endl;
}


