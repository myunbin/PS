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
const int MAX = 222222+10; // PLZ CHK!

int n,q;
int p[MAX][21], d[MAX];
map<pii, int> cnt;
vector<int> g[MAX];

void dfs(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        p[nxt][0]=cur;
        d[nxt]=d[cur]+1;
        dfs(nxt,cur);
    }
}

void li() {
    for (int j=1; j<=20; j++) {
        for (int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v) {
    //d[v]>=d[u]
    if (d[u]>d[v]) swap(u,v);
    for (int i=20; i>=0; i--) if (d[p[v][i]]>=d[u]) v=p[v][i];
    if (u==v) return u;
    for (int i=20; i>=0; i--) if (p[v][i]!=p[u][i]) v=p[v][i], u=p[u][i];
    return p[v][0];    
}

void dfs2(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        dfs2(nxt, cur);
        pii ce={min(cur,p[cur][0]), max(cur,p[cur][0])};
        pii ne={min(nxt,p[nxt][0]), max(nxt,p[nxt][0])};
        cnt[ce]+=cnt[ne];
    }
}

int main() {
    fio();
    cin>>n>>q;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
        pii e={min(u,v), max(u,v)};
        cnt[e]=0;
    }

    d[1]=1;
    dfs(1,0);
    li();

    while (q--) {
        int u,v;
        cin>>u>>v;
        int l=lca(u,v);
        pii up={min(u, p[u][0]), max(u, p[u][0])};
        pii vp={min(v, p[v][0]), max(v, p[v][0])};
        pii lp={min(l, p[l][0]), max(l, p[l][0])};
        cnt[up]++, cnt[vp]++, cnt[lp]-=2;
    }

    dfs2(1,0);
    
    int ans=-1; 
    pii ap={INF,INF};
    for (auto [p, x]:cnt) {
        // cout<<p.F<<sp<<p.S<<sp<<x<<endl;
        if (ans<x) {
            ans=x;
            ap=p;
        }
        else if (ans==x) {
            ap=min(ap,p);
        }
    }

    cout<<ap.F<<sp<<ap.S<<sp<<ans;
    
    return 0;
}