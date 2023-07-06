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

struct ed {
    int u,v;
    ll w;
};

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    vector<pil> g[MAX];
    vector<ed> e(m);
    for (auto &[u,v,w]:e) {
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    for (int i=1; i<=n; i++) {
        sort(all(g[i]), [](pil a, pil b){
            return a.S>b.S;
        });
    }

    sort(all(e), [](ed a, ed b){
        return a.w>b.w;
    });

    ll ans=0;
    if (m>0) ans+=e[0].w;
    if (m>1) ans+=e[1].w;

    for (auto [u,v,w]:e) {
        vector<pil> eu, ev;
        for (auto [uu,ww]:g[u]) {
            if (uu==v) continue;
            eu.pb({uu,ww});
            if (sz(eu)==2) break;
        }
        for (auto [vv,ww]:g[v]) {
            if (vv==u) continue;
            ev.pb({vv,ww});
            if (sz(ev)==2) break;
        }

        if (eu.empty() || ev.empty()) continue;
        int su=sz(eu), sv=sz(ev);
        for (int i=0; i<su; i++) {
            for (int j=0; j<sv; j++) {
                if (eu[i].F==ev[j].F) continue;
                ll t=w+eu[i].S+ev[j].S;
                ans=max(ans, t);
            }
        }
    }

    cout<<ans;
    return 0;
}