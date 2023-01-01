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
const int MAX = 1010101; // PLZ CHK!

int m,n;
int v[MAX], f[MAX];
vector<vector<int>> c;
vector<int> g(MAX,-1), g2(MAX,-2);

void dfs(int cur, vector<int> &gr) {
    v[cur]=1;
    int nxt=gr[cur];
    if (nxt<0) {
        f[cur]=1;
        return;
    }
    if (!v[nxt]) dfs(nxt, gr);
    else {
        if (!f[nxt]) {
            c.pb({cur});
        }
    }
    f[cur]=1;
}

int nv[MAX];
void cyd(int i, int st, int cur) {
    nv[cur]=i;
    int nxt=g[cur];
    if (nxt==st) return;
    c[i].pb(nxt);
    cyd(i, st, nxt);
}

int sz[MAX];

int main() {
    fio();
    memset(nv,-1,sizeof nv);

    cin>>m>>n;
    vector<pii> ed;
    for (int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        g[u]=v;
        ed.pb({u,v});
    }    
    for (int i=0; i<n; i++) {
        if (!v[i]) dfs(i, g);
    }

    for (int i=0; i<sz(c); i++) {
        cyd(i, c[i][0], c[i][0]);
        sz[i]=sz(c[i]);
    }
    
    for (int i=0; i<n; i++) {
        if (nv[i]<0) {
            nv[i]=sz(c);
            sz[nv[i]]=1;
            c.pb({i});
        }
    }

    int ind[MAX]={0};
    for (auto [u,v]:ed) {
        u=nv[u], v=nv[v];
        if (u==v) continue;
        g2[u]=v;
        ind[v]++;
    }

    memset(v,0,sizeof v);
    for (int i=0; i<sz(c); i++) {
        if (!v[i]) dfs(i, g2);
    }

    queue<int> q;
    int d[MAX]={0};
    for (int i=0; i<n; i++) {
        if (!ind[i]) {
            q.push(i);
            d[i]=sz[i];
        }
    }

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        int nxt=g2[cur];
        if (nxt<0) continue;
        
        d[nxt]=max(d[nxt], d[cur]+sz[nxt]);
        if (--ind[nxt]==0) {
            q.push(nxt);
        }
    }

    cout<<*max_element(d,d+sz(c));

    return 0;
}