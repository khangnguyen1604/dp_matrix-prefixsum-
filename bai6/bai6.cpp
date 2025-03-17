#define nametask ""
#include <bits/stdc++.h>
#define fi first
#define se second
#define x fi.fi
#define y fi.se
#define u se.fi
#define v se.se
#define mp make_pair
#define pb push_back
#define SZ(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

using namespace std;
typedef long long ll;
typedef pair <int, int> p2i;
typedef pair <p2i, p2i> p4i;
const int N = 505;

int n, k, r, p;
ll a[N][N];
p2i point[6];

ll get(int x1, int y1, int x2, int y2){
    if (x1 == 0 || y1 == 0) return 0;
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1]);
}

p4i hcn_chung(p4i &rec1, p4i &rec2){

    if (rec1.x > rec2.x) swap(rec1, rec2);
    if (rec1.u < rec2.x || rec1.v < rec2.y || rec2.v < rec1.y) return (mp(mp(0, 0), mp(0, 0)));
    int x1 = max(rec1.x, rec2.x), y1 = max(rec1.y, rec2.y);
    int u1 = min(rec1.u, rec2.u), v1 = min(rec1.v, rec2.v);
    return (mp(mp(x1, y1), mp(u1, v1)));
}

signed main()
{
     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> k >> r >> p;
    FOR(i, 1, n){
        FOR(j, 1, n) {
            cin >> a[i][j];
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, n) a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    ll res = 0;
    FOR(i, 1, k){
        FOR(j, 0, p - 1) cin >> point[j].fi >> point[j].se;
        ll sum = 0;
        FOR(mask, 1, (1 << p) - 1){
            p4i now = mp(mp(1, 1), mp(n, n));
            FOR(j1, 0, p - 1){
                if ((mask >> j1) & 1){
                    p4i rec = mp(mp(point[j1].fi, point[j1].se), mp(point[j1].fi + r - 1, point[j1].se + r - 1));
                    now = hcn_chung(now, rec);
                }
            }
            if (__builtin_popcount(mask) % 2 == 1) sum += get(now.x, now.y, now.u, now.v);
            else sum -= get(now.x, now.y, now.u, now.v);
        }
        res = max(res, sum);
    }
    cout << res;
    return 0;
}
