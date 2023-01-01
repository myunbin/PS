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

int n,k,l;
vector<vector<int>> g1(MAX), g2(MAX);
vector<int> v1(MAX), v2(MAX);

void dfs(int cur, vector<vector<int>> &g, vector<int> &v, vector<int> &t) {
    v[cur]=1;
    t.pb(cur);
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        dfs(nxt, g, v, t);
    }
}

int main() {
    fio();
    cin>>n>>k>>l;

    for (int i=0; i<k; i++) {
        int u,v;
        cin>>u>>v;
        g1[u].pb(v), g1[v].pb(u);
    }    
    for (int i=0; i<l; i++) {
        int u,v;
        cin>>u>>v;
        g2[u].pb(v), g2[v].pb(u);
    }

    vector<vector<int>> c1,c2;
    for (int i=1; i<=n; i++) {
        if (!v1[i]) {
            vector<int> t;
            dfs(i, g1, v1, t);
            c1.pb(t);
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v2[i]) {
            vector<int> t;
            dfs(i, g2, v2, t);
            c2.pb(t);
        }
    }
    
    vector<pii> cmp(n+1);
    for (int i=0; i<sz(c1); i++) {
        for (int x:c1[i]) {
            cmp[x].F=i+1;
        }
    }
    for (int i=0; i<sz(c2); i++) {
        for (int x:c2[i]) {
            cmp[x].S=i+1;
        }
    }

    
    map<pii, vector<int>> cnt;
    vector<int> ans(n+1,0);
    for (int i=1; i<=n; i++) cnt[cmp[i]].pb(i);
    for (auto [uv,v]:cnt) {
        for (int x:v) {
            ans[x]=sz(v);
        }
    }
    for (int i=1; i<=n; i++) cout<<ans[i]<<sp;
    
    return 0;
}