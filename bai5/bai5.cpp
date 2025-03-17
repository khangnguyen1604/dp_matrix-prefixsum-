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

int n, m, k;
ll s[N][N];

ll get(int x1, int y1, int x2, int y2){
    return (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
}

ll bs1(int y1, int y2, int x1, int x2){
    int l = y1, r = y2 - 1;
    ll res = 1e18;
    ll sum = get(x1, y1, x2, y2);
    while (l <= r){
        int mid = (l + r) / 2;
        ll val = get(x1, y1, x2, mid);
        res = min(res, abs(sum - 2LL * val));
        if (sum - 2LL * val > 0) {

            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

ll bs2(int x1, int x2, int y1, int y2){
    int l = x1, r = x2 - 1;
    ll res = 1e18;
    ll sum = get(x1, y1, x2, y2);
    while (l <= r){
        int mid = (l + r) / 2;
        ll val = get(x1, y1, mid, y2);
        res = min(res, abs(sum - 2LL * val));
        if (sum - 2LL * val > 0) {

            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

void solve(){
    FOR(i, 1, k){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << min(bs1(y1, y2, x1, x2), bs2(x1, x2, y1, y2)) << '\n';
    }
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
        FOR(j, 1, m) {
            int x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }
    solve();
    return 0;
}
