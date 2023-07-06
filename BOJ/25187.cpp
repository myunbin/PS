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

int n,m,q;
int a[MAX], v[MAX];
vector<int> g[MAX];

pii dfs(int cur, vector<int> &c) {
    c.pb(cur);
    v[cur]=1;
    pii ret={1, a[cur]};
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        auto [f,s]=dfs(nxt, c);
        ret.F+=f, ret.S+=s;
    }
    return ret;
}

int main() {
    fio();
    cin>>n>>m>>q;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        g[x].pb(y), g[y].pb(x);
    }

    vector<int> ans(n+1);
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            vector<int> t;
            auto [sz, cnt]=dfs(i, t);
            if (cnt*2>sz) {
                for (int x:t) ans[x]=1;
            }
        }
    }

    while (q--) {
        int x; cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}