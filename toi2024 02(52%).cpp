#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
int m, n;
int t, k, r;
vector<int> a;
vector<int> wd;  // wd[i] = a[i-k+1] + ... + a[i];

int main() {
    cin >> m >> n;
    if (m > MAXN or n > MAXN) return 0;
    cin >> t >> k >> r;
    a = vector<int>(n + 1, 0);
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    wd = vector<int>(n + 1);
    int sum = 0;
    for (int i = 1; i < k; i++) sum += a[i];
    for (int i = k; i <= n; i++) {
        sum += a[i];
        sum -= a[i - k];
        wd[i] = sum;
    }

    int cnt = 0;  // 總和是奇數的區間數量
    for (int i = k; i <= n; i++) {
        if (wd[i] % 2 == 1) cnt++;
    }

    int lb = max(r - k + 1, 1);  // 上緣最小可以在哪個 row
    int ub = min(m - k + 1, r);  // 上緣最大可以在哪個 row
    /*
    k*k 矩陣上緣可能在哪個 row 可以涵蓋到 r

    lb = max(r - k + 1, 1)
    ub = min(m - k + 1, r)
     */

    long long total = 1LL * (n - k + 1) * (m - k + 1);
    long long oddSquare = 1LL * cnt * (ub - lb + 1);

    if (k % 2 == 1) {
        cout << total - oddSquare << '\n';
    } else {  // k % 2 == 0
        cout << oddSquare << '\n';
    }

    return 0;
}