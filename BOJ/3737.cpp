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

int cnt,ans;
vector<vector<int>> g;
vector<pii> st;
vector<int> dn, dm;

void dfs(int cur, int prv) {
    dn[cur]=dm[cur]=cnt++;
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;

        if (dn[cur]>dn[nxt]) st.pb({cur, nxt});

        if (dn[nxt]) dm[cur]=min(dm[cur], dn[nxt]);
        else {
            dfs(nxt, cur);
            dm[cur]=min(dm[cur], dm[nxt]);
            if (dn[cur]<=dm[nxt]) {
                set<int> nd;
                int bc=0;
                while (1) {
                    pii e=st.back(); st.pop_back();
                    nd.insert(e.F), nd.insert(e.S);
                    bc++;
                    if (e==pii(cur,nxt)) break;
                }
                if (bc==sz(nd)) ans=max(ans, sz(nd));
            }
        }
    }
}

void init() {
    ans=0, cnt=1;
    for (int i=0; i<sz(g); i++) g[i].clear();
    dn.clear(), dm.clear(), st.clear();
}

void solve() {
    init();

    int n,m;
    cin>>n>>m;

    g.resize(n+1), dn.resize(n+1), dm.resize(n+1);
    for (int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    dfs(1,0);

    cout<<ans<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}