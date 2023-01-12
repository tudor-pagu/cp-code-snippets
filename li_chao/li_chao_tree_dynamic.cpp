#include <bits/stdc++.h>
#define int long long
using namespace std;


typedef long long ftype;
typedef complex<ftype> point;
const int max_x = 1000000005,inf = (1LL << 30),nmax = 200005;

ftype dot(point a, point b) {
    return (conj(a) * b).real();
}

ftype f(point a, ftype x) {
    return dot(a, {x, 1});
}

struct Li_Chao_Tree {
    vector<point> line;
    vector<pair<int,int>> kids;
    int nodes_counter = 0;
    Li_Chao_Tree() : line(4*nmax+5), kids(4*nmax+5 , {-1,-1}) {
        nodes_counter++;
        line[1] = {-inf,-inf};
    }
    void create(int &id) {
        if (id == -1) {
            id = ++nodes_counter;
            line[id] = {-inf,inf};
        }
    }
    void add_line (point nw, int node = 1, int l = 1, int r = max_x) {
        int m = (l + r) / 2;
        bool left = f(nw, l) > f(line[node], l);
        bool mid = f(nw, m) > f(line[node] , m);
        if (mid) {
            swap(line[node] , nw);
        }
        if (l >= r) {
            return;
        }
        if (left == mid) { /// intersection is to the right
            create(kids[node].second);
            add_line(nw , kids[node].second , m + 1, r);
        }  else {
            create(kids[node].first);
            add_line(nw , kids[node].first, l, m);
        }
    } 

    ftype query(int x, int node = 1, int l = 1, int r = max_x) {
        int m = (l + r) / 2;
        if (l == r) {
            return f(line[node], x);
        }

        if (x <= m) {
            create(kids[node].first);
            return max(f(line[node],x) , query(x , kids[node].first, l , m));
        } else {
            create(kids[node].second);
            return max(f(line[node],x),query(x , kids[node].second, m + 1, r));
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