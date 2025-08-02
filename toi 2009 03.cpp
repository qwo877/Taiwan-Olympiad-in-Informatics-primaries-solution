#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int>> a;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(make_tuple(x, y));
    }
    sort(a.begin(), a.end(), [](const tuple<int, int>& A, const tuple<int, int>& B) {
        return get<1>(A) > get<1>(B);
    });
    int t1 = 0, t2 = 0;
    for (const auto& i : a) {
        t1 += get<0>(i);
        t2 = max(t2, t1 + get<1>(i));
    }
    cout << t2 << endl;
    return 0;
}