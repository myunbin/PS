#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

void dfs(int curx, int cury, int n, int m, vector<vector<int>> &a, vector<vector<int>> &v) {
    v[curx][cury]=1;
    for (int i=0; i<4; i++) {
        int nxtx=curx+dx[i], nxty=cury+dy[i];
        if (0<=nxtx && nxtx<n && 0<=nxty && nxty<m) {
            if (a[nxtx][nxty] && !v[nxtx][nxty]) {
                dfs(nxtx, nxty, n, m, a, v);
            }
        }
    }
}

void solve() {
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for (int i=0; i<k; i++) {
        int y,x;
        cin>>y>>x;
        a[x][y]=1;
    }

    vector<vector<int>> v(n+1, vector<int>(m+1,0));
    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] && !v[i][j]) {
                dfs(i, j, n, m, a, v);
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}