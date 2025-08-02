#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // 儲存房屋資料：座標 (a, b)，租金 r，以及房屋編號 (從 1 開始)
    vector<tuple<long long, long long, long long, int>> houses(n);
    for (int i = 0; i < n; i++) {
        long long a, b, r;
        cin >> a >> b >> r;
        houses[i] = make_tuple(a, b, r, i + 1);
    }
    
    // 儲存捷運站資料：座標 (c, d)
    vector<pair<long long, long long>> stations(m);
    for (int j = 0; j < m; j++) {
        long long c, d;
        cin >> c >> d;
        stations[j] = {c, d};
    }
    
    // 儲存計算結果： (最短距離的平方, 租金, 房屋編號)
    vector<tuple<long long, long long, int>> results(n);
    
    // 對每一間房屋計算與所有捷運站的距離，並取最小的平方距離
    for (int i = 0; i < n; i++) {
        long long a, b, r;
        int id;
        tie(a, b, r, id) = houses[i];
        long long minDist = LLONG_MAX;
        for (int j = 0; j < m; j++) {
            long long dx = a - stations[j].first;
            long long dy = b - stations[j].second;
            long long dist = dx * dx + dy * dy;
            if (dist < minDist) {
                minDist = dist;
            }
        }
        results[i] = make_tuple(minDist, r, id);
    }
    
    // 根據題目排序條件進行排序
    sort(results.begin(), results.end(), [](const auto &x, const auto &y) {
        if (get<0>(x) != get<0>(y))
            return get<0>(x) < get<0>(y); // 先依最短距離排序
        if (get<1>(x) != get<1>(y))
            return get<1>(x) < get<1>(y); // 若距離相同，依租金排序
        return get<2>(x) < get<2>(y);     // 若租金也相同，依房屋編號排序
    });
    
    // 輸出排序後的房屋編號
    for (const auto &entry : results) {
        cout << get<2>(entry) << "\n";
    }
    return 0;
}
