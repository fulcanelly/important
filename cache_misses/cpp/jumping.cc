#include <iostream>

using std::cout;
using std::endl;

auto x_ = 200 * 100;
auto y_ = 200 * 100;


int &access_at(int x, int y, int* arr) {
    return arr[x + y * x_];
}

void fill_jumping_(int* arr) {
    int k = 0;
    for (auto i = 0; i < x_; i++) {
        for (auto j = 0; j < y_; j++) {
            access_at(i, j, arr) = k++;
        }
    }
}

int count_jumping_(int* arr) {
    int sum = 0;
    for (auto i = 0; i < x_; i++) {
        for (auto j = 0; j < y_; j++) {
           sum |= access_at(i, j, arr);
        }
    }
    return sum;

}


int main() {
    auto data = new int[x_ * y_];

    fill_jumping_(data);

    cout << count_jumping_(data) << endl;
}
