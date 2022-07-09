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

struct qq {
    int v,c,i;
};

int n,m,c;
vector<int> col[MAX], g[MAX];
int t[MAX], cnt=1; // t[i] = i의 방문순서 (가명)
int s[MAX]; // s[i] = i의 서브트리 사이즈

int dfs(int cur, int prv) {
    t[cur]=cnt++;
    s[cur]=1;
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        s[cur]+=dfs(nxt, cur);
    }
    return s[cur];
}

struct fwt {
    // 1-indexed!
    vector<ll> tr;
    void rst(int n) {tr.resize(n+1);}
    void upd(int i, ll v) {
        for (; i<sz(tr); i+=(i&-i)) tr[i]+=v;
    }
    ll qry(int r) { //[1,r]
        ll sum=0;
        for (; r; r-=(r&(-r))) sum+=tr[r];
        return sum;
    }
    ll qry(int l, int r) { //[l, r]
        if(l==0) return qry(r);
        return qry(r)-qry(l-1);
    }
};


int main() {
    fio();
    cin>>n>>m>>c;
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        col[x].pb(i);
    }

    for (int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    vector<qq> q(m);
    for (int i=0; i<m; i++) {
        auto &[x,y,z]=q[i];
        cin>>x>>y; z=i;
    }
    sort(all(q),[](qq a, qq b) {
        return a.c<b.c;
    });

    dfs(1,0);
    
    ll ans=0;
    fwt fw; fw.rst(MAX);

    int cc=1;
    for (int i=0; i<m; i++) {
        auto [x,y,z]=q[i];
        while (cc<=y) {
            for (int u:col[cc]) fw.upd(t[u], 1);
            cc++;
        }
        ans=(ans+fw.qry(t[x], t[x]+s[x]-1))%MOD;
    }
    cout<<ans;
    return 0;
}