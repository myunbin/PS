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
const int MAX = 5050; // PLZ CHK!

int n,a[MAX],d[MAX][MAX<<1];
vector<int> g[MAX],v[MAX<<1];

void dfs(int cur, int prv) {
    for (int x=2; x<(MAX<<1); x++) {
        if (a[cur]==x) continue;
        d[cur][x]=x;
    }

    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        dfs(nxt, cur);
        for (int x=2; x<(MAX<<1); x++) {
            int t=2*n;
            for (int y:v[x]) {
                t=min(t, d[nxt][y]);
            }
            d[cur][x]+=t;
        }
    }

    for (int x=2; x<(MAX<<1); x++) {
        for (int y:v[x]) {
            d[cur][y]=min(d[cur][y], d[cur][x]);
        }
    }
}

void init() {
    for (int i=2; i<(MAX<<1); i++) {
        for (int j=i; j<(MAX<<1); j+=i) {
            v[j].pb(i);
        }
    }
}

int main() {
    fio();
    init();
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<n; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    dfs(1,0);
    int ans=2*n;
    for (int i=2; i<(MAX<<1); i++) ans=min(ans, d[1][i]);

    cout<<ans;

    return 0;
}