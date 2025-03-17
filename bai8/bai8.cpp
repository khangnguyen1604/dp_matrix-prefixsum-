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
const int N = 2505;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

int n;
pi a[N];
int s[N][N];

int get(int x1, int y1, int x2, int y2){
    return (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n;
    vector <int> x, y;
    FOR(i, 0, n - 1){
        cin >> a[i].fi >> a[i].se;
        x.pb(a[i].fi);
        y.pb(a[i].se);
    }
    sort(all(x));
    sort(all(y));
    FOR(i, 0, n - 1){
        a[i].fi = lower_bound(all(x), a[i].fi) - x.begin() + 1;
        a[i].se = lower_bound(all(y), a[i].se) - y.begin() + 1;
        s[a[i].fi][a[i].se]++;
    }
    FOR(i, 1, n){
        FOR(j, 1, n) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
    ll res = 1;
    FOR(i, 0, n - 1){
        FOR(j, i, n - 1){
            int x1 = a[i].fi, y1 = a[i].se, x2 = a[j].fi, y2 = a[j].se;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            res += 1LL * get(x1, 1, x2, y1) * get(x1, y2, x2, n);
        }
    }
    cout << res;
    return 0;
}
