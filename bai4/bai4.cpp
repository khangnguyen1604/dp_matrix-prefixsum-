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
const int N = 505;

int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

int n, r, k;
int a[N][N], d[N][N];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> r >> k;
    FOR(i, 1, n){
        FOR(j, 1, n) cin >> a[i][j];
    }
    FOR(i, 1, k){
        int x, y;
        cin >> x >> y;
        d[x][y]++;
        d[x + r][y]--;
        d[x][y + r]--;
        d[x + r][y + r]++;
    }
    ll res = 0;
    FOR(i, 1, n){
        FOR(j, 1, n) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (d[i][j] > 0) res += a[i][j];
        }
    }
    cout << res;
    return 0;
}
