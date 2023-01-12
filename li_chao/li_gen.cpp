#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b) {
    return rng() % (b - a + 1) + a;
}


const int nmax = 100,valmax = 100000,xmax = 100000005;
int main() {
    int n = rand(1,nmax);
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        int type = rand(0,1);
        if (i == 1) {
            type = 0;
        }
        cout << type << " ";
        if (type == 0) {
            cout << rand(-valmax,valmax) << " " << rand(-valmax,valmax);
        } else {
            cout << rand(1, xmax);
        }
        cout << "\n";
    }
}