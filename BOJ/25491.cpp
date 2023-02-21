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
const int MAX = 303030; // PLZ CHK!

vector<int> g[MAX];
int n,s,p[MAX][21], d[MAX], a[MAX], b[MAX], cnt[1<<20], xr[MAX];
set<int> mex;

void dfs(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        d[nxt]=d[cur]+1;
        p[nxt][0]=cur;
        dfs(nxt, cur);
    }
}

int lca(int u, int v) {
    if (d[u]>d[v]) swap(u,v); // d[u]<=d[v]
    for (int i=20; i>=0; i--) if (d[p[v][i]]>=d[u]) v=p[v][i];
    if (u==v) return u;
    for (int i=20; i>=0; i--) if (p[u][i]!=p[v][i]) u=p[u][i], v=p[v][i];
    return p[v][0];
}

void dfsx(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        dfsx(nxt, cur);
        xr[cur]^=xr[nxt];
    }    
}

void dfsm(int cur, int prv) {
    int v=a[cur]^xr[cur];
    if (cnt[v]==0) {
        mex.erase(v);
    }    
    cnt[v]++;
    b[cur]=*mex.begin();

    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        dfsm(nxt, cur);
    }

    cnt[v]--;
    if (cnt[v]==0) {
        mex.insert(v);
    }
}

int main() {
    fio();
    cin>>n>>s;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    d[s]=1, dfs(s,0);
    for (int j=1; j<=20; j++) {
        for (int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }

    int m;
    cin>>m;
    while (m--) {
        int x,y,z;
        cin>>x>>y>>z;
        int l=lca(x,y);
        // cout<<x<<sp<<y<<sp<<l<<sp<<p[l][0]<<endl;
        xr[x]^=z, xr[y]^=z, xr[l]^=z, xr[p[l][0]]^=z;
    }

    dfsx(s,0);

    for (int i=0; i<=(1<<20); i++) mex.insert(i);
    dfsm(s,0);

    for (int i=1; i<=n; i++) cout<<b[i]<<sp;
    return 0;
}