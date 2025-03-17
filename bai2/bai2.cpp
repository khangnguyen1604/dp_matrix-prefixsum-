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
const int N = 1005;

int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

int n, k;
int a[N][N], s[N][N];

int get(int x1, int y1, int x2, int y2){
    return (s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (fopen(nametask".inp", "r")){
        freopen(nametask".inp", "r", stdin);
        freopen(nametask".out", "w", stdout);
    }
    cin >> n >> k;
    FOR(i, 1, n){
        FOR(j, 1, n) cin >> a[i][j];
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int res = 0;
    FOR(i, k, n){
        FOR(j, k, n){
            res = max(res, get(i - k + 1, j - k + 1, i, j));
        }
    }
    cout << res;
    return 0;
}
