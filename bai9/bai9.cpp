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
const int N = 205;
const int M = 1e5 + 5;

int Rand(int l, int r){
    return (l + (rd() % (r - l + 1)));
}

struct object{
    int type, x, y, z, u, v, k, w;
};

int n, m;
object q[M];
ll a[N][N][N], bit[N][N][N];

void solve1(){
    FOR(i, 1, n){
        FOR(j, 1, n){
            FOR(k, 1, n) a[i][j][k] = 0;
        }
    }
    FOR(i, 1, m){
        if (q[i].type == 0){
            a[q[i].x][q[i].y][q[i].z] = q[i].w;
        }
        else{
            int sum = 0;
            FOR(x1, q[i].x, q[i].u)
                FOR(y1, q[i].y, q[i].v)
                    FOR(z1, q[i].z, q[i].k) sum += a[x1][y1][z1];
            cout << sum << '\n';
        }
    }
}

void solve2(){
    FOR(i, 1, n){
        FOR(j, 1, n){
            FOR(k, 1, n) a[i][j][k] = 0;
        }
    }
    int pos = m + 1;
    FOR(i, 1, m){
        if (q[i].type == 0) a[q[i].x][q[i].y][q[i].z] = q[i].w;
        else {
            pos = i;
            break;
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            FOR(k, 1, n){
                FOR(mask, 1, 7){
                    int x = i, y = j, z = k;
                    int cnt = 0;
                    if ((mask >> 0) & 1) --x, ++cnt;
                    if ((mask >> 1) & 1) --y, ++cnt;
                    if ((mask >> 2) & 1) --z, ++cnt;
                    if (cnt % 2 == 1) a[i][j][k] += a[x][y][z];
                    else a[i][j][k] -= a[x][y][z];
                }
            }
        }
    }
    FOR(i, pos, m){
        ll sum = 0;
        FOR(mask, 0, 7){
            int u = q[i].u, v = q[i].v, k = q[i].k;
            int cnt = 0;
            if ((mask >> 0) & 1) u = q[i].x - 1, ++cnt;
            if ((mask >> 1) & 1) v = q[i].y - 1, ++cnt;
            if ((mask >> 2) & 1) k = q[i].z - 1, ++cnt;
            if (cnt % 2 == 1) sum -= a[u][v][k];
            else sum += a[u][v][k];
        }
        cout << sum << '\n';
    }
}

void update_bit(int x, int y, int z, int w){
    for (; x <= n; x += x & (-x)){
        for (int y1 = y; y1 <= n; y1 += y1 & (-y1)){
            for (int z1 = z; z1 <= n; z1 += z1 & (-z1)) bit[x][y1][z1] += w;
        }
    }
}

ll get_bit(int x, int y, int z){
    ll res = 0;
    for (; x > 0; x -= x & (-x)){
        for (int y1 = y; y1 > 0; y1 -= y1 & (-y1)){
            for (int z1 = z; z1 > 0; z1 -= z1 & (-z1)) res += bit[x][y1][z1];
        }
    }
    return res;
}

void solve3(){
    FOR(i, 1, n){
        FOR(j, 1, n){
            FOR(k, 1, n) a[i][j][k] = bit[i][j][k] = 0;
        }
    }
    FOR(i, 1, m){
        if (q[i].type == 0){
            int x = q[i].x, y = q[i].y, z = q[i].z, w = q[i].w;
            update_bit(x, y, z, -a[x][y][z] + w);
            a[x][y][z] = w;
        }
        else{
            ll sum = 0;
            FOR(mask, 0, 7){
                int u = q[i].u, v = q[i].v, k = q[i].k;
                int cnt = 0;
                if ((mask >> 0) & 1) u = q[i].x - 1, ++cnt;
                if ((mask >> 1) & 1) v = q[i].y - 1, ++cnt;
                if ((mask >> 2) & 1) k = q[i].z - 1, ++cnt;
                if (cnt % 2 == 1) sum -= get_bit(u, v, k);
                else sum += get_bit(u, v, k);
            }
            cout << sum << '\n';
        }
    }
}

signed main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        FOR(i, 1, m){
            string s;
            cin >> s;
            if (s[0] == 'U') {
                q[i].type = 0;
                cin >> q[i].x >> q[i].y >> q[i].z >> q[i].w;
            }
            else {
                q[i].type = 1;
                cin >> q[i].x >> q[i].y >> q[i].z >> q[i].u >> q[i].v >> q[i].k;
            }
        }
        if (n <= 10 && m <= 1000) solve1();
        else if (n > 50) solve2();
        else
            solve3();
    }
    return 0;
}
