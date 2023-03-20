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

ll n,m;
vector<vector<pll>> g1, g2;
vector<ll> c1(MAX), c2(MAX), d1(MAX), d2(MAX);

void dfs1(int cur, int prv, vector<vector<pll>> &g, vector<ll> &c, vector<ll> &d) {
    c[cur]=1;
    for (auto [nxt, cst]:g[cur]) {
        if (nxt==prv) continue;
        dfs1(nxt, cur, g, c, d);
        c[cur]+=c[nxt];
        d[cur]+=d[nxt]+cst*c[nxt];
    }
}

void dfs2(int cur, int prv, vector<vector<pll>> &g, vector<ll> &c, vector<ll> &ans) {
    for (auto [nxt, cst]:g[cur]) {
        if (nxt==prv) continue;
        ans[nxt]=ans[cur]+cst*(1ll*(sz(g)-1)-2*c[nxt]);
        dfs2(nxt, cur, g, c, ans);
    }
}

int main() {
    fio();

    cin>>n;
    g1.resize(n+1); 
    for (int i=0; i<n-1; i++) {
        int u,v; ll w;
        cin>>u>>v>>w;
        g1[u].pb({v,w}), g1[v].pb({u,w});
    }    
    dfs1(1,0,g1,c1,d1);

    cin>>m;
    g2.resize(m+1);
    for (int i=0; i<m-1; i++) {
        int u,v; ll w;
        cin>>u>>v>>w;
        g2[u].pb({v,w}), g2[v].pb({u,w});
    }
    dfs1(1,0,g2,c2,d2);

    vector<ll> ans1(MAX);
    ans1[1]=d1[1];
    dfs2(1,0,g1,c1,ans1);
    pll a1={LINF,0};
    for (int i=1; i<=n; i++) a1=min(a1, {ans1[i],i});

    vector<ll> ans2(MAX);
    ans2[1]=d2[1];
    dfs2(1,0,g2,c2,ans2);
    pll a2={LINF,0};
    for (int i=1; i<=m; i++) a2=min(a2, {ans2[i],i});

    cout<<a1.S<<sp<<a2.S<<endl;
    cout<<a1.F*m+n*m+a2.F*n;
    
    return 0;
}