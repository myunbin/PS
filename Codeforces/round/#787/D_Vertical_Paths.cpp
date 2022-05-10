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

vector<vector<int>> g;
vector<int> d,m;

void dfs1(int cur) {
    for (int nxt:g[cur]) {
        d[nxt]=d[cur]+1;
        dfs1(nxt);
    }
}

void dfs3(int cur) {
    m[cur]=d[cur];
    for (int nxt:g[cur]) {
        dfs3(nxt);
        m[cur]=max(m[cur], m[nxt]);
    }
}

void dfs2(int cur, vector<int> &ta, vector<vector<int>> &ans) {
    pii mx={0,0};
    ta.pb(cur);

    if (g[cur].empty()) {
        ans.pb(ta);
        return;
    }

    for (int nxt:g[cur]) {
        mx=max(mx, {m[nxt],nxt});
    }    
    
    dfs2(mx.S, ta, ans);
    
    for (int nxt:g[cur]) {
        if (nxt==mx.S) continue;
        vector<int> t;
        dfs2(nxt, t, ans);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> ans;
    g.resize(n+1);
    d.resize(n+1,0);
    m.resize(n+1,0);

    int rt;
    for (int i=1; i<=n; i++) {
        int p; cin>>p;
        if (i==p) rt=p;
        else g[p].pb(i);
    }

    dfs1(rt);
    dfs3(rt);

    vector<int> tt;
    dfs2(rt, tt, ans);

    cout<<sz(ans)<<endl;
    for (auto v:ans) {
        if (sz(v)==0) continue;
        cout<<sz(v)<<endl;
        for (int x:v) cout<<x<<sp;
        cout<<endl;
    }

    cout<<endl;

    for (int i=0; i<=n; i++) g[i].clear();
    d.clear(), m.clear();
}
int main() {
    fio();
    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}