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
const int N = 1005;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

int n, m, k, q;
ll a[N][N], s[N][N];

ll get(int x1, int y1, int x2, int y2){
    return (a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> m >> k;
    FOR(i, 1, n){
        FOR(j, 1, m) cin >> a[i][j];
    }
    cin >> q;
    FOR(i, 1, q){
        int x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        s[x1][y1] += w;
        s[x2 + 1][y1] -= w;
        s[x1][y2 + 1] -= w;
        s[x2 + 1][y2 + 1] += w;
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + s[i][j];
        }
    }
    ll res = -1e18;
    FOR(i, k, n){
        FOR(j, k, m){
            res = max(res, get(i - k + 1, j - k + 1, i, j));
        }
    }
    cout << res;
    return 0;
}
