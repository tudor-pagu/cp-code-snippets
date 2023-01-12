#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Line {
    int m,k;
};

int eval(Line l, int x) {
    return l.m * x + l.k;
}

int inf = (1LL << 50);

int32_t main() {
   int n;
   cin >> n;
   vector<Line> v;
   for (int i = 1; i <= n; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int m,k;
            cin >> m >> k;
            v.push_back({m,k});
        } else {
            int x;
            cin >> x;
            int maxim = -inf;
            for (auto k : v) {
                maxim = max(maxim , eval(k, x));
            }
            cout << maxim << "\n";
        }
   }
   return 0;
}