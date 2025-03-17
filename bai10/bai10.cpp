#define nametask ""
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

using namespace std;
typedef long long ll;
typedef pair <int, int> pi;
const int N = 41;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());


int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

int n, m, p, q, numT;
ll a[N][N][N][N];

signed main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> m >> p >> q;
    FOR(i, 1, n){
        FOR(j, 1, m){
            FOR(k, 1, p){
                FOR(h, 1, q) cin >> a[i][j][k][h];
            }
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            FOR(k, 1, p){
                FOR(h, 1, q){
                    FOR(mask, 1, 15){
                        int x = i, y = j, z = k, t = h;
                        int cnt = 0;
                        if ((mask >> 0) & 1) --x, ++cnt;
                        if ((mask >> 1) & 1) --y, ++cnt;
                        if ((mask >> 2) & 1) --z, ++cnt;
                        if ((mask >> 3) & 1) --t, ++cnt;
                        if (cnt % 2 == 1) a[i][j][k][h] += a[x][y][z][t];
                        else a[i][j][k][h] -= a[x][y][z][t];
                    }
                }
            }
        }
    }
    cin >> numT;
    FOR(i, 1, numT){
        int x1, y1, z1, t1, x2, y2, z2, t2;
        cin >> x1 >> y1 >> z1 >> t1 >> x2 >> y2 >> z2 >> t2;
        ll sum = 0;
        FOR(mask, 0, 15){
            int x = x2, y = y2, z = z2, t = t2;
            int cnt = 0;
            if ((mask >> 0) & 1) x = x1 - 1, ++cnt;
            if ((mask >> 1) & 1) y = y1 - 1, ++cnt;
            if ((mask >> 2) & 1) z = z1 - 1, ++cnt;
            if ((mask >> 3) & 1) t = t1 - 1, ++cnt;
            if (cnt % 2 == 1) sum -= a[x][y][z][t];
            else sum += a[x][y][z][t];
        }
        cout << sum << '\n';
    }
    return 0;
}
