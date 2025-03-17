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

int n, m;
int a[N][N];
ll s[N][N];

ll get(int x1, int y1, int x2, int y2){
    return (s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
}

ll solve1(){
    ll res = -1e18;
    FOR(x1, 1, n)
        FOR(y1, 1, m)
            FOR(x2, x1 + 1, n)
                FOR(y2, y1 + 1, m) res = max(res, get(x1, y1, x2, y2));
    return res;
}

ll solve2(){
    ll res = -1e18;
    FOR(y1, 1, m){
        FOR(y2, y1 + 1, m){
            ll minpf = 0;
            FOR(x2, 1, n){
                if (x2 > 2) minpf = min(minpf, s[x2 - 2][y2] - s[x2 - 2][y1 - 1]);
                res = max(res, s[x2][y2] - s[x2][y1 - 1] - minpf);
            }
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m) cin >> a[i][j];
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    cout << solve2();
    return 0;
}
