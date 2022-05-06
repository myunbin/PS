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

int n;
vector<int> v,s,p;
vector<vector<int>> g;
vector<pii> mm;
void dfs(int cur) {
    v[cur]=s[cur]=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        p[nxt]=cur;
        dfs(nxt);
        s[cur]+=s[nxt];
    }
}

void dfs2(int cur) {
    v[cur]=1;
    int mx=n-s[cur];
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        mx=max(mx,s[nxt]);
        dfs2(nxt);
    }
    if (mm.empty()||mx<mm[0].F) mm.clear(), mm.pb({mx,cur});
    else if (mx==mm[0].F) mm.pb({mx,cur});
}

int lf=0;
void dfs3(int cur, int ctr) {
    v[cur]=1;
    if (!lf && s[cur]==1) {
        lf=cur;
        cout<<cur<<sp<<p[cur]<<endl;
        return;
    }
    for (int nxt:g[cur]) {
        if (v[nxt]||nxt==ctr) continue;
        dfs3(nxt, ctr);
    }
}

void solve() {
    for (auto &x:g) x.clear();
    v.clear(), s.clear(), mm.clear(), p.clear(), lf=0;

    cin>>n;
    g.resize(n+1,vector<int>());
    v.resize(n+1,0), s.resize(n+1,0), p.resize(n+1,0);
    
    for (int i=0; i<n-1; i++) {
        int x,y; cin>>x>>y;
        g[x].pb(y), g[y].pb(x);
    }

    dfs(1);
    fill(all(v),0);
    dfs2(1);
    
    assert(sz(mm)<=2);

    if (sz(mm)==1) {
        cout<<2<<sp<<p[2]<<endl;
        cout<<2<<sp<<p[2]<<endl;
    }
    else {
        int x=mm[0].S, px=p[x];
        fill(all(v),0);
        dfs3(x,px);
        cout<<lf<<sp<<px<<endl;
    }
}
int main() {
    fio();
    int tc;
    cin>>tc;
    while (tc--) solve();
    return 0;
}