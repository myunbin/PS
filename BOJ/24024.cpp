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

struct edge {int v; ll w; int p;};

int n,m;
ll x;
vector<edge> g[MAX];

ll djk(ll a) {
    vector<ll> d(n+1, LINF); d[1]=0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({d[1],1});

    while (!pq.empty()) {
        auto [dst, cur]=pq.top(); pq.pop();
        if (dst!=d[cur]) continue;
        for (auto [nxt, cst, col]:g[cur]) {
            if (col==1) cst+=a;
            if (col==2) cst+=(x-a);
            if (d[nxt]>d[cur]+cst) {
                d[nxt]=d[cur]+cst;
                pq.push({d[nxt], nxt});
            }
        }
    }

    return d[n];
}

int main() {
    fio();
    cin>>n>>m>>x;
    for (int i=0; i<m; i++) {
        int u,v; ll w; int p;
        cin>>u>>v>>w>>p;
        g[u].pb({v,w,p});
        g[v].pb({u,w,p});
    }
    
    ll l=0, r=x;
    while (r-l>=3) {
        ll p=(2*l+r)/3, q=(l+2*r)/3;
        if (djk(p)<=djk(q)) l=p;
        else r=q;
    }

    ll ans=-1;
    for (ll i=l; i<=r; i++) {
        ans=max(ans, djk(i));
    }
    cout<<ans;
    return 0;
}