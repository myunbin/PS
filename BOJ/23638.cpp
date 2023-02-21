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

int n;
vector<int> g[MAX];
int v[MAX], f[MAX], p[MAX];
pii cy;

void dfs(int cur, int prv) {
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        if (v[nxt]) {
            if (!f[nxt]) cy={cur, nxt};
            continue;
        }
        p[nxt]=cur;
        dfs(nxt, cur);
    }
    f[cur]=1;
}

vector<int> cyc;
void c(int cur, int lst) {
    cyc.pb(cur);
    if (cur==lst) return;
    c(p[cur], lst);
}

pii di(int cur, int prv, int dcr) {
    pii ret={dcr, cur};
    for (int nxt:g[cur]) {
        if (nxt==prv || v[nxt]) continue;
        ret=max(ret, di(nxt, cur, dcr+1));
    }
    return ret;
}

pii dia(int x) {
    pii d1=di(x,0,1);
    pii d2=di(d1.S,0,1);
    return {d2.F, d1.F-1}; // {지름, max 깊이}
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) {
        int u,v; 
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }    
    
    dfs(1,0);
    c(cy.F, cy.S);
    fill(v, v+MAX, 0);
    for (int x:cyc) v[x]=1;

    int ans=0, sz=sz(cyc);
    vector<int> a(sz);
    for (int i=0; i<sz; i++) {
        v[cyc[i]]=0;
        auto [dd, md]=dia(cyc[i]);
        a[i]=md;
        ans=max(ans, dd);
        v[cyc[i]]=1;
    }

    int t=a[0];
    for (int i=1; i<sz; i++) {
        ans=max(ans, a[i]+i+t);
        t=max(t, a[i]-i);
    }
    t=a[0];
    for (int i=1; i<sz; i++) {
        ans=max(ans, a[i]+sz-i+t);
        t=max(t, a[i]+i);
    }

    cout<<sz(cyc)<<sp<<ans;
    return 0;
}