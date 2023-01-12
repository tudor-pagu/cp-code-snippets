#include <bits/stdc++.h>
#define int long long
using namespace std;


typedef long long ftype;
typedef complex<ftype> point;
const int nmax = 200000,inf = (1LL << 30);

ftype dot(point a, point b) {
    return (conj(a) * b).real();
}

ftype f(point a, ftype x) {
    return dot(a, {x, 1});
}

struct Li_Chao_Tree {
    vector<point> line;
    Li_Chao_Tree() : line(5*nmax+5, {-inf, -inf}) {

    }

   void add_line(point nw, int v = 1, int l = 0, int r = nmax) {
    int m = (l + r) / 2;
    bool lef = f(nw, l) > f(line[v], l);
    bool mid = f(nw, m) > f(line[v], m);
    if(mid) {
        swap(line[v], nw);
    }
    if(r - l == 1) {
        return;
    } else if(lef != mid) {
        add_line(nw, 2 * v, l, m);
    } else {
        add_line(nw, 2 * v + 1, m, r);
    }
}

    ftype query(int x, int v = 1, int l = 0, int r = nmax) {
    int m = (l + r) / 2;
    if(r - l == 1) {
        return f(line[v], x);
    } else if(x < m) {
        return max(f(line[v], x), query(x, 2 * v, l, m));
    } else {
        return max(f(line[v], x), query(x, 2 * v + 1, m, r));
    }
}
};

int32_t main() {
    int n;
    Li_Chao_Tree tree;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int m,k;
            cin >> m >> k;
            tree.add_line({m, k});
        } else {
            int x;
            cin >> x;
            cout << tree.query(x) << "\n";
        }
   }
   return 0;  
}