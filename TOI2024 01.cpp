#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long kaprekar_process(long long num, int d) {
    set<long long> seen;  // 記錄出現過的數字
    int count = 0;   // 嘗試加入 set 的次數
    while (true) {
        if (!seen.insert(num).second){  // 如果插入失敗，表示num已存在
        return num;}
        

        // 轉成字串並補零
        string s = to_string(num);
        while (s.size() < d) s = "0" + s;  // 確保是 d 位數

        // 排序數字
        string asc = s, desc = s;
        sort(asc.begin(), asc.end());  // 升序
        sort(desc.rbegin(), desc.rend());  // 降序

        long long big = stoll(desc);
        long long small = stoll(asc);
        num = big - small;
        
    }
}

int main() {
    int n, d;
    cin >> n >> d;

    while (n--) {
        long long s;
        cin >> s;
        cout << kaprekar_process(s, d) << endl;
    }

    return 0;
}