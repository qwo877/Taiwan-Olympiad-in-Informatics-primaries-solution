#include <iostream>
#include <vector>

using namespace std;

bool z(int n) {
    for (int a = 1; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int d = a + b;
            int nn = n - a * b;
            if (d == 0) continue;
            if (nn % d == 0) {
                int c = nn / d;
                if (c > b && (a * b + a * c + b * c == n)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<int> arr;
    int n = 1;
    while (arr.size() < 65) {
        if(z(n)){
            arr.push_back(n);
        }
        n++;
    }

    int k;
    cin >> k;
    cout << arr[k - 1] << endl;
    return 0;
}