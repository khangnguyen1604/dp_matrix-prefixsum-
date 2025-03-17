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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

struct object{
    int x, y, u, v, c;
};

int n, m, q;
vector <vector <ll>> a, f, g;
object b[1000005];

signed main()
{   
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1, vector <ll> (m + 1, 0));
    f.resize(n + 2, vector <ll> (m + 2, 0));
    g.resize(n + 2, vector <ll> (m + 2, 0));
    FOR(i, 1, n){
        FOR(j, 1, m) cin >> a[i][j];
    }
    cin >> q;
    FOR(i, 1, q){
        cin >> b[i].x >> b[i].y >> b[i].u >> b[i].v >> b[i].c;
        f[b[i].x][b[i].y] += b[i].c;
        f[b[i].u + 1][b[i].y] -= b[i].c;
        f[b[i].x][b[i].v + 1] -= b[i].c;
        f[b[i].u + 1][b[i].v + 1] += b[i].c;
    }
    FOR(i, 1, n){
        FOR(j, 1, m) {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            a[i][j] += f[i][j];
            g[i][j] = max(a[i][j], max(g[i - 1][j], g[i][j - 1]));
        }
    }
    FOD(i, n, 1){
        FOD(j, m, 1) {
            f[i][j] = max(a[i][j], max(f[i + 1][j], f[i][j + 1]));
        }
    }
    ll res = 1e18;
    FOR(i, 1, q){
        ll mx = g[n][m] - b[i].c;
        mx = max(mx, max(g[b[i].x - 1][m], g[n][b[i].y - 1]));
        mx = max(mx, max(f[1][b[i].v + 1], f[b[i].u + 1][1]));
        res = min(res, mx);
    }
    cout << res;
    return 0;
}
