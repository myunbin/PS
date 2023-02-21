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
const int MAX = 202020; // PLZ CHK!

map<pii,pil> ed; // (u,v) (idx, val)
vector<int> g[MAX];
int v[MAX], f[MAX], p[MAX][21], d[MAX];
vector<int> cy;
int n,m;
pii cc;
void dfs(int cur) {
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) {
            if (!f[nxt] && p[cur][0]!=nxt) cc={cur,nxt};
            continue;
        }
        d[nxt]=d[cur]+1;
        p[nxt][0]=cur;
        dfs(nxt);
    }
    f[cur]=1;
}

void inl() {
    for (int j=1; j<=20; j++) {
        for (int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v) {
    if (d[u]>d[v]) swap(u,v);
    for (int i=20; i>=0; i--) if (d[p[v][i]]>=d[u]) v=p[v][i];
    if (u==v) return u;
    for (int i=20; i>=0; i--) if (p[v][i]!=p[u][i]) v=p[v][i], u=p[u][i];
    return p[v][0];    
}

void dfs2(int cur) {
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        dfs2(nxt);
        pii ec={min(cur,p[cur][0]), max(cur,p[cur][0])};
        pii en={min(nxt,p[nxt][0]), max(nxt,p[nxt][0])};
        ed[ec].S+=ed[en].S;
    }
}

void cyc(int st, int cur) {
    cy.pb(cur);
    if (st==cur) return;
    cyc(st, p[cur][0]);
}

int main() {
    fio();
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        int a,b; 
        cin>>a>>b;
        pii e={min(a,b), max(a,b)};
        ed[e]={i,0};
        g[a].pb(b), g[b].pb(a);
    }

    d[1]=1;
    dfs(1);
    inl();

    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        int l=lca(u,v);

        pii e1={min(u,p[u][0]), max(u,p[u][0])};
        pii e2={min(v,p[v][0]), max(v,p[v][0])};
        pii e3={min(l,p[l][0]), max(l,p[l][0])};
        ed[e1]={ed[e1].F, ed[e1].S+1ll*w};
        ed[e2]={ed[e2].F, ed[e2].S+1ll*w};
        ed[e3]={ed[e3].F, ed[e3].S-2ll*w};
    }
    
    fill(v,v+MAX, 0);
    dfs2(1);
    cyc(cc.S, cc.F);

    ll cv=0;
    for (int i=0; i<sz(cy); i++) {
        int u=cy[i], v=cy[(i+1)%sz(cy)];
        pii e={min(u,v), max(u,v)};
        cv+=ed[e].S;
    }
    for (int i=0; i<sz(cy); i++) {
        int u=cy[i], v=cy[(i+1)%sz(cy)];
        pii e={min(u,v), max(u,v)};
        ed[e].S=cv;
    }

    ll ans[MAX];
    for (auto [p1, p2]:ed) {
        auto [idx,v]=p2;
        ans[idx]=v;
    }

    for (int i=1; i<=n; i++) cout<<ans[i]<<endl;
    return 0;
}